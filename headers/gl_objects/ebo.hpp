/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * Novmeber 21, 2023
 */

#pragma once

#include <utility>
#include <vector>

#include "./engine/glad.hpp"

class EBO {
    public:
        EBO();
        ~EBO();

        EBO(const EBO&) = delete; // delete copy constructor
        EBO(EBO &&other) : id(other.id) {
            other.id = 0;
        }

        EBO &operator=(const EBO&) = delete; // delete copy-assignment
        EBO &operator=(EBO &&other) {
            if (this != &other) {
                destroy();

                std::swap(id, other.id);
            }

            return *this;
        }
        
        unsigned int get_id();
        void bind();
        void unbind();
        void store_data(std::vector<unsigned int> data);

    private:
        unsigned int id = 0;

        void destroy();
};
