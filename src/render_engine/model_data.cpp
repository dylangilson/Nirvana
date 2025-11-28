/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * Novmeber 24, 2025
 */

#include "./render_engine/model_data.hpp"

ModelData::ModelData(const std::vector<float> &vertices, const std::vector<float> &texture_coordinates, const std::vector<float> &normals, const std::vector<unsigned int> &indices, float furthest_point) :
    vertices(vertices), texture_coordinates(texture_coordinates), normals(normals), indices(indices), furthest_point(furthest_point) {

}

ModelData::~ModelData() {
    
}

const std::vector<float> &ModelData::get_vertices() const {
    return vertices;
}

const std::vector<float> &ModelData::get_texture_coordinates() const {
    return texture_coordinates;
}

const std::vector<float> &ModelData::get_normals() const {
    return normals;
}

const std::vector<unsigned int> &ModelData::get_indices() const {
    return indices;
}

float ModelData::get_furthest_point() const {
    return furthest_point;
}
