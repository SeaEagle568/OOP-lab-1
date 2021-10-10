//
// Created by seaeagle on 07.10.21.
//

#include "../include/Algorithms/AhrensGammaMethod.h"

AhrensGammaMethod::AhrensGammaMethod(IUniformStrategy *X, bool printInfo, bool useDefaults) {
    this->Y = X;
    if (printInfo) {
        this->printInfo(useDefaults);
    }
}

double AhrensGammaMethod::nextNumber(double lower, double upper) {
    return nextNumber();
}

void AhrensGammaMethod::printInfo(bool useDefaults) {
    cout << "You chose CorrelationMethod with subMethod: " << Y->getName() << endl;
    cout << "Recommended constants:\n" << "A = " << a << endl << endl;
    if (!useDefaults) {
        cout << "Please enter A constant: " << endl;
        cin >> a;
    } else {
        cout << "Using default recommended constants..." << endl;
    }
}

double AhrensGammaMethod::nextNumber() {
    while (true) {
        double Y = tan(acos(-1)*AhrensGammaMethod::Y->nextNumber());
        double X = sqrt(2*a-1) * Y + a - 1;
        if (X <= 0) continue;
        double V = AhrensGammaMethod::Y->nextNumber();
        if (V > (1+Y*Y)*exp((a-1)*log(X/(a-1)) - sqrt(2*a-1) * Y)) continue;
        return X;
    }
}
