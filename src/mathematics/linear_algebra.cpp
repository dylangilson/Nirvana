/*
 * Dylan Gilson
 * dylan.gilson@retlook.com
 * November 19, 2023
 */

#include "./mathematics/linear_algebra.hpp"

static const float PI = 3.14159265358979323846;

/** Vector3f implementation ***/

Vector3f::Vector3f(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

std::ostream &operator<<(std::ostream &ret, const Vector3f &vector) {
    ret << "[" << vector.x << ", " << vector.y << ", " << vector.z << "]";
    return ret;
}

void Vector3f::normalize() {
    float magnitude = sqrt(x * x + y * y + z * z);

    // vector already normalized
    if (magnitude == 0.0f || magnitude == 1.0f) {
        return;
    }

	x = x / magnitude;
	y = y / magnitude;
	z = z / magnitude;
}

float Vector3f::dot_product(Vector3f vector) {
    return x * vector.x + y * vector.y + z * vector.z;
}

void Vector3f::cross_product(Vector3f vector) {
    Vector3f ret(0.0f, 0.0f, 0.0f);

	ret.x = y * vector.z - z * vector.y;
	ret.y = z * vector.x - x * vector.z;
	ret.z = x * vector.y - y * vector.x;

    x = ret.x;
    y = ret.y;
    z = ret.z;
}

/** Matrix4f implementation ***/

Matrix4f Matrix4f::operator*=(Matrix4f matrix) {
    Matrix4f temp = IDENTITY_MATRIX;
    size_t row;
    size_t row_offset;
    size_t column;

	for (row = 0, row_offset = row * 4; row < 4; ++row, row_offset = row * 4) {
		for (column = 0; column < 4; ++column) {
			temp.m[row_offset + column] =
				m[row_offset + 0] * matrix.m[column + 0] +
				m[row_offset + 1] * matrix.m[column + 4] +
				m[row_offset + 2] * matrix.m[column + 8] +
				m[row_offset + 3] * matrix.m[column + 12];
        }
    }

    for (size_t i = 0; i < 16; i++) {
        m[i] = temp.m[i];
    }

	return *this;
}

Matrix4f Matrix4f::operator*(Matrix4f matrix) {
    Matrix4f ret = IDENTITY_MATRIX;
    size_t row;
    size_t row_offset;
    size_t column;

	for (row = 0, row_offset = row * 4; row < 4; ++row, row_offset = row * 4) {
		for (column = 0; column < 4; ++column) {
			ret.m[row_offset + column] =
				m[row_offset + 0] * matrix.m[column + 0] +
				m[row_offset + 1] * matrix.m[column + 4] +
				m[row_offset + 2] * matrix.m[column + 8] +
				m[row_offset + 3] * matrix.m[column + 12];
        }
    }

	return ret;
}

std::ostream &operator<<(std::ostream &ret, const Matrix4f &matrix) {
    ret << matrix.m[0] << " " << matrix.m[1] << " " << matrix.m[2] << " " << matrix.m[3] << std::endl;
    ret << matrix.m[4] << " " << matrix.m[5] << " " << matrix.m[6] << " " << matrix.m[7] << std::endl;
    ret << matrix.m[8] << " " << matrix.m[9] << " " << matrix.m[10] << " " << matrix.m[11] << std::endl;
    ret << matrix.m[12] << " " << matrix.m[13] << " " << matrix.m[14] << " " << matrix.m[15];

    return ret;
}

void Matrix4f::rotateX(float angle) {
    Matrix4f rotation = IDENTITY_MATRIX;
    float sine = (float)sin(angle);
    float cosine = (float)cos(angle);

    rotation.m[5] = cosine;
	rotation.m[6] = -sine;
	rotation.m[9] = sine;
	rotation.m[10] = cosine;

    *this *= rotation;
}

void Matrix4f::rotateY(float angle) {
    Matrix4f rotation = IDENTITY_MATRIX;
    float sine = (float)sin(angle);
	float cosine = (float)cos(angle);
	
	rotation.m[0] = cosine;
	rotation.m[8] = sine;
	rotation.m[2] = -sine;
	rotation.m[10] = cosine;

    *this *= rotation;
}

void Matrix4f::rotateZ(float angle) {
    Matrix4f rotation = IDENTITY_MATRIX;
    float sine = (float)sin(angle);
	float cosine = (float)cos(angle);
	
	rotation.m[0] = cosine;
	rotation.m[1] = -sine;
	rotation.m[4] = sine;
	rotation.m[5] = cosine;

    *this *= rotation;
}

void Matrix4f::scale(Vector3f vector) {
    m[0] *= vector.x;
    m[1] *= vector.x;
    m[2] *= vector.x;
    m[3] *= vector.x;
    m[4] *= vector.y;
    m[5] *= vector.y;
    m[6] *= vector.y;
    m[7] *= vector.y;
    m[8] *= vector.z;
    m[9] *= vector.z;
    m[10] *= vector.z;
    m[11] *= vector.z;
}

void Matrix4f::translate(Vector3f vector) {
    Matrix4f translation = IDENTITY_MATRIX;

    translation.m[12] = vector.x;
	translation.m[13] = vector.y;
	translation.m[14] = vector.z;

    *this *= translation;
}

/** Vector4f implementation ***/

Vector4f::Vector4f(float x, float y, float z, float w) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

Vector4f Vector4f::operator*=(Matrix4f matrix) {
    Vector4f temp(0.0f, 0.0f, 0.0f, 0.0f);

    temp.x = matrix.m[0] * x + matrix.m[4] * y + matrix.m[8] * z + matrix.m[12] * w;
    temp.y = matrix.m[1] * x + matrix.m[5] * y + matrix.m[9] * z + matrix.m[13] * w;
    temp.z = matrix.m[2] * x + matrix.m[6] * y + matrix.m[10] * z + matrix.m[14] * w;
    temp.w = matrix.m[3] * x + matrix.m[7] * y + matrix.m[11] * z + matrix.m[15] * w;

    x = temp.x;
    y = temp.y;
    z = temp.z;
    w = temp.w;

    return *this;
}

Vector4f Vector4f::operator*(Matrix4f matrix) {
    Vector4f ret(0.0f, 0.0f, 0.0f, 0.0f);

    ret.x = matrix.m[0] * x + matrix.m[4] * y + matrix.m[8] * z + matrix.m[12] * w;
    ret.y = matrix.m[1] * x + matrix.m[5] * y + matrix.m[9] * z + matrix.m[13] * w;
    ret.z = matrix.m[2] * x + matrix.m[6] * y + matrix.m[10] * z + matrix.m[14] * w;
    ret.w = matrix.m[3] * x + matrix.m[7] * y + matrix.m[11] * z + matrix.m[15] * w;

    return ret;
}

std::ostream &operator<<(std::ostream &ret, const Vector4f &vector) {
    ret << "[" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << "]";
    return ret;
}

void Vector4f::normalize() {
    float magnitude = sqrt(x * x + y * y + z * z + w * w);

    // vector already normalized
    if (magnitude == 0.0f || magnitude == 1.0f) {
        return;
    }

	x = x / magnitude;
	y = y / magnitude;
	z = z / magnitude;
    w = w / magnitude;
}

float Vector4f::dot_product(Vector4f vector) {
    return x * vector.x + y * vector.y + z * vector.z + w * vector.w;
}

void Vector4f::cross_product(Vector4f vector) {
    Vector4f ret(0.0f, 0.0f, 0.0f, 0.0f);

	ret.x = y * vector.z - z * vector.y;
	ret.y = z * vector.x - x * vector.z;
	ret.z = x * vector.y - y * vector.x;

    x = ret.x;
    y = ret.y;
    z = ret.z;
    w = 0;
}
