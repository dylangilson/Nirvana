/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * October 29, 2023
 */

/*** Compilation & Running ***/
// make
// ./nirvana

#include <iostream>
#include <vector>

#include "./engine/glad.hpp"
#include <GLFW/glfw3.h>

#include "./mathematics/random_number_generator.hpp"
#include "./render_engine/display.hpp"
#include "./render_engine/loader.hpp"
#include "./models/raw_model.hpp"
#include "./render_engine/renderer.hpp"
#include "./shaders/entity_shader.hpp"
#include "./textures/model_texture.hpp"
#include "./models/textured_model.hpp"

int main(int argc, char *argv[]) {
    // hide warnings from main arguments
    (void)argc;
    (void)argv;

    Display display;
    RandomNumberGenerator random_number_generator;
    Loader loader;
    Renderer renderer;
    EntityShader *shader = new EntityShader();

    std::vector<float> vertices = {
        -0.5f, 0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.5f, 0.5f, 0.0f
    };

    std::vector<int> indices = {
        0, 1, 3,
        3, 1, 2
    };

    std::vector<float> texture_coordinates = {
        0.0f, 0.0f,
        0.0f, 1.0f,
        1.0f, 1.0f,
        1.0f, 0.0f
    };


    RawModel *model = loader.load_raw_model(vertices, indices, texture_coordinates);
    ModelTexture *texture = new ModelTexture(loader.load_texture("OSRS LOGO"));
    TexturedModel *textured_model = new TexturedModel(model, texture);
    
    // game loop
    while (!glfwWindowShouldClose(Display::window)) {
        // render
        renderer.prepare();
        shader->start();
        renderer.render(textured_model);
        shader->stop();
        Display::update_display();
    }

    // clean up
    delete textured_model;
    delete shader;
    
    glfwTerminate();

    return EXIT_SUCCESS;
}
