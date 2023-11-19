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

#include "glad.h"
#include <GLFW/glfw3.h>

#include "display.hpp"
#include "loader.hpp"
#include "raw_model.hpp"
#include "renderer.hpp"
#include "static_shader.hpp"

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

    RawModel *model = loader.load_to_vao(vertices, indices);

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
