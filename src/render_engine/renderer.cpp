/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * Novmeber 3, 2023
 */

#include "./render_engine/renderer.hpp"

void Renderer::prepare() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::render(TexturedModel *textured_model) {
    RawModel *model = textured_model->get_raw_model();
    model->get_vao()->bind(std::vector<int>());

    glEnableVertexAttribArray(0); // 0 -> positions
    glEnableVertexAttribArray(1); // 1 -> texture coordinates
    textured_model->get_model_texture()->get_texture()->bind_to_unit(0);

    glDrawElements(GL_TRIANGLES, model->get_indices().size(), GL_UNSIGNED_INT, model->get_indices().data());

    glDisableVertexAttribArray(0); // 0 -> positions
    glDisableVertexAttribArray(1); // 1 -> texture coordinates
    
    model->get_vao()->unbind(std::vector<int>());
}
