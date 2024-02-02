#version 330 core

out vec4 out_colour;

uniform vec3 outline_colour;

void main(void) {
    out_colour = vec4(outline_colour, 1.0);
}
