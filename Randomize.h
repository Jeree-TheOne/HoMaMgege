//
// Created by kates on 04.03.2021.
//

#ifndef MAIN_CPP_RANDOMIZE_H
#define MAIN_CPP_RANDOMIZE_H
#include <iostream>
#include <random>
#include <time.h>
using namespace std;

class Randomize {
public:
    static int GetRand(int min, int max)
    {
        std::random_device RandomDevice;
        std::mt19937 generator(RandomDevice());
        std::uniform_int_distribution<> distribution(min, max);
        int x = distribution(generator);
        return x;
    }
};


#endif //MAIN_CPP_RANDOMIZE_H
