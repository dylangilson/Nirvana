/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * November 19, 2023
 */

#pragma once

#include <cmath>
#include <iostream>
#include <vector>

class Vector2f {
    public:
        float x;
        float y;

        Vector2f();
        Vector2f(float x, float y);
        Vector2f operator+=(Vector2f vector);
        Vector2f operator+(Vector2f vector);
        friend std::ostream &operator<<(std::ostream &ret, const Vector2f &vector);
        void normalize();
        float dot_product(Vector2f vector);
        float length() const;
};

class Vector3f {
    public:
        float x;
        float y;
        float z;

        Vector3f();
        Vector3f(float x, float y, float z);
        Vector3f operator+=(Vector3f vector);
        Vector3f operator+(Vector3f vector);
        friend std::ostream &operator<<(std::ostream &ret, const Vector3f &vector);
        void normalize();
        float dot_product(Vector3f vector);
        void cross_product(Vector3f vector);
        float length() const;
};

class Matrix4f {
    public:
	    float m[16];

        Matrix4f operator*=(Matrix4f matrix);
        Matrix4f operator*(Matrix4f matrix);
        friend std::ostream &operator<<(std::ostream &ret, const Matrix4f &matrix);
        void rotateX(float angle);
        void rotateY(float angle);
        void rotateZ(float angle);
        void scale(Vector3f vector);
        void translate(Vector3f vector);
        void transpose();
};

class Vector4f {
    public:
        float x;
        float y;
        float z;
        float w;

        Vector4f();
        Vector4f(float x, float y, float z, float w);
        Vector4f operator+=(Vector4f vector);
        Vector4f operator+(Vector4f vector);
        Vector4f operator*=(Matrix4f matrix);
        Vector4f operator*(Matrix4f matrix);
        friend std::ostream &operator<<(std::ostream &ret, const Vector4f &vector);
        void normalize();
        float dot_product(Vector4f vector);
        void cross_product(Vector4f vector);
};

static const float PI = 3.1415926f;

static const Vector4f X_AXIS = {1.0f, 0.0f, 0.0f, 0.0f};
static const Vector4f Y_AXIS = {0.0f, 1.0f, 0.0f, 0.0f};
static const Vector4f Z_AXIS = {0.0f, 0.0f, 1.0f, 0.0f};
static const Vector4f INV_X_AXIS = {-1.0f, 0.0f, 0.0f, 0.0f};
static const Vector4f INV_Y_AXIS = {0.0f, -1.0f, 0.0f, 0.0f};
static const Vector4f INV_Z_AXIS = {0.0f, 0.0f, -1.0f, 0.0f};

static const Matrix4f IDENTITY_MATRIX = {
	1.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 1.0f
};

static const Matrix4f ZERO_MATRIX = {
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f
};
