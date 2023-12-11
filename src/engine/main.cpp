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
#include "./entities/camera.hpp"

int main(int argc, char *argv[]) {
    // hide warnings from main arguments
    (void)argc;
    (void)argv;

    Display display;
    RandomNumberGenerator random_number_generator;
    Loader loader;
    EntityShader *shader = new EntityShader();
    Renderer *renderer = new Renderer(shader);
    
    std::vector<float> vertices = {
        -0.5f, 0.5f, -0.5f,	
        -0.5f, -0.5f, -0.5f,	
        0.5f, -0.5f, -0.5f,	
        0.5f, 0.5f, -0.5f,		
        
        -0.5f, 0.5f, 0.5f,	
        -0.5f, -0.5f, 0.5f,	
        0.5f, -0.5f, 0.5f,	
        0.5f, 0.5f, 0.5f,
        
        0.5f, 0.5f, -0.5f,	
        0.5f, -0.5f, -0.5f,	
        0.5f, -0.5f, 0.5f,	
        0.5f, 0.5f, 0.5f,
        
        -0.5f, 0.5f, -0.5f,	
        -0.5f, -0.5f, -0.5f,	
        -0.5f, -0.5f, 0.5f,	
        -0.5f, 0.5f, 0.5f,
        
        -0.5f, 0.5f, 0.5f,
        -0.5f, 0.5f, -0.5f,
        0.5f, 0.5f, -0.5f,
        0.5f, 0.5f, 0.5f,
        
        -0.5f, -0.5f, 0.5f,
        -0.5f, -0.5f, -0.5f,
        0.5f, -0.5f, -0.5f,
        0.5f, -0.5f, 0.5f
    };

    std::vector<int> indices = {
        0, 1, 3,	
        3, 1, 2,	
        4, 5, 7,
        7, 5, 6,
        8, 9, 11,
        11, 9, 10,
        12, 13, 15,
        15, 13, 14,	
        16, 17, 19,
        19, 17, 18,
        20, 21, 23,
        23, 21, 22
    };

    std::vector<float> texture_coordinates = {
        0.0f, 0.0f,
        0.0f, 1.0f,
        1.0f, 1.0f,
        1.0f, 0.0f,			
        0.0f, 0.0f,
        0.0f, 1.0f,
        1.0f, 1.0f,
        1.0f, 0.0f,			
        0.0f, 0.0f,
        0.0f, 1.0f,
        1.0f, 1.0f,
        1.0f, 0.0f,
        0.0f, 0.0f,
        0.0f, 1.0f,
        1.0f, 1.0f,
        1.0f, 0.0f,
        0.0f, 0.0f,
        0.0f, 1.0f,
        1.0f, 1.0f,
        1.0f, 0.0f,
        0.0f, 0.0f,
        0.0f, 1.0f,
        1.0f, 1.0f,
        1.0f, 0.0f
    };


    RawModel *model = loader.load_raw_model(vertices, indices, texture_coordinates);
    ModelTexture *texture = new ModelTexture(loader.load_texture("OSRS LOGO"));
    TexturedModel *textured_model = new TexturedModel(model, texture);
    Entity *entity = new Entity(textured_model, Vector3f(0.0f, 0.0f, -5.0f), Vector3f(0.0f, 0.0f, 0.0f), 1.0f);
    Camera camera;
    
    // game loop
    while (!glfwWindowShouldClose(Display::window)) {
        // render
        entity->increase_rotation(Vector3f(0.1f, 0.1f, 0.0f));
        camera.move();
        renderer->prepare();
        shader->start();
        shader->load_view_matrix(camera);
        renderer->render(entity, shader);
        shader->stop();
        display.update_display();
    }

    // clean up
    delete entity;
    delete renderer;
    delete shader;
    
    glfwTerminate();

    return EXIT_SUCCESS;
}
