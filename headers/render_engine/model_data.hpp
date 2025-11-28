/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * Novmeber 24, 2025
 */

#pragma once

#include <vector>

class ModelData {
    public:
        ModelData(const std::vector<float> &vertices, const std::vector<float> &texture_coordinates, const std::vector<float> &normals, const std::vector<unsigned int> &indices, float furthest_point);
        ~ModelData();
        const std::vector<float> &get_vertices() const;
        const std::vector<float> &get_texture_coordinates() const;
        const std::vector<float> &get_normals() const;
        const std::vector<unsigned int> &get_indices() const;
        float get_furthest_point() const;

    private:
        std::vector<float> vertices;
        std::vector<float> texture_coordinates;
        std::vector<float> normals;
        std::vector<unsigned int> indices;
        float furthest_point;
};
