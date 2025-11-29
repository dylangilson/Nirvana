#version 330 core

in vec2 out_texture_coordinates;
in vec3 out_surface_normal;
in vec3 out_to_light_vector;
in vec3 out_to_camera_vector;
in float out_visibility;

out vec4 out_colour;

uniform sampler2D background_texture; // black on blend map -> draw this texture
uniform sampler2D red_texture; // red on blend map -> draw this texture
uniform sampler2D green_texture; // green on blend map -> draw this texture
uniform sampler2D blue_texture; // blue on blend map -> draw this texture
uniform sampler2D blend_map;
uniform vec3 light_colour;
uniform float shine_damper;
uniform float reflectivity;
uniform vec3 sky_colour;

const float TILE_SIZE = 40.0;

void main(void) {
    vec4 blend_map_colour = texture(blend_map, out_texture_coordinates);

    float background_texture_amount = 1.0 - (blend_map_colour.r + blend_map_colour.g + blend_map_colour.b);
    vec2 tiled_coordinates = out_texture_coordinates * TILE_SIZE;

    vec4 background_texture_colour = texture(background_texture, tiled_coordinates) * background_texture_amount;
    vec4 red_texture_colour = texture(red_texture, tiled_coordinates) * blend_map_colour.r;
    vec4 green_texture_colour = texture(green_texture, tiled_coordinates) * blend_map_colour.g;
    vec4 blue_texture_colour = texture(blue_texture, tiled_coordinates) * blend_map_colour.b;

    vec4 total_colour = background_texture_colour + red_texture_colour + green_texture_colour + blue_texture_colour;

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
    vec3 specular_lighting = shine_damping_factor * reflectivity * light_colour;

    out_colour = vec4(diffuse_lighting, 1.0) * total_colour + vec4(specular_lighting, 1.0);
    out_colour = mix(vec4(sky_colour, 1.0), out_colour, out_visibility);
}
