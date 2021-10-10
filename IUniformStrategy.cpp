//
// Created by seaeagle on 28.09.21.
//

#include "include/IUniformStrategy.h"

double IUniformStrategy::nextNumber() {
    int nextInt = this->nextInt();
    return static_cast<double>(nextInt) / static_cast<double>(getM() - 1);
}
double IUniformStrategy::nextNumber(double lower, double upper) {
    double number = nextNumber();
    return number * (upper - lower) + lower;
}
