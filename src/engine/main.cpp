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
#include "./render_engine/obj_loader.hpp"
#include "./models/raw_model.hpp"
#include "./render_engine/renderer.hpp"
#include "./textures/model_texture.hpp"
#include "./models/textured_model.hpp"
#include "./entities/camera.hpp"
#include "./entities/light.hpp"

int main(int argc, char *argv[]) {
    // hide warnings from main arguments
    (void)argc;
    (void)argv;

    Display display;
    RandomNumberGenerator random_number_generator;
    Loader loader;
    OBJLoader obj_loader;
    Renderer *renderer = new Renderer();

    RawModel *model = obj_loader.load_obj_model(loader, "dragon");
    ModelTexture *texture = new ModelTexture(loader.load_texture("OSRS LOGO"));
    TexturedModel *textured_model = new TexturedModel(model, texture);
    Entity *entity = new Entity(textured_model, Vector3f(0.0f, 0.0f, -30.0f), Vector3f(0.0f, 0.0f, 0.0f), 1.0f);
    Light light(Vector3f(0.0f, 0.0f, -20.0f), Vector3f(1.0f, 1.0f, 1.0f));
    Camera camera;
    
    // game loop
    while (!glfwWindowShouldClose(Display::window)) {
        // render
        entity->increase_rotation(Vector3f(0.0f, 0.1f, 0.0f));
        camera.move();
        renderer->prepare();
        renderer->get_shader()->start();
        renderer->get_shader()->load_light(light);
        renderer->get_shader()->load_view_matrix(camera);
        renderer->render(entity);
        renderer->get_shader()->stop();
        display.update_display();
    }

    // clean up
    delete entity;
    delete renderer;
    
    glfwTerminate();

    return EXIT_SUCCESS;
}
