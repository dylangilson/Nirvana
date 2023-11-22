/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * November 8, 2023
 */

#include "./shaders/static_shader.hpp"

std::string StaticShader::VERTEX_SHADER_FILE = "./shaders/vertex_shader.glsl";
std::string StaticShader::FRAGMENT_SHADER_FILE = "./shaders/fragment_shader.glsl";

StaticShader::StaticShader() : ShaderProgram(VERTEX_SHADER_FILE, FRAGMENT_SHADER_FILE) {
    
}

StaticShader::~StaticShader() {
    
}

void ShaderProgram::bind_attributes() {
    bind_attribute(0, "in_position"); // 0 -> position
}
