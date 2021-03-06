//
// Created by kates on 04.03.2021.
//

#ifndef MAIN_CPP_RANDOMIZE_H
#define MAIN_CPP_RANDOMIZE_H
#include <iostream>
#include <time.h>
using namespace std;

class Randomize {
public:
    int Rand(int min, int max)
    {
        srand(static_cast<unsigned int>(time(0)));
        static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
        return static_cast<int>(rand() * fraction * (max - min + 1) + min);
    }
};


#endif //MAIN_CPP_RANDOMIZE_H
