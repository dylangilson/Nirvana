/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * December 3, 2023
 */

#include "./mathematics/random_number_generator.hpp"

RandomNumberGenerator::RandomNumberGenerator() {
    struct timespec ts;
    timespec_get(&ts, TIME_UTC);

    seed = ts.tv_nsec;
    mersenne_twister = std::mt19937_64(seed);
}

// return a float in range [0, 1]
float RandomNumberGenerator::rand() {
    return (float)mersenne_twister() / (float)mersenne_twister.max();
}

// return an unsigned int in range [0, max - 1]
unsigned int RandomNumberGenerator::rand_in_range(unsigned int max) {
    return (unsigned int)((float)mersenne_twister() / (float)(mersenne_twister.max() / max));
}

long RandomNumberGenerator::get_seed() {
    return seed;
}

std::mt19937_64 RandomNumberGenerator::get_mersenne_twister() {
    return mersenne_twister;
}
