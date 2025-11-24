/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * January 14, 2024
 */

#include "./render_engine/obj_loader.hpp"

// RawModel* OBJLoader::load_obj_model(Loader loader, std::string filename) {
//     std::string current_line;
//     std::string filepath = "../res/models/" + filename + ".obj";
//     std::ifstream file(filepath);

//     if (!file) {
//         std::cout << "Failed to load file: " << filename << std::endl;
//         return NULL;
//     }

//     std::vector<Vector3f> vertices;
//     std::vector<Vector2f> texture_coordinates;
//     std::vector<Vector3f> normals;
//     std::vector<float> vertex_floats;
//     std::vector<int> indices;
//     std::vector<float> normal_floats;
//     std::vector<float> textures;

//     while (getline(file, current_line)) {
//         std::stringstream string_stream(current_line);
//         std::istream_iterator<std::string> begin(string_stream);
//         std::istream_iterator<std::string> end;
//         std::vector<std::string> words(begin, end);

//         if (current_line.substr(0, 2) == "v ") {
//             Vector3f vertex(std::stof(words[1]), std::stof(words[2]), std::stof(words[3]));
//             vertices.push_back(vertex);
//         } else if (current_line.substr(0, 2) == "vt") {
//             Vector2f texture_coordinate(std::stof(words[1]), std::stof(words[2]));
//             texture_coordinates.push_back(texture_coordinate);
//         } else if (current_line.substr(0, 2) == "vn") {
//             Vector3f normal(std::stof(words[1]), std::stof(words[2]), std::stof(words[3]));
//             normals.push_back(normal);
//         } else if (current_line.substr(0, 2) == "f ") {
//             textures = std::vector<float>(vertices.size() * 2);
//             normal_floats = std::vector<float>(vertices.size() * 3);
//             break;
//         }
//     }

//     while (!current_line.empty()) {
//         int vertex_a_x;
//         int vertex_a_y;
//         int vertex_a_z;
//         int vertex_b_x;
//         int vertex_b_y;
//         int vertex_b_z;
//         int vertex_c_x;
//         int vertex_c_y;
//         int vertex_c_z;

//         const char *str = current_line.c_str();
//         sscanf(str, "f %i/%i/%i %i/%i/%i %i/%i/%i", &vertex_a_x, &vertex_a_y, &vertex_a_z, &vertex_b_x, &vertex_b_y, &vertex_b_z, &vertex_c_x, &vertex_c_y, &vertex_c_z);
        
//         vertex_a_x--;
//         vertex_a_y--;
//         vertex_a_z--;
//         vertex_b_x--;
//         vertex_b_y--;
//         vertex_b_z--;
//         vertex_c_x--;
//         vertex_c_y--;
//         vertex_c_z--;

//         // process vertex 1
//         int current_vertex_pointer = vertex_a_x;
//         indices.push_back(current_vertex_pointer);

//         Vector2f current_texture = texture_coordinates.at(vertex_a_y);
//         textures.at(current_vertex_pointer * 2) = current_texture.x;
//         textures.at(current_vertex_pointer * 2 + 1) = 1.0f - current_texture.y;

//         Vector3f current_normal = normals.at(vertex_a_z);
//         normal_floats.at(current_vertex_pointer * 3) = current_normal.x;
//         normal_floats.at(current_vertex_pointer * 3 + 1) = current_normal.y;
//         normal_floats.at(current_vertex_pointer * 3 + 2) = current_normal.z;

//         // process vertex 2
//         current_vertex_pointer = vertex_b_x;
//         indices.push_back(current_vertex_pointer);

//         current_texture = texture_coordinates.at(vertex_b_y);
//         textures.at(current_vertex_pointer * 2) = current_texture.x;
//         textures.at(current_vertex_pointer * 2 + 1) = 1 - current_texture.y;

//         current_normal = normals.at(vertex_b_z);
//         normal_floats.at(current_vertex_pointer * 3) = current_normal.x;
//         normal_floats.at(current_vertex_pointer * 3 + 1) = current_normal.y;
//         normal_floats.at(current_vertex_pointer * 3 + 2) = current_normal.z;

//         // process vertex 3
//         current_vertex_pointer = vertex_c_x;
//         indices.push_back(current_vertex_pointer);

//         current_texture = texture_coordinates.at(vertex_c_y);
//         textures.at(current_vertex_pointer * 2) = current_texture.x;
//         textures.at(current_vertex_pointer * 2 + 1) = 1 - current_texture.y;

//         current_normal = normals.at(vertex_c_z);
//         normal_floats.at(current_vertex_pointer * 3) = current_normal.x;
//         normal_floats.at(current_vertex_pointer * 3 + 1) = current_normal.y;
//         normal_floats.at(current_vertex_pointer * 3 + 2) = current_normal.z;

//         getline(file, current_line);
//     }

//     file.close();

//     for (size_t i = 0; i < vertices.size(); i++) {
//         Vector3f vertex = vertices.at(i);
//         vertex_floats.push_back(vertex.x);
//         vertex_floats.push_back(vertex.y);
//         vertex_floats.push_back(vertex.z);
//     }

//     return loader.load_raw_model(vertex_floats, indices, normal_floats, textures);
// }

ModelData OBJLoader::load_obj_model(const std::string &filename) {
    std::ifstream file("../res/models/" + filename + ".obj");

    if (!file.is_open()) {
        std::cerr << "File not found in res: " << filename << "\n";

        return ModelData({}, {}, {}, {}, 0.0f);
    }

    std::vector<std::unique_ptr<Vertex>> vertices;
    std::vector<Vector2f> textures;
    std::vector<Vector3f> normals;
    std::vector<unsigned int> indices;

    std::string line;

    while (std::getline(file, line)) {
        if (line.substr(0, 2) == "v ") {
            std::istringstream iss(line.substr(2));

            float x, y, z;
            
            iss >> x >> y >> z;

            vertices.push_back(std::make_unique<Vertex>(vertices.size(), Vector3f(x, y, z)));
        } else if (line.substr(0, 3) == "vt ") {
            std::istringstream iss(line.substr(3));

            float u, v;
            
            iss >> u >> v;

            textures.emplace_back(u, v);
        } else if (line.substr(0, 3) == "vn ") {
            std::istringstream iss(line.substr(3));

            float x, y, z;
            
            iss >> x >> y >> z;

            normals.emplace_back(x, y, z);
        } else if (line.substr(0, 2) == "f ") {
            break;
        }
    }

    file.clear();
    file.seekg(0);

    while (std::getline(file, line)) {
        if (line.substr(0, 2) != "f ") {
            continue;
        }

        std::istringstream iss(line.substr(2));
        std::string v1, v2, v3;

        iss >> v1 >> v2 >> v3;

        auto split_vertex = [](const std::string &str) -> std::vector<std::string> {
            std::vector<std::string> result;
            std::string token;
            std::istringstream s(str);

            while (std::getline(s, token, '/')) {
                result.push_back(token);
            }

            return result;
        };

        process_vertex(split_vertex(v1), vertices, indices);
        process_vertex(split_vertex(v2), vertices, indices);
        process_vertex(split_vertex(v3), vertices, indices);
    }

    remove_unused_vertices(vertices);

    std::vector<float> vertices_vector;
    std::vector<float> textures_vector;
    std::vector<float> normals_vector;

    float furthest_point = 0.0f;

    for (const auto &vertex_ptr : vertices) {
        const Vertex &vertex = *vertex_ptr;
        const Vector3f &position = vertex.get_position();

        vertices_vector.push_back(position.x);
        vertices_vector.push_back(position.y);
        vertices_vector.push_back(position.z);

        if (vertex.get_length() > furthest_point) {
            furthest_point = vertex.get_length();
        }

        const Vector2f &texture = textures[vertex.get_texture_index()];

        textures_vector.push_back(texture.x);
        textures_vector.push_back(1.0f - texture.y);

        const Vector3f &normal = normals[vertex.get_normal_index()];

        normals_vector.push_back(normal.x);
        normals_vector.push_back(normal.y);
        normals_vector.push_back(normal.z);
    }

    return ModelData(vertices_vector, textures_vector, normals_vector, indices, furthest_point);
}

void OBJLoader::process_vertex(const std::vector<std::string>& vertex_data, std::vector<std::unique_ptr<Vertex>>& vertices, std::vector<unsigned int>& indices) {
    int index = std::stoi(vertex_data[0]) - 1;
    int texture_index = std::stoi(vertex_data[1]) - 1;
    int normal_index = std::stoi(vertex_data[2]) - 1;

    Vertex *current_vertex = vertices[index].get();

    if (!current_vertex->is_set()) {
        current_vertex->set_texture_index(texture_index);
        current_vertex->set_normal_index(normal_index);
        indices.push_back(index);
    } else {
        deal_with_already_processed_vertex(*current_vertex, texture_index, normal_index, vertices, indices);
    }
}

void OBJLoader::deal_with_already_processed_vertex(Vertex &previous_vertex, int new_texture_index, int new_normal_index, std::vector<std::unique_ptr<Vertex>>& vertices, std::vector<unsigned int>& indices) {
    if (previous_vertex.has_same_texture_and_normal(new_texture_index, new_normal_index)) {
        indices.push_back(previous_vertex.get_index());
    } else if (previous_vertex.get_duplicate_vertex() != nullptr) {
        deal_with_already_processed_vertex(*previous_vertex.get_duplicate_vertex(), new_texture_index, new_normal_index, vertices, indices);
    } else {
        auto duplicate = std::make_unique<Vertex>(vertices.size(), previous_vertex.get_position());
        duplicate->set_texture_index(new_texture_index);
        duplicate->set_normal_index(new_normal_index);

        Vertex *duplicate_ptr = duplicate.get();

        previous_vertex.set_duplicate_vertex(duplicate_ptr);

        vertices.push_back(std::move(duplicate));

        indices.push_back(duplicate_ptr->get_index());
    }
}

void OBJLoader::remove_unused_vertices(std::vector<std::unique_ptr<Vertex>>& vertices) {
    for (auto &vertex_ptr : vertices) {
        Vertex &vertex = *vertex_ptr;

        if (!vertex.is_set()) {
            vertex.set_texture_index(0);
            vertex.set_normal_index(0);
        }
    }
}
