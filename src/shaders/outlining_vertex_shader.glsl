#version 330 core

layout (location = 0) in vec3 in_position;
layout (location = 1) in vec3 in_normal;

uniform mat4 transformation_matrix;
uniform mat4 projection_matrix;
uniform mat4 view_matrix;

void main(void) {
    vec4 world_position = transformation_matrix * vec4(in_position + in_normal * 0.08, 1.0);

    gl_Position = projection_matrix * view_matrix * world_position;
}
