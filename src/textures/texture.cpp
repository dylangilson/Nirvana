/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * December 3, 2023
 */

#include "./textures/texture.hpp"

Texture::Texture() {
    glGenTextures(1, &id);
}

Texture::~Texture() {
    destroy();
}

void Texture::set_parameters() {
    // set wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // set filtering paramters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

// NOTE: texture file must be 2^N in size in both width and height
void Texture::load_data(std::string file_path) {
    unsigned char *data = stbi_load(file_path.c_str(), &width, &height, &number_of_channels, 0);

    if (!data) {
        std::cout << "Failed to load texture: " << file_path << std::endl;
    }

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(data);
}

void Texture::bind_to_unit(unsigned int unit) {
    glActiveTexture(GL_TEXTURE0 + unit);
    bind();
}

unsigned int Texture::get_id() {
    return id;
}

void Texture::bind() {
    glBindTexture(GL_TEXTURE_2D, id);
}

void Texture::unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::destroy() {
    glDeleteTextures(1, &id);
}
