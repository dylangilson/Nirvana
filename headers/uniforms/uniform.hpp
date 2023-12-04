/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * December 3, 2023
 */

#pragma once

#include "./engine/glad.hpp"

#include <string>

class Uniform {
    public:
        Uniform(std::string name);
        virtual void store_uniform_location(unsigned int program_id);

    protected:
        unsigned int get_location();

    private:
        std::string name;
        unsigned int location;
};
