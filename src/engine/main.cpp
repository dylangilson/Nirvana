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

#include "./render_engine/display.hpp"
#include "./render_engine/loader.hpp"
#include "./models/raw_model.hpp"
#include "./render_engine/renderer.hpp"
#include "./shaders/static_shader.hpp"
#include "./mathematics/random_number_generator.hpp"

int main(int argc, char *argv[]) {
    // hide warnings from main arguments
    (void)argc;
    (void)argv;

    Display display;
    Loader loader;
    Renderer renderer;
    StaticShader *shader = new StaticShader();

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

    RawModel *model = loader.load_raw_model(vertices, indices);

    RandomNumberGenerator random_number_generator;
    
    // game loop
    while (!glfwWindowShouldClose(Display::window)) {
        // render
        renderer.prepare();
        shader->start();
        renderer.render(model);
        shader->stop();
        Display::update_display();
    }

    // clean up
    delete shader;
    delete model;
    
    glfwTerminate();

    return EXIT_SUCCESS;
}
