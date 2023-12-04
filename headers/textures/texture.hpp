/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * December 3, 2023
 */

#pragma once

#include "./engine/glad.hpp"
#include "./engine/stb_image.hpp"

#include <iostream>
#include <string>
#include <utility>

class Texture {
    public:
        Texture();
        ~Texture();

        Texture(const Texture&) = delete; // delete copy constructor
        Texture(Texture &&other) : id(other.id), height(other.height), width(other.width), number_of_channels(other.number_of_channels) {
            other.id = 0;
            other.height = 0;
            other.width = 0;
            other.number_of_channels = 0; 
        }

        Texture &operator=(const Texture&) = delete; // delete copy-assignment
        Texture &operator=(Texture &&other) {
            if (this != &other) {
                destroy();

                std::swap(id, other.id);
                std::swap(height, other.height);
                std::swap(width, other.width);
                std::swap(number_of_channels, other.number_of_channels);
            }

            return *this;
        }

        unsigned int get_id();
        void bind();
        void unbind();
        void set_parameters();
        void load_data(std::string file_path);
        void bind_to_unit(unsigned int unit);

    private:
        unsigned int id = 0;
        int height = 0;
        int width = 0;
        int number_of_channels = 0;

        void destroy();
};
