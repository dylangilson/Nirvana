/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * January 14, 2024
 */

#pragma once

#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

#include "./mathematics/linear_algebra.hpp"
#include "./models/raw_model.hpp"
#include "./render_engine/loader.hpp"

class OBJLoader {
    public:
        static RawModel* load_obj_model(Loader loader, std::string filename);
};
