//
// Created by seaeagle on 14.09.21.
//

#include "../include/Algorithms/InverseCongruentialMethod.h"


void InverseCongruentialMethod::printInfo(int seed, bool useDefaults) {
    cout << "You chose InverseCongruentialMethod with seed: " << seed << endl;
    cout << "X_n = (A * (X_n-1)^(-1) + C) % M" << endl;
    cout << string() + "Recommended constants:\n" + "A: " + to_string(a) + "\nC: " + to_string(c) + "\nM: " + to_string(m) << endl << endl;
    if (!useDefaults) {

        while (true)
        {
            cout << "Please enter module constant: " << endl;
            cin >> this->m;
            cout << "Please enter A (multiplier) constant: " << endl;
            cin >> this->a;
            cout << "Please enter C constant: " << endl;
            cin >> this->c;
            cout << "Please enter seed (initial value): " << endl;
            cin >> this->previous;
            bool ok = true;

            if (Utils::phi(m) != m-1) {
                cout << "M should be prime" << endl;
                ok = false;
            }
            if (m < 0) {
                cout << "M should be > 0" << endl;
                ok = false;
            }
            if (a >= m || a < 0) {
                cout << "A should be >= 0 and < m" << endl;
                ok = false;
            }
            if (c < 0 && c >= m) {
                cout << "C should be >= 0 and < m" << endl;
            }

            if (ok) break;
            cout << "Please try again..." << endl << endl;
        }


    }
    else {
        cout << "Using default recommended constants..." << endl;
    }
}


InverseCongruentialMethod::InverseCongruentialMethod(int seed, bool printInfo, bool useDefaults) {
    this->name = __func__;
    previous = seed;
    if (printInfo) {
        this->printInfo(seed, useDefaults);
    }
    inv_coef = Utils::phi(m);
}

int InverseCongruentialMethod::nextInt() {
    int ans = static_cast<int>(((a * Utils::binpow(previous, inv_coef-1, m)) % m + c) % m);
    updatePrev(ans);
    return ans;
}

void InverseCongruentialMethod::updatePrev(int newNumber) {
    previous = newNumber;
}

int InverseCongruentialMethod::getM() {
    return this->m;
}

string InverseCongruentialMethod::getName() {
    return name;
}

