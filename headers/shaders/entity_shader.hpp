/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * November 8, 2023
 */

#pragma once

#include "shader_program.hpp"
#include "./mathematics/camera_algebra.hpp"
#include "./uniforms/uniform_matrix4f.hpp"
#include "./uniforms/uniform_vector3f.hpp"
#include "./uniforms/uniform_float.hpp"
#include "./entities/camera.hpp"
#include "./entities/light.hpp"

class EntityShader : public ShaderProgram {
    public:
        static std::string VERTEX_SHADER_FILE;
        static std::string FRAGMENT_SHADER_FILE;

        EntityShader();
        ~EntityShader();
        void bind_attributes();
        void load_transformation_matrix(Matrix4f matrix);
        void load_projection_matrix(Matrix4f matrix);
        void load_view_matrix(Camera camera);
        void load_light(Light light);
        void load_specular_lighting(float shine_damper_value, float reflectivity_value);
        void load_transparency(float transparency_value);
        void load_fake_lighting(float fake_lighting_value);
        void load_sky_colour(Vector3f colour);

    protected:
        UniformMatrix4f *transformation_matrix;
        UniformMatrix4f *projection_matrix;
        UniformMatrix4f *view_matrix;
        UniformVector3f *light_position;
        UniformVector3f *light_colour;
        UniformFloat *shine_damper;
        UniformFloat *reflectivity;
        UniformFloat *transparency;
        UniformFloat *use_fake_lighting;
        UniformVector3f *sky_colour;
};
