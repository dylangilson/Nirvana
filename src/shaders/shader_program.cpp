/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * November 8, 2023
 */

#include "./shaders/shader_program.hpp"

ShaderProgram::ShaderProgram(std::string vertex_shader_file, std::string fragment_shader_file) {
    program_id = glCreateProgram();
    vertex_shader_id = load_shader(vertex_shader_file, GL_VERTEX_SHADER);
    fragment_shader_id = load_shader(fragment_shader_file, GL_FRAGMENT_SHADER);

    glAttachShader(program_id, vertex_shader_id);
    glAttachShader(program_id, fragment_shader_id);

    bind_attributes();

    glLinkProgram(program_id);
    glValidateProgram(program_id);

    glDeleteShader(vertex_shader_id);
    glDeleteShader(fragment_shader_id);
}

ShaderProgram::~ShaderProgram() {
    destroy();
}

void ShaderProgram::bind_attributes() {

}

void ShaderProgram::start() {
    glUseProgram(program_id);
}

void ShaderProgram::stop() {
    glUseProgram(0); // 0 -> stop program
}

void ShaderProgram::bind_attribute(int attribute_id, std::string variable_name) {
    glBindAttribLocation(program_id, attribute_id, variable_name.c_str());
}

void ShaderProgram::store_all_uniform_locations(std::vector<Uniform *> uniforms) {
    for (size_t i = 0; i < uniforms.size(); i++) {
        uniforms.at(i)->store_uniform_location(program_id);
    }

    glValidateProgram(program_id);
}

int ShaderProgram::load_shader(std::string filename, unsigned int type) {
    std::string shader_source;
    std::string current_line;
    std::string filepath = "./shaders/" + filename + ".glsl";
    std::ifstream file(filepath);

    if (!file) {
        std::cout << "Failed to load shader: " << filename << std::endl;
    }

    while (getline(file, current_line)) {
        shader_source += current_line + "\n";
    }

    file.close();

    int shader_id = glCreateShader(type);
    const char *source = shader_source.c_str();
    glShaderSource(shader_id, 1, &source, NULL);
    glCompileShader(shader_id);
    int success;
    char info_log[512];

    glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(shader_id, 512, NULL, info_log);
        std::cout << "Could not compile shader: " << filename << std::endl << info_log << std::endl; 
        exit(EXIT_FAILURE);
    }

    return shader_id;
}

void ShaderProgram::destroy() {
    stop();

    glDetachShader(program_id, vertex_shader_id);
    glDetachShader(program_id, fragment_shader_id);
    
    glDeleteProgram(program_id);
}
