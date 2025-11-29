/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * February 2, 2023
 */

#include "./terrain/terrain.hpp"

Terrain::Terrain(int x_length, int z_length, Loader loader, TerrainTexturePack *texture_pack, TerrainTexture *blend_map) {
    this->texture_pack = texture_pack;
    this->blend_map = blend_map;
    this->x = x_length * SIZE;
    this->z = z_length * SIZE;
    this->model = generate_terrain(loader);
}

Terrain::~Terrain() {
    delete model;
    delete texture_pack;
    delete blend_map;
}

RawModel *Terrain::generate_terrain(Loader loader) {
    int count = VERTEX_COUNT * VERTEX_COUNT;
    size_t index = 0;
    std::vector<float> vertices(count * 3);
    std::vector<unsigned int> indices((VERTEX_COUNT - 1) * (VERTEX_COUNT - 1) * 6);
    std::vector<float> normals(count * 3);
    std::vector<float> texture_coordinates(count * 2);
    
    for (size_t i = 0; i < VERTEX_COUNT; i++) {
        for (size_t j = 0; j < VERTEX_COUNT; j++) {
            vertices.at(index * 3) = (float)j / ((float)VERTEX_COUNT - 1) * SIZE;
            vertices.at(index * 3 + 1) = 0;
            vertices.at(index * 3 + 2) = (float)i / ((float)VERTEX_COUNT - 1) * SIZE;

            normals.at(index * 3) = 0;
            normals.at(index * 3 + 1) = 1;
            normals.at(index * 3 + 2) = 0;

            texture_coordinates.at(index * 2) = (float)j / ((float)VERTEX_COUNT - 1);
            texture_coordinates.at(index * 2 + 1) = (float)i / ((float)VERTEX_COUNT - 1);

            index++;
        }
    }

    index = 0;

    for (unsigned int generator_z = 0; generator_z < VERTEX_COUNT - 1; generator_z++) {
        for (unsigned int generator_x = 0; generator_x < VERTEX_COUNT - 1; generator_x++) {
            unsigned int top_left = generator_z * VERTEX_COUNT + generator_x;
            unsigned int top_right = top_left + 1;
            unsigned int bottom_left = (generator_z + 1) * VERTEX_COUNT + generator_x;
            unsigned int bottom_right = bottom_left + 1;

            indices.at(index++) = top_left;
            indices.at(index++) = bottom_left;
            indices.at(index++) = top_right;
            indices.at(index++) = top_right;
            indices.at(index++) = bottom_left;
            indices.at(index++) = bottom_right;
        }
    }

    return loader.load_raw_model(vertices, indices, normals, texture_coordinates);
}

RawModel *Terrain::get_model() {
    return model;
}

TerrainTexturePack *Terrain::get_texture_pack() {
    return texture_pack;
}

TerrainTexture *Terrain::get_blend_map() {
    return blend_map;
}

float Terrain::get_x() {
    return x;
}

float Terrain::get_z() {
    return z;
}
