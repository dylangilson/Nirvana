/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * October 29, 2023
 */

#pragma once

#include <iostream>

#include "./engine/glad.hpp"
#include <GLFW/glfw3.h>

class Display {
    public:
        static const int WIDTH = 1280;
        static const int HEIGHT = 720;
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
        static float get_frame_time_in_seconds();
        void update_display();
        void switch_screen_mode();
};
