#version 330 core

in vec2 pass_texture_coordinates;

out vec4 out_colour;

uniform sampler2D texture_sampler;

void main(void) {
    out_colour = texture(texture_sampler, pass_texture_coordinates);
}
