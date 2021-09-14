//
// Created by seaeagle on 07.09.21.
//

#include "../include/Algorithms/LinialCongruentialMethod.h"


double LinialCongruentialMethod::nextNumber() {
    int nextInt = static_cast<int>(((a * previous) % m + c) % m);
    previous = nextInt;
    return static_cast<double>(nextInt) / static_cast<double>(m - 1);
}


LinialCongruentialMethod::LinialCongruentialMethod(int seed) {
    this->seed = seed;
    this->previous = seed;
}


