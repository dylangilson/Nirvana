/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * October 29, 2023
 */

#include "display.hpp"

int Display::frame_count = 0;
long Display::last_frame_time = 0;
float Display::delta_time = 0.0f;
int Display::count_monitors = 0;
int Display::monitor_x = 0;
int Display::monitor_y = 0;
int Display::monitor_width = 0;
int Display::monitor_height = 0;
bool Display::is_fullscreen = false;
const GLFWvidmode *Display::mode = NULL;
GLFWwindow *Display::window = NULL;
GLFWmonitor **Display::monitors = NULL;

Display::Display() {
    glfwWindowHint(GLFW_SAMPLES, 4); // 4x anti-aliasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // OpenGL version 3.2
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    Display::window = glfwCreateWindow(Display::WIDTH, Display::HEIGHT, "Nirvana", NULL, NULL);

    if (Display::window == NULL) {
        std::cerr << "Failed to open GLFW window" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(Display::window); // initialize GLEW
    glewExperimental = true; // needed in core profile

    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    Display::monitors = glfwGetMonitors(&Display::count_monitors);
    Display::mode = glfwGetVideoMode(Display::monitors[0]);
    Display::monitor_width = Display::mode->width / 1.5;
    Display::monitor_height = Display::mode->height / 16 * 9;

    glfwGetMonitorPos(Display::monitors[0], &Display::monitor_x, &Display::monitor_y);
    glfwSetWindowPos(Display::window, Display::monitor_x + (Display::mode->width - Display::monitor_width) / 2, Display::monitor_y + (Display::mode->height - Display::monitor_height) / 2);

    glViewport(0, 0, Display::WIDTH, Display::HEIGHT);
    glfwSetInputMode(Display::window, GLFW_STICKY_KEYS, GL_TRUE); // allow for key captures

    Display::last_frame_time = glfwGetTime();
}

void Display::update_display() {
    switch_screen_mode();

    long current_frame_time = glfwGetTime();
    Display::frame_count++;
    Display::delta_time = (current_frame_time - Display::last_frame_time) / 1000.0f; // delta_time stores time in seconds

    if (current_frame_time - Display::last_frame_time >= 1.0) {
        std::cout << "FPS " << Display::frame_count << std::endl;

        Display::frame_count = 0;
        Display::last_frame_time = current_frame_time;
    }

    glfwSwapBuffers(Display::window);
    glfwPollEvents();
}

float Display::get_frame_time_in_seconds() {
    return Display::delta_time;
}

void Display::switch_screen_mode() {
    if (glfwGetKey(Display::window, GLFW_KEY_F12) == GLFW_PRESS && !Display::is_fullscreen) {
        glfwSetWindowMonitor(Display::window, Display::monitors[0], 0, 0, Display::mode->width, Display::mode->height, Display::mode->refreshRate); // set window size to fullscreen

        Display::is_fullscreen = true;
    } else if (glfwGetKey(Display::window, GLFW_KEY_ESCAPE) == GLFW_PRESS && Display::is_fullscreen) {
        glfwSetWindowMonitor(Display::window, NULL, 0, 0, Display::WIDTH, Display::HEIGHT, 0); // set window size to WIDTH x HEIGHT
        glfwSetWindowPos(Display::window, Display::monitor_x + (Display::mode->width - Display::monitor_width) / 2, Display::monitor_y + (Display::mode->height - Display::monitor_height) / 2); // position window in center of primary monitor

        Display::is_fullscreen = false;
    }
}
