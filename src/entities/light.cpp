/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * January 15, 2024
 */

#include "./entities/light.hpp"

Light::Light(Vector3f position, Vector3f colour) {
    this->position = position;
    this->colour = colour;
}

Vector3f Light::get_position() {
    return position;
}

void Light::set_position(Vector3f position) {
    this->position = position;
}

Vector3f Light::get_colour() {
    return colour;
}

void Light::set_colour(Vector3f colour) {
    this->colour = colour;
}
