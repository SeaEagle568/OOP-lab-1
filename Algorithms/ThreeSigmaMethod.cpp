//
// Created by seaeagle on 23.09.21.
//

#include "../include/Algorithms/ThreeSigmaMethod.h"

ThreeSigmaMethod::ThreeSigmaMethod(IUniformStrategy *X, bool printInfo, bool useDefaults) {
    this->X = X;
    if (printInfo) {
        this->printInfo(useDefaults);
    }
}

void ThreeSigmaMethod::printInfo(bool useDefaults) {
    cout << "You chose ThreeSigmaMethod with subMethod: " << X->getName() << endl;
    cout << "X_n = m + (sum - 6) * sigma" << endl;
    cout << "-- Sum is sum of 12 uniformly distributed numbers from 0 to 1" << endl;
    cout << "-- m = 0" << endl;
    cout << "-- sigma = 1" << endl;
}

double ThreeSigmaMethod::nextNumber() {
    double sum = 0;
    for (int i = 0; i < 12; i++) {
        sum += X->nextNumber();
    }
    return (sum - 6);
}

double ThreeSigmaMethod::nextNumber(double lower, double upper) {
    if (lower != -3 && upper != 3){
        throw "Panic: ThreeSigmaMethod cannot generate this distribution";
    }
    else return nextNumber();
}
