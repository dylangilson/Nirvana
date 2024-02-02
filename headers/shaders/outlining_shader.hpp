/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * November 8, 2023
 */

#pragma once

#include "./entities/camera.hpp"
#include "./mathematics/camera_algebra.hpp"
#include "./shaders/shader_program.hpp"
#include "./uniforms/uniform_matrix4f.hpp"
#include "./uniforms/uniform_vector3f.hpp"

class OutliningShader : public ShaderProgram {
    public:
        static std::string VERTEX_SHADER_FILE;
        static std::string FRAGMENT_SHADER_FILE;

        OutliningShader();
        ~OutliningShader();
        void bind_attributes();
        void load_transformation_matrix(Matrix4f matrix);
        void load_projection_matrix(Matrix4f matrix);
        void load_view_matrix(Camera camera);
        void load_outline_colour(Vector3f colour);

    protected:
        UniformMatrix4f *transformation_matrix;
        UniformMatrix4f *projection_matrix;
        UniformMatrix4f *view_matrix;
        UniformVector3f *outline_colour;
};
