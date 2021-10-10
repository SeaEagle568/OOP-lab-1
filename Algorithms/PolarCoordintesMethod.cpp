//
// Created by seaeagle on 05.10.21.
//

#include "../include/Algorithms/PolarCoordintesMethod.h"

PolarCoordintesMethod::PolarCoordintesMethod(IUniformStrategy *X, bool printInfo, bool useDefaults) {
    this->X = X;
    if (printInfo) {
        this->printInfo(useDefaults);
    }
}

double PolarCoordintesMethod::nextNumber() {
    if (cache != -inf) {
        double temp = cache;
        cache = -inf;
        return temp;
    }
    while (true) {
        double v1 = X->nextNumber(-1, 1);
        double v2 = X->nextNumber(-1, 1);
        if (v1*v1 + v2*v2 < 1) {
            double S = v1*v1 + v2*v2;
            cache = v2 * sqrt(-2 * log(S) / S);
            return v1 * sqrt(-2 * log(S) / S);
        }
    }
}

double PolarCoordintesMethod::nextNumber(double lower, double upper) {
    if (lower != -3 && upper != 3){
        return lower;
    }
    else return nextNumber();
}

void PolarCoordintesMethod::printInfo(bool useDefaults) {
    cout << "You chose PolarCoordintesMethod with subMethod: " << X->getName() << endl;
}
