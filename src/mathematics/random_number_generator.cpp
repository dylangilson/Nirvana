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

// return an int in range [min, max]
int RandomNumberGenerator::rand_in_range(int min, int max) {
    if (min == max) {
        return max;
    }

    if (min > max) {
        std::swap(min, max);
    }

    return min + mersenne_twister() % (max - min + 1);
}

long RandomNumberGenerator::get_seed() {
    return seed;
}

std::mt19937_64 RandomNumberGenerator::get_mersenne_twister() {
    return mersenne_twister;
}
