#version 330 core

layout (location = 0) in vec3 in_position;
layout (location = 1) in vec2 in_texture_coordinates;

out vec2 pass_texture_coordinates;

uniform mat4 transformation_matrix;
uniform mat4 projection_matrix;
uniform mat4 view_matrix;

void main(void) {
    gl_Position = projection_matrix * view_matrix * transformation_matrix * vec4(in_position, 1.0);
    pass_texture_coordinates = in_texture_coordinates;
}
