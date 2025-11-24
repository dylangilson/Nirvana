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
#include "./model_data.hpp"
#include "./vertex.hpp"

class OBJLoader {
    public:
        static ModelData load_obj_model(const std::string &filename);

    private:
        static void process_vertex(const std::vector<std::string> &vertex_data, std::vector<std::unique_ptr<Vertex>> &vertices, std::vector<unsigned int> &indices);
        static void deal_with_already_processed_vertex(Vertex &previous_vertex, int new_texture_index, int new_normal_index, std::vector<std::unique_ptr<Vertex>> &vertices, std::vector<unsigned int> &indices);
        static void remove_unused_vertices(std::vector<std::unique_ptr<Vertex>> &vertices);
};
