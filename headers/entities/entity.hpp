/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * December 9, 2023
 */

#pragma once

#include "./mathematics/linear_algebra.hpp"
#include "./models/textured_model.hpp"

class Entity {
    public:
        Entity(TexturedModel *model, Vector3f position, Vector3f rotation, Vector3f outline_colour, float scale);
        ~Entity();
        TexturedModel *get_model();
        Vector3f get_position();
        void set_position(Vector3f value);
        void increase_position(Vector3f value);
        Vector3f get_rotation();
        void set_rotation(Vector3f value);
        void increase_rotation(Vector3f value);
        Vector3f get_outline_colour();
        void set_outline_colour(Vector3f value);
        float get_scale();
        void set_scale(float value);

    private:
        TexturedModel *model;
        Vector3f position;
        Vector3f rotation;
        Vector3f outline_colour;
        float scale;
};
