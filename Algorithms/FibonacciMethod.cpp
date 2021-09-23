//
// Created by seaeagle on 14.09.21.
//

#include "../include/Algorithms/FibonacciMethod.h"


FibonacciMethod::FibonacciMethod(int seed1, int seed2, bool printInfo, bool useDefaults) {
    this->name = __func__;
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
            cout << "Please enter seed 1 (initial value): " << endl;
            cin >> this->subprevious;
            cout << "Please enter seed 2 (initial value): " << endl;
            cin >> this->previous;
            if (m > 0) break;
            cout << "M should be > 0" << endl << endl << "Please try again..." << endl;
        }
    }
    else {
        cout << "Using default recommended constants..." << endl;
    }
}

int FibonacciMethod::nextInt() {
    int ans = static_cast<int>((previous + subprevious) % m);
    updatePrev(ans);
    return ans;
}

void FibonacciMethod::updatePrev(int newNumber) {
    subprevious = previous;
    previous = newNumber;
}

int FibonacciMethod::getM() {
    return this->m;
}

string FibonacciMethod::getName() {
    return name;
}

