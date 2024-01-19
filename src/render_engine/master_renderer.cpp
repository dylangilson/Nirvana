/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * Novmeber 3, 2023
 */

#include "./render_engine/master_renderer.hpp"

MasterRenderer::MasterRenderer() {
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    create_projection_matrix();

    this->entity_renderer = new EntityRenderer(projection_matrix);
}

MasterRenderer::~MasterRenderer() {
    delete entity_renderer;
}

EntityRenderer *MasterRenderer::get_entity_renderer() {
    return entity_renderer;
}

void MasterRenderer::prepare() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void MasterRenderer::render(Light sun, Camera camera) {
    prepare();

    entity_renderer->get_shader()->start();

    entity_renderer->get_shader()->load_light(sun);
    entity_renderer->get_shader()->load_view_matrix(camera);

    entity_renderer->render(entities);

    entity_renderer->get_shader()->stop();

    entities.clear();
}

void MasterRenderer::process_entity(Entity *entity) {
    TexturedModel *textured_model = entity->get_model();

    if (entities.find(textured_model) == entities.end()) {
        std::vector<Entity *> batch;
        batch.push_back(entity);
        entities[textured_model] = batch;

        return;
    }

    std::vector<Entity *> *batch = &entities.find(textured_model)->second;
    batch->push_back(entity);
}

void MasterRenderer::create_projection_matrix() {
    float aspect_ratio = (float)Display::WIDTH / (float)Display::HEIGHT;
    float y_scale = (1.0f / tan(FOV * PI / 180.0f / 2.0f)) * aspect_ratio;
    float x_scale = y_scale / aspect_ratio;
    float frustrum_length = FAR_PLANE - NEAR_PLANE;

    projection_matrix = ZERO_MATRIX;
    projection_matrix.m[0] = x_scale;
    projection_matrix.m[5] = y_scale;
    projection_matrix.m[10] = -((FAR_PLANE + NEAR_PLANE) / frustrum_length);
    projection_matrix.m[11] = -1.0f;
    projection_matrix.m[14] = -((2.0f * NEAR_PLANE * FAR_PLANE) / frustrum_length);
}
