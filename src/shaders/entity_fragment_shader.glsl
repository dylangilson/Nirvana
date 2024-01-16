#version 330 core

in vec2 out_texture_coordinates;
in vec3 out_surface_normal;
in vec3 out_to_light_vector;

out vec4 out_colour;

uniform sampler2D texture_sampler;
uniform vec3 light_colour;

void main(void) {
    vec3 unit_normal = normalize(out_surface_normal);
    vec3 unit_light_vector = normalize(out_to_light_vector);

    float normal_dot_light = dot(unit_normal, unit_light_vector);
    float brightness = max(normal_dot_light, 0.0);
    vec3 diffuse_lighting = brightness * light_colour;

    out_colour = vec4(diffuse_lighting, 1.0) * texture(texture_sampler, out_texture_coordinates);
}
