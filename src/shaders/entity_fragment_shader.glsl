#version 330 core

in vec2 out_texture_coordinates;
in vec3 out_surface_normal;
in vec3 out_to_light_vector;
in vec3 out_to_camera_vector;

out vec4 out_colour;

uniform sampler2D texture_sampler;
uniform vec3 light_colour;
uniform float shine_damper;
uniform float reflectivity;

void main(void) {
    vec3 unit_normal = normalize(out_surface_normal);
    vec3 unit_light_vector = normalize(out_to_light_vector);

    // diffuse lighting
    float normal_dot_light = dot(unit_normal, unit_light_vector);
    float brightness = max(normal_dot_light, 0.2); // this also adds ambient lighting due to non-zero minimum value
    vec3 diffuse_lighting = brightness * light_colour;

    // specular lighting
    vec3 unit_camera_vector = normalize(out_to_camera_vector);
    vec3 light_direction = -unit_light_vector;
    vec3 reflected_light_direction = reflect(light_direction, unit_normal);
    float specular_lighting_factor = max(dot(reflected_light_direction, unit_camera_vector), 0.0);
    float shine_damping_factor = pow(specular_lighting_factor, shine_damper);
    vec3 specular_lighting = shine_damping_factor * light_colour;

    out_colour = vec4(diffuse_lighting, 1.0) * texture(texture_sampler, out_texture_coordinates) + vec4(specular_lighting, 1.0);
}
