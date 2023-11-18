/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * November 8, 2023
 */

#pragma once

#include <fstream>
#include <iostream>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class ShaderProgram {
    public:
        ShaderProgram(std::string vertex_shader_file, std::string fragment_shader_file);
        virtual ~ShaderProgram();
        void start();
        void stop();
        virtual void bind_attributes();

    protected:
        void bind_attribute(int attribute_id, std::string variable_name);

    private:
        unsigned int program_id;
        unsigned int vertex_shader_id;
        unsigned int fragment_shader_id;

        static int load_shader(std::string file_name, unsigned int type);
};
