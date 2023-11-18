/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * November 8, 2023
 */

#pragma once

#include "shader_program.hpp"

class StaticShader : public ShaderProgram {
    public:
        static std::string VERTEX_SHADER_FILE;
        static std::string FRAGMENT_SHADER_FILE;

        StaticShader();
        ~StaticShader();
};
