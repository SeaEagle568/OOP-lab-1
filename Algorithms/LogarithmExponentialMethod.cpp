//
// Created by seaeagle on 05.10.21.
//

#include "../include/Algorithms/LogarithmExponentialMethod.h"

LogarithmExponentialMethod::LogarithmExponentialMethod(IUniformStrategy *X, bool printInfo, bool useDefaults) {
    this->X = X;
    if (printInfo) {
        this->printInfo(useDefaults);
    }
}

double LogarithmExponentialMethod::nextNumber() {
    return -Mu * log(X->nextNumber());
}

double LogarithmExponentialMethod::nextNumber(double lower, double upper) {
    return nextNumber();
}

void LogarithmExponentialMethod::printInfo(bool useDefaults) {
    cout << "You chose LogarithmExponentialMethod with subMethod: " << X->getName() << endl;
    cout << "X_n = -Mu * ln(U)" << endl;
    cout << "Recommended constants:\n" << "Mu = " << Mu << endl << endl;
    if (!useDefaults) {
        cout << "Please enter Mu constant: " << endl;
        cin >> Mu;
    } else {
        cout << "Using default recommended constants..." << endl;
    }
}
