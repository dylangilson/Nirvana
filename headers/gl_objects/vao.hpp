/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * Novmeber 3, 2023
 */

#pragma once

#include <utility>
#include <vector>

#include "ebo.hpp"
#include "vbo.hpp"

class VAO {
    public:
        VAO();
        ~VAO();

        VAO(const VAO&) = delete; // delete copy constructor
        VAO(VAO &&other) : vbos(other.vbos), id(other.id), ebo(other.ebo) {
            other.vbos = std::vector<VBO *>();
            other.id = 0;
            other.ebo = NULL;
        }

        VAO &operator=(const VAO&) = delete; // delete copy-assignment
        VAO &operator=(VAO &&other) {
            if (this != &other) {
                destroy();

                vbos.swap(other.vbos);
                std::swap(id, other.id);
                std::swap(ebo, other.ebo);
            }

            return *this;
        }

        unsigned int get_id();
        EBO *get_ebo();
        void bind(std::vector<int> attributes);
        void unbind(std::vector<int> attributes);
        void create_ebo(std::vector<int> indices);
        void create_attribute(unsigned int attribute_id, size_t attribute_size, std::vector<float> data);
        void create_attribute(unsigned int attribute_id, size_t attribute_size, std::vector<int> data);

    private:
        std::vector<VBO *> vbos;
        unsigned int id = 0;
        EBO *ebo;

        void bind();
        void unbind();
        void destroy();
};
