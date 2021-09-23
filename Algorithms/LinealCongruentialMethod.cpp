//
// Created by seaeagle on 07.09.21.
//

#include "../include/Algorithms/LinealCongruentialMethod.h"



LinealCongruentialMethod::LinealCongruentialMethod(int seed, bool printInfo, bool useDefaults) {
    this->name = __func__;
    this->previous = seed;
    if (printInfo) {
        this->printInfo(seed, useDefaults);
    }
}

void LinealCongruentialMethod::printInfo(int seed, bool useDefaults) {
    cout << "You chose LinealCongruentialMethod with seed: " << seed << endl;
    cout << "X_n = (A * X_n-1 + C) % M" << endl;
    cout << "Recommended constants:\nA: " << a  << "\nC: " << c << "\nM: " << m << endl << endl;
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
            if (__gcd(m, c) != 1) {
                cout << "M and C should be coprime" << endl;
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

            vector<long long> fact = Utils::factorize(m);
            for (auto it : fact) {
                if (a-1 > it && (a-1) % it != 0) {
                    cout << "A-1 should be multiple of all prime divisors of m" << endl;
                    ok = false;
                    break;
                }
                if (a-1 < it) break;
            }

            if (m % 4 == 0 && (a-1) % 4 != 0) {
                cout << "M is a multiplier of 4, a-1 should also be a multiplier of 4" << endl;
                ok = false;
            }

            if (ok) break;
            cout << "Please try again..." << endl << endl;
        }


    }
    else {
        cout << "Using default recommended constants..." << endl;
    }
}

int LinealCongruentialMethod::nextInt() {
    int ans = static_cast<int>(((a * previous) % m + c) % m);
    updatePrev(ans);
    return ans;
}

void LinealCongruentialMethod::updatePrev(int newNumber) {
    previous = nextInt();
}

int LinealCongruentialMethod::getM() {
    return this->m;
}

string LinealCongruentialMethod::getName() {
    return name;
}


