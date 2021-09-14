//
// Created by seaeagle on 14.09.21.
//

#include "../include/Algorithms/FibonacciMethod.h"


double FibonacciMethod::nextNumber() {
    int nextInt = static_cast<int>((previous + subprevious) % m);
    subprevious = previous;
    previous = nextInt;
    return static_cast<double>(nextInt) / static_cast<double>(m - 1);
}

FibonacciMethod::FibonacciMethod(int seed1, int seed2) {
    previous = seed1;
    subprevious = seed2;
}
