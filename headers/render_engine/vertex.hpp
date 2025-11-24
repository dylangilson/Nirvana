/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * Novmeber 24, 2025
 */

#pragma once

#include <memory>

#include "./mathematics/linear_algebra.hpp"

class Vertex {
    public:
        static constexpr int NO_INDEX = -1;

        Vertex(int index, const Vector3f &position);
        int get_index() const;
        float get_length() const;
        bool is_set() const;
        bool has_same_texture_and_normal(int texture_index_other, int normal_index_other) const;
        void set_texture_index(int texture_index);
        void set_normal_index(int normal_index);
        void set_duplicate_vertex(Vertex *duplicate_vertex);
        const Vector3f &get_position() const;
        int get_texture_index() const;
        int get_normal_index() const;
        Vertex *get_duplicate_vertex() const;
        
    private:
        Vector3f position;
        int texture_index = NO_INDEX;
        int normal_index = NO_INDEX;
        Vertex *duplicate_vertex = nullptr;
        int index;
        float length;
};
