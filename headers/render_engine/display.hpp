/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * October 29, 2023
 */

#pragma once

#include <iostream>
#include <stdlib.h>

#include "./engine/glad.hpp"
#include <GLFW/glfw3.h>

class Display {
    public:
        static const int WIDTH = 1280;
        static const int HEIGHT = 720;
        static const int MAX_FPS = 120;
        static GLFWwindow *window;
        static GLFWmonitor **monitors;
        static const GLFWvidmode *mode;
        static int frame_count;
        static long last_frame_time; // time of last frame in milliseconds
        static float delta_time;
        static int count_monitors;
        static int monitor_x;
        static int monitor_y;
        static int monitor_width;
        static int monitor_height;
        static bool is_fullscreen;

        Display();
        static void update_display();
        static float get_frame_time_in_seconds();
        static void switch_screen_mode();
};
