/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * December 9, 2023
 */

#include "./entities/entity.hpp"

Entity::Entity(TexturedModel *model, Vector3f position, Vector3f rotation, float scale) {
    this->model = model;
    this->position = position;
    this->rotation = rotation;
    this->scale = scale;
}

Entity::~Entity() {
    
}

TexturedModel *Entity::get_model() {
    return model;
}

Vector3f Entity::get_position() {
    return position;
}

void Entity::set_position(Vector3f value) {
    position = value;
}

void Entity::increase_position(Vector3f value) {
    position.x += value.x;
    position.y += value.y;
    position.z += value.z;
}

Vector3f Entity::get_rotation() {
    return rotation;
}

void Entity::set_rotation(Vector3f value) {
    rotation = value;
}

void Entity::increase_rotation(Vector3f value) {
    rotation.x += value.x;
    rotation.y += value.y;
    rotation.z += value.z;
}

float Entity::get_scale() {
    return scale;
}

void Entity::set_scale(float value) {
    scale = value;
}
