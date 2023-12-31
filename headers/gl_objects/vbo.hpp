/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * Novmeber 3, 2023
 */

#pragma once

#include <utility>
#include <vector>

#include "./engine/glad.hpp"

class VBO {
    public:
        VBO();
        ~VBO();

        VBO(const VBO&) = delete; // delete copy constructor
        VBO(VBO &&other) : id(other.id) {
            other.id = 0;
        }

        VBO &operator=(const VBO&) = delete; // delete copy-assignment
        VBO &operator=(VBO &&other) {
            if (this != &other) {
                destroy();

                std::swap(id, other.id);
            }

            return *this;
        }

        unsigned int get_id();
        void bind();
        void unbind();
        void store_data(std::vector<float> data);
        void store_data(std::vector<int> data);

    private:
        unsigned int id = 0;

        void destroy();
};
