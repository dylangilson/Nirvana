/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * January 14, 2024
 */

#include "./render_engine/obj_loader.hpp"

RawModel* OBJLoader::load_obj_model(Loader loader, std::string filename) {
    std::string current_line;
    std::string filepath = "../res/models/" + filename + ".obj";
    std::ifstream file(filepath);

    if (!file) {
        std::cout << "Failed to load file: " << filename << std::endl;
        return NULL;
    }

    std::vector<Vector3f> vertices;
    std::vector<Vector2f> texture_coordinates;
    std::vector<Vector3f> normals;
    std::vector<float> vertex_floats;
    std::vector<int> indices;
    std::vector<float> normal_floats;
    std::vector<float> textures;

    while (getline(file, current_line)) {
        std::stringstream string_stream(current_line);
        std::istream_iterator<std::string> begin(string_stream);
        std::istream_iterator<std::string> end;
        std::vector<std::string> words(begin, end);

        if (current_line.substr(0, 2) == "v ") {
            Vector3f vertex(std::stof(words[1]), std::stof(words[2]), std::stof(words[3]));
            vertices.push_back(vertex);
        } else if (current_line.substr(0, 2) == "vt") {
            Vector2f texture_coordinate(std::stof(words[1]), std::stof(words[2]));
            texture_coordinates.push_back(texture_coordinate);
        } else if (current_line.substr(0, 2) == "vn") {
            Vector3f normal(std::stof(words[1]), std::stof(words[2]), std::stof(words[3]));
            normals.push_back(normal);
        } else if (current_line.substr(0, 2) == "f ") {
            textures = std::vector<float>(vertices.size() * 2);
            normal_floats = std::vector<float>(vertices.size() * 3);
            break;
        }
    }

    while (!current_line.empty()) {
        int vertex_a_x;
        int vertex_a_y;
        int vertex_a_z;
        int vertex_b_x;
        int vertex_b_y;
        int vertex_b_z;
        int vertex_c_x;
        int vertex_c_y;
        int vertex_c_z;

        const char *str = current_line.c_str();
        sscanf(str, "f %i/%i/%i %i/%i/%i %i/%i/%i", &vertex_a_x, &vertex_a_y, &vertex_a_z, &vertex_b_x, &vertex_b_y, &vertex_b_z, &vertex_c_x, &vertex_c_y, &vertex_c_z);
        
        vertex_a_x--;
        vertex_a_y--;
        vertex_a_z--;
        vertex_b_x--;
        vertex_b_y--;
        vertex_b_z--;
        vertex_c_x--;
        vertex_c_y--;
        vertex_c_z--;

        // process vertex 1
        int current_vertex_pointer = vertex_a_x;
        indices.push_back(current_vertex_pointer);

        Vector2f current_texture = texture_coordinates.at(vertex_a_y);
        textures.at(current_vertex_pointer * 2) = current_texture.x;
        textures.at(current_vertex_pointer * 2 + 1) = 1.0f - current_texture.y;

        Vector3f current_normal = normals.at(vertex_a_z);
        normal_floats.at(current_vertex_pointer * 3) = current_normal.x;
        normal_floats.at(current_vertex_pointer * 3 + 1) = current_normal.y;
        normal_floats.at(current_vertex_pointer * 3 + 2) = current_normal.z;

        // process vertex 2
        current_vertex_pointer = vertex_b_x;
        indices.push_back(current_vertex_pointer);

        current_texture = texture_coordinates.at(vertex_b_y);
        textures.at(current_vertex_pointer * 2) = current_texture.x;
        textures.at(current_vertex_pointer * 2 + 1) = 1 - current_texture.y;

        current_normal = normals.at(vertex_b_z);
        normal_floats.at(current_vertex_pointer * 3) = current_normal.x;
        normal_floats.at(current_vertex_pointer * 3 + 1) = current_normal.y;
        normal_floats.at(current_vertex_pointer * 3 + 2) = current_normal.z;

        // process vertex 3
        current_vertex_pointer = vertex_c_x;
        indices.push_back(current_vertex_pointer);

        current_texture = texture_coordinates.at(vertex_c_y);
        textures.at(current_vertex_pointer * 2) = current_texture.x;
        textures.at(current_vertex_pointer * 2 + 1) = 1 - current_texture.y;

        current_normal = normals.at(vertex_c_z);
        normal_floats.at(current_vertex_pointer * 3) = current_normal.x;
        normal_floats.at(current_vertex_pointer * 3 + 1) = current_normal.y;
        normal_floats.at(current_vertex_pointer * 3 + 2) = current_normal.z;

        getline(file, current_line);
    }

    file.close();

    for (size_t i = 0; i < vertices.size(); i++) {
        Vector3f vertex = vertices.at(i);
        vertex_floats.push_back(vertex.x);
        vertex_floats.push_back(vertex.y);
        vertex_floats.push_back(vertex.z);
    }

    return loader.load_raw_model(vertex_floats, indices, normal_floats, textures);
}
