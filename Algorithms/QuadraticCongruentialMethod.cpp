//
// Created by seaeagle on 14.09.21.
//

#include "../include/Algorithms/QuadraticCongruentialMethod.h"


double QuadraticCongruentialMethod::nextNumber() {
    int nextInt = static_cast<int>(((d * ((previous * previous) % m)) % m + (a * previous) % m + c) % m);
    previous = nextInt;
    return static_cast<double>(nextInt) / static_cast<double>(m - 1);
}

QuadraticCongruentialMethod::QuadraticCongruentialMethod(int seed) {
    this->seed = seed;
    this->previous = seed;
}
