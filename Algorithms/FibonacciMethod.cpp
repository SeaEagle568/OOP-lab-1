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

FibonacciMethod::FibonacciMethod(int seed1, int seed2, bool printInfo, bool useDefaults) {
    previous = seed1;
    subprevious = seed2;
    if (printInfo) {
        this->printInfo(seed1, seed2, useDefaults);
    }
}

void FibonacciMethod::printInfo(int seed1, int seed2, bool useDefaults) {
    cout << "You chose FibonacciMethod with seeds: " << seed1 << ", " << seed2 << endl;
    cout << "X_n = (X_n-1 + X_n-2) % M" << endl;
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

