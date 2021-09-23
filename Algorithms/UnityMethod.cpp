//
// Created by seaeagle on 23.09.21.
//

#include "../include/Algorithms/UnityMethod.h"

int UnityMethod::nextInt() {
    return Utils::modmin(X->nextInt(), Y->nextInt(), m);
}

void UnityMethod::updatePrev(int newNumber){}

int UnityMethod::getM() {
    return this->m;
}


void UnityMethod::printInfo(bool useDefaults) {
    cout << "You chose UnityMethod with subMethods: " << X->getName() << ", " << Y->getName() << endl;
    cout << "Z_n = (X_n - Y_n) % M" << endl;
    cout << "Recommended constants: \nM: " << m << endl << endl;
    if (!useDefaults) {
        while (true) {
            cout << "Please enter module constant: " << endl;
            cin >> this->m;
            if (m > 0) break;
            cout << "M should be > 0" << endl << endl << "Please try again..." << endl;
        }
    }
    else {
        cout << "Using default recommended constants..." << endl;
    }
}

UnityMethod::UnityMethod(IStrategy* X, IStrategy* Y, bool printInfo, bool useDefaults) {
    this->name = __func__;
    this->X = X;
    this->Y = Y;
    if (printInfo) {
        this->printInfo(useDefaults);
    }
}

UnityMethod *UnityMethod::getUnityMethod(int seed1, int seed2, bool printInfo, bool useDefaults) {
    return new UnityMethod(
            new QuadraticCongruentialMethod(seed1, false, true),
            new InverseCongruentialMethod(seed2, false, true),
            printInfo,
            useDefaults
            );
}

UnityMethod *UnityMethod::getUnityMethod(bool printInfo, bool useDefaults) {
    return new UnityMethod(
            new QuadraticCongruentialMethod(1488, false, true),
            new InverseCongruentialMethod(420, false, true),
            printInfo,
            useDefaults
    );
}

string UnityMethod::getName() {
    return name;
}

