/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * November 8, 2023
 */

#pragma once

#include "shader_program.hpp"
#include "./mathematics/camera_algebra.hpp"
#include "./uniforms/uniform_matrix4f.hpp"
#include "./entities/camera.hpp"

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

    protected:
        UniformMatrix4f *transformation_matrix;
        UniformMatrix4f *projection_matrix;
        UniformMatrix4f *view_matrix;
};
