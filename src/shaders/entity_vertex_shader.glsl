#version 330 core

layout (location = 0) in vec3 in_position;
layout (location = 1) in vec3 in_normal;
layout (location = 2) in vec2 in_texture_coordinates;

out vec2 out_texture_coordinates;
out vec3 out_surface_normal;
out vec3 out_to_light_vector;
out vec3 out_to_camera_vector;

uniform mat4 transformation_matrix;
uniform mat4 projection_matrix;
uniform mat4 view_matrix;
uniform vec3 light_position;
uniform float use_fake_lighting;

void main(void) {
    vec4 world_position = transformation_matrix * vec4(in_position, 1.0);

    gl_Position = projection_matrix * view_matrix * world_position;

    vec3 actual_normal = in_normal;
    if (use_fake_lighting > 0.5) {
        actual_normal = vec3(0.0, 1.0, 0.0);
    }

    out_texture_coordinates = in_texture_coordinates;
    out_surface_normal = (transformation_matrix * vec4(actual_normal, 0.0)).xyz;
    out_to_light_vector = light_position - world_position.xyz;
    out_to_camera_vector = (inverse(view_matrix) * vec4(0.0, 0.0, 0.0, 1.0)).xyz - world_position.xyz;
}
