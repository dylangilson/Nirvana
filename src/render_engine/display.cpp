/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * October 29, 2023
 */

#include "./render_engine/display.hpp"

const GLFWvidmode *Display::mode = NULL;
GLFWwindow *Display::window = NULL;
GLFWmonitor **Display::monitors = NULL;
int Display::frame_count = 0;
double Display::last_frame_time = 0;
float Display::delta_time = 0.0f;
int Display::count_monitors = 0;
int Display::monitor_x = 0;
int Display::monitor_y = 0;
int Display::monitor_width = 0;
int Display::monitor_height = 0;
bool Display::is_fullscreen = false;

Display::Display() {
    // initialize GLFW
    if (!glfwInit()) {
        std::cout << "Failed to initialize GLFW" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_SAMPLES, 4); // 4x anti-aliasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // OpenGL version 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    Display::window = glfwCreateWindow(Display::WIDTH, Display::HEIGHT, "Nirvana", NULL, NULL);

    if (Display::window == NULL) {
        std::cout << "Failed to open GLFW window" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(Display::window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    Display::monitors = glfwGetMonitors(&Display::count_monitors);
    Display::mode = glfwGetVideoMode(Display::monitors[0]);
    Display::monitor_width = int(Display::mode->width / 1.5);
    Display::monitor_height = int((Display::mode->height / 16) * 9);

    glfwGetMonitorPos(Display::monitors[0], &Display::monitor_x, &Display::monitor_y);
    glfwSetWindowPos(Display::window, Display::monitor_x + (Display::mode->width - Display::monitor_width) / 2, Display::monitor_y + (Display::mode->height - Display::monitor_height) / 2);

    glViewport(0, 0, Display::WIDTH, Display::HEIGHT);
    glfwSetInputMode(Display::window, GLFW_STICKY_KEYS, GL_TRUE); // allow for key captures

    Display::last_frame_time = glfwGetTime();
}

float Display::get_frame_time_in_seconds() {
    return Display::delta_time;
}

void Display::update_display() {
    switch_screen_mode();

    double current_frame_time = glfwGetTime();
    Display::frame_count++;
    Display::delta_time = (float)(current_frame_time - Display::last_frame_time) / 1000.0f; // delta_time stores time in seconds

    if (current_frame_time - Display::last_frame_time >= 1.0) {
        std::cout << "FPS: " << Display::frame_count << std::endl;

        Display::frame_count = 0;
        Display::last_frame_time = current_frame_time;
    }

    glfwSwapBuffers(Display::window);
    glfwPollEvents();
    glfwSwapInterval(1);
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
