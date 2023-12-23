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

        ShaderProgram(const ShaderProgram&) = delete; // delete copy constructor
        ShaderProgram(ShaderProgram &&other) : program_id(other.program_id), vertex_shader_id(other.vertex_shader_id), fragment_shader_id(other.fragment_shader_id) {
            other.program_id = 0;
            other.vertex_shader_id = 0;
            other.fragment_shader_id = 0;
        }

        ShaderProgram &operator=(const ShaderProgram&) = delete; // delete copy-assignment
        ShaderProgram &operator=(ShaderProgram &&other) {
            if (this != &other) {
                destroy();

                std::swap(program_id, other.program_id);
                std::swap(vertex_shader_id, other.vertex_shader_id);
                std::swap(fragment_shader_id, other.fragment_shader_id);
            }

            return *this;
        }

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
        void destroy();
};
