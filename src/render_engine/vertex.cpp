/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * Novmeber 24, 2025
 */

#include "./render_engine/vertex.hpp"

Vertex::Vertex(int index, const Vector3f &position) : position(position), index(index), length(position.length()) {}

int Vertex::get_index() const {
    return index;
}

float Vertex::get_length() const {
    return length;
}

bool Vertex::is_set() const {
    return texture_index != NO_INDEX && normal_index != NO_INDEX;
}

bool Vertex::has_same_texture_and_normal(int texture_index_other, int normal_index_other) const {
    return texture_index_other == texture_index && normal_index_other == normal_index;
}

void Vertex::set_texture_index(int texture_index) {
    this->texture_index = texture_index;
}

void Vertex::set_normal_index(int normal_index) {
    this->normal_index = normal_index;
}

void Vertex::set_duplicate_vertex(Vertex *duplicate_vertex) {
    this->duplicate_vertex = duplicate_vertex;
}

const Vector3f &Vertex::get_position() const {
    return position;
}

int Vertex::get_texture_index() const {
    return texture_index;
}

int Vertex::get_normal_index() const {
    return normal_index;
}

Vertex *Vertex::get_duplicate_vertex() const {
    return duplicate_vertex;
}
