/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * November 8, 2023
 */

#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "./engine/glad.hpp"
#include <GLFW/glfw3.h>

#include "./uniforms/uniform.hpp"

class ShaderProgram {
    public:
        ShaderProgram(std::string vertex_shader_file, std::string fragment_shader_file);
        virtual ~ShaderProgram();
        virtual void bind_attributes();
        void start();
        void stop();

    protected:
        void bind_attribute(int attribute_id, std::string variable_name);
        void store_all_uniform_locations(std::vector<Uniform *> uniforms);

    private:
        unsigned int program_id;
        unsigned int vertex_shader_id;
        unsigned int fragment_shader_id;

        static int load_shader(std::string file_name, unsigned int type);
};
