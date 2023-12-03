/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * December 3, 2023
 */

#pragma once

#include <ctime>
#include <random>

// RandomNumberGenerator uses a Mersenne Twister implementation
class RandomNumberGenerator {
    public:
        RandomNumberGenerator();
        float rand();
        unsigned int rand_in_range(unsigned int max);
        long get_seed();
        std::mt19937_64 get_mersenne_twister();

    private:
        long seed;
        std::mt19937_64 mersenne_twister;
};
