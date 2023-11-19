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

void Renderer::render(RawModel *model) {
    model->get_vao()->bind(std::vector<int>());

    glEnableVertexAttribArray(0); // 0 -> positions

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glDrawElements(GL_TRIANGLES, model->get_indices().size(), GL_UNSIGNED_INT, model->get_indices().data());

    glDisableVertexAttribArray(0); // 0 -> positions
    
    model->get_vao()->unbind(std::vector<int>());
}
