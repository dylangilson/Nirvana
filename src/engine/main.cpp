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
#include "./render_engine/master_renderer.hpp"
#include "./textures/model_texture.hpp"
#include "./models/textured_model.hpp"
#include "./entities/camera.hpp"
#include "./entities/light.hpp"
#include "./terrain/terrain.hpp"

int main(int argc, char *argv[]) {
    // hide warnings from main arguments
    (void)argc;
    (void)argv;

    Display display;
    RandomNumberGenerator random_number_generator;
    Loader loader;
    OBJLoader obj_loader;
    MasterRenderer *master_renderer = new MasterRenderer();

    RawModel *model = obj_loader.load_obj_model(loader, "Dragon");

    ModelTexture *texture = new ModelTexture(loader.load_texture("OSRS LOGO"));
    texture->set_shine_damper(10.0f);
    texture->set_reflectivity(1.0f);
    TexturedModel *textured_model = new TexturedModel(model, texture);

    std::vector<Entity *> entities;
    Entity *entity = new Entity(textured_model, Vector3f(0.0f, 5.0f, -30.0f), Vector3f(0.0f, 0.0f, 0.0f), Vector3f(0.0f, 1.0f, 1.0f), 1.0f);
    entities.push_back(entity);

    Light sun(Vector3f(0.0f, 0.0f, -20.0f), Vector3f(1.0f, 1.0f, 1.0f));

    std::vector<Terrain *> terrains;
    Terrain *terrain = new Terrain(0, -1, loader, new ModelTexture(loader.load_texture("Lava")));
    Terrain *terrain2 = new Terrain(-1, -1, loader, new ModelTexture(loader.load_texture("Lava")));
    terrains.push_back(terrain);
    terrains.push_back(terrain2);

    Camera camera;
    
    // game loop
    while (!glfwWindowShouldClose(Display::window)) {
        camera.move();

        // render phase
        for (size_t i = 0; i < entities.size(); i++) {
            entities.at(i)->increase_rotation(Vector3f(0.0f, 1.0f, 0.0f));
            master_renderer->process_entity(entities.at(i));
        }

        for (size_t i = 0; i < terrains.size(); i++) {
            master_renderer->process_terrain(terrains.at(i));
        }

        master_renderer->render(sun, camera);

        // end of frame
        display.update_display();
    }

    // clean up
    for (size_t i = 0; i < entities.size(); i++) {
        delete entities.at(i);
    }
    delete textured_model;
    delete master_renderer;
    
    glfwTerminate();

    return EXIT_SUCCESS;
}
