//
// Created by kates on 04.03.2021.
//

#ifndef MAIN_CPP_RANDOMIZE_H
#define MAIN_CPP_RANDOMIZE_H
#include <iostream>
#include <random>
#include <ctime>
using namespace std;

class Randomize {
public:
    static int GetRand(int min, int max)
    {
        srand(_time64(NULL));
        return min + (rand() % ((max - min) + 1));;
    }
};




#endif //MAIN_CPP_RANDOMIZE_H
