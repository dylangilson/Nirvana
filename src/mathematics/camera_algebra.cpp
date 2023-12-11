/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * December 10, 2023
 */

#include "./mathematics/camera_algebra.hpp"

Matrix4f CameraAlgebra::create_transformation_matrix(Vector3f translation, Vector3f rotation, float scale) {
    Matrix4f matrix = IDENTITY_MATRIX;
    matrix.rotateX(rotation.x);
    matrix.rotateY(rotation.y);
    matrix.rotateZ(rotation.z);
    matrix.translate(translation);
    matrix.scale(Vector3f(scale, scale, scale));

    return matrix;
}

Matrix4f CameraAlgebra::create_view_matrix(Camera camera) {
    Vector3f negative_camera_position(-camera.get_position().x, -camera.get_position().y, -camera.get_position().z);
    Matrix4f matrix = IDENTITY_MATRIX;
    matrix.rotateX(camera.get_pitch());
    matrix.rotateY(camera.get_yaw());
    matrix.translate(negative_camera_position);
    
    return matrix;
}
