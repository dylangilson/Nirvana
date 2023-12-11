/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * December 3, 2023
 */

#include "./uniforms/uniform_matrix4f.hpp"

UniformMatrix4f::UniformMatrix4f() {

}

UniformMatrix4f::UniformMatrix4f(std::string name) : Uniform(name) {

}

void UniformMatrix4f::load_matrix(Matrix4f value) {
	this->value = value;

	glUniformMatrix4fv(get_location(), 1, false, value.m);
}
