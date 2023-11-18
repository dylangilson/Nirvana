/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * October 29, 2023
 */

/*** Compilation & Running ***/
// make
// ./nirvana

#include <iostream>

#include <GL/glew.h>
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

    // initialize GLFW
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        glfwTerminate();
        return EXIT_FAILURE;
    }

    Display display;
    Loader loader;
    Renderer renderer;
    StaticShader shader;

    float vertices[] = {
	    -0.5f, 0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.5f, 0.5f, 0.0f	
	};

    int indices[] = {
        0, 1, 3,
        3, 1, 2
    };

    RawModel *model = loader.load_to_vao(vertices, indices, sizeof(vertices) / sizeof(vertices[0]), sizeof(indices) / sizeof(indices[0]));

    // game loop
    while (!glfwWindowShouldClose(Display::window)) {
        // render
        renderer.prepare();
        shader.start();
        renderer.render(model);
        shader.stop();
        Display::update_display();
    }

    // clean up
    delete model;

    glfwTerminate();

    return 0;
}
