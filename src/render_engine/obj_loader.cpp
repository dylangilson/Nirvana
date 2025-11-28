/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * January 14, 2024
 */

#include "./render_engine/obj_loader.hpp"

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

            vertices.push_back(std::make_unique<Vertex>((int)vertices.size(), Vector3f(x, y, z)));
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
        auto duplicate = std::make_unique<Vertex>((int)vertices.size(), previous_vertex.get_position());
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
