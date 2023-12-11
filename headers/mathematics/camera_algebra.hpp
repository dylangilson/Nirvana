/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * December 10, 2023
 */

#pragma once

#include "linear_algebra.hpp"
#include "./entities/camera.hpp"

class CameraAlgebra {
    public:
        static Matrix4f create_transformation_matrix(Vector3f translation, Vector3f rotation, float scale);
        static Matrix4f create_view_matrix(Camera camera);
};
