//
// Created by seaeagle on 07.10.21.
//

#include "../include/Algorithms/CorrelationMethod.h"

CorrelationMethod::CorrelationMethod(IUniformStrategy *X, bool printInfo, bool useDefaults) {
    this->Y = X;
    if (printInfo) {
        this->printInfo(useDefaults);
    }
}

double CorrelationMethod::nextNumber() {
    while (true) {
        double U = 0;
        while (U == 0) U = Y->nextNumber();
        double V = Y->nextNumber();
        double X = sqrt(8/exp(1))*((V - 0.5) / U);
        if (X*X <= 5-4.0*exp(1.0/4.0)*U) return X;
        if (X*X >= (4*exp(-1.35) / U) + 1.4) continue;
        if (X*X <= -4*log(U)) return X;
    }
}

double CorrelationMethod::nextNumber(double lower, double upper) {
    return nextNumber();
}

void CorrelationMethod::printInfo(bool useDefaults) {
    cout << "You chose CorrelationMethod with subMethod: " << Y->getName() << endl;
}
