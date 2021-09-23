//
// Created by seaeagle on 07.09.21.
//

#include "include/IStrategy.h"

double IStrategy::nextNumber(double lower, double upper) {
    double number = nextNumber();
    return number * (upper - lower) + lower;
}

double IStrategy::nextNumber() {
    int nextInt = this->nextInt();
    return static_cast<double>(nextInt) / static_cast<double>(getM() - 1);
}


