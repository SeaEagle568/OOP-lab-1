//
// Created by seaeagle on 14.09.21.
//

#include "../include/Algorithms/QuadraticCongruentialMethod.h"


double QuadraticCongruentialMethod::nextNumber() {
    int nextInt = static_cast<int>(((d * ((previous * previous) % m)) % m + (a * previous) % m + c) % m);
    previous = nextInt;
    return static_cast<double>(nextInt) / static_cast<double>(m - 1);
}

QuadraticCongruentialMethod::QuadraticCongruentialMethod(int seed, bool printInfo, bool useDefaults) {
    this->previous = seed;
    if (printInfo) {
        this -> printInfo(seed, useDefaults);
    }

}

void QuadraticCongruentialMethod::printInfo(int seed, bool useDefaults) {
    cout << "You chose QuadraticCongruentialMethod with seed: " << seed << endl;
    cout << "X_n = (D * (X_n-1)^2 + A * X_n-1 + C) % M" << endl;
    cout << "Recommended constants:\nD: " << d <<  "\nA: "  << a << "\nC: " << c << "\nM: " << m  << endl << endl;
    if (!useDefaults) {

        while (true)
        {
            cout << "Please enter module constant: " << endl;
            cin >> this->m;
            cout << "Please enter D (multiplier^2) constant: " << endl;
            cin >> this->d;
            cout << "Please enter A (multiplier) constant: " << endl;
            cin >> this->a;
            cout << "Please enter C constant: " << endl;
            cin >> this->c;

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
            if (d < 0 && d >= m) {
                cout << "D should be >= 0 and < m" << endl;
            }

            vector<long long> fact = Utils::factorize(m);
            for (auto it : fact) {
                if ((a-1 > it && (a-1) % it != 0) || (d > it && d % it != 0)) {
                    cout << "A-1 and D should be multiple of all prime divisors of m" << endl;
                    ok = false;
                    break;
                }
                if (a-1 < it && d < it) break;
            }

            if (m % 4 == 0 && (d % 2 != 0 || d % 4 != (a-1) % 4)) {
                cout << "M is a multiplier of 4, d should be even and d ≡ a–1 mod 4" << endl;
                ok = false;
            }
            if (m % 2 == 0 && d % 2 != (a-1) % 2) {
                cout << "M is a multiplier of 2, so d should be ≡ a–1 mod 4" << endl;
                ok = false;
            }
            if (m % 3 == 0 && d % 9 != 3*c % 9) {
                cout << "M is a multiplier of 3, so d should be ≡ 3*c mod 9" << endl;
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
