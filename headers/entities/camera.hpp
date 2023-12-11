/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * December 10, 2023
 */

#pragma once

#include "./engine/glad.hpp"
#include <GLFW/glfw3.h>

#include "./render_engine/display.hpp"
#include "./mathematics/linear_algebra.hpp"

class Camera {
    public:
        Camera();
        Vector3f get_position();
        float get_pitch();
        float get_yaw();
        float get_roll();
        void move();

    private:
        Vector3f position;
        float pitch;
        float yaw;
        float roll;
};
