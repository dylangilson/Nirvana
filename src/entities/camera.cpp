/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * December 10, 2023
 */

#include "./entities/camera.hpp"

Camera::Camera() {
    position = Vector3f(0.0f, 5.0f, 0.0f);
    pitch = 0.0f;
    yaw = 0.0f;
    roll = 0.0f;
}

Vector3f Camera::get_position() {
    return position;
}

float Camera::get_pitch() {
    return pitch;
}

float Camera::get_yaw() {
    return yaw;
}

float Camera::get_roll() {
    return roll;
}

void Camera::move() {
    if (glfwGetKey(Display::window, GLFW_KEY_W) == GLFW_PRESS) {
        position.z -= 0.02f;
    }
    if (glfwGetKey(Display::window, GLFW_KEY_A) == GLFW_PRESS) {
        position.x -= 0.02f;
    }
    if (glfwGetKey(Display::window, GLFW_KEY_S) == GLFW_PRESS) {
        position.z += 0.02f;
    }
    if (glfwGetKey(Display::window, GLFW_KEY_D) == GLFW_PRESS) {
        position.x += 0.02f;
    }
}

