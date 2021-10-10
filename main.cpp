#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2")

#include<bits/stdc++.h>
#include "include/IStrategy.h"
#include "include/RandomGenerator.h"
#include "include/Algorithms/algorithms.h"

using namespace std;

int main() {
    bool change = false;

    cout << "OOP - LAB1" << endl;
    cout << "Author: Oleksiienko Pavlo, K-22" << endl;
    cout << "Do you want to input your own coefficients? (y/n) ";
    string ans;
    cin >> ans;
    if (ans == "y") {
        change = true;
    }
    cout << endl << "Please input number 1 to 10 to select generation method: " << endl;
    int number;
    cin >> number;
    RandomGenerator* generator = nullptr;
    switch (number) {
        case 1: {
            generator = new RandomGenerator(new LinealCongruentialMethod(1489,true, !change));
            break;
        }
        case 2: {
            generator = new RandomGenerator(new QuadraticCongruentialMethod(1489,true, !change));
            break;
        }
        case 3: {
            generator = new RandomGenerator(new FibonacciMethod(228, 420,true, !change));
            break;
        }
        case 4: {
            generator = new RandomGenerator(new InverseCongruentialMethod(1489,true, !change));
            break;
        }
        case 5: {
            generator = new RandomGenerator(UnityMethod::getUnityMethod(420, 228, true, !change));
            break;
        }
        case 6: {
            generator = new RandomGenerator(
                    new ThreeSigmaMethod(
                            new QuadraticCongruentialMethod(1489, false, true),
                            true,
                            !change
                            ));
            break;
        }
        case 7: {
            generator = new RandomGenerator(
                    new PolarCoordintesMethod(
                            new InverseCongruentialMethod(1489, false, true),
                            true,
                            !change
                    ));
            break;
        }
        case 8: {
            generator = new RandomGenerator(
                    new CorrelationMethod(
                            new FibonacciMethod(1489, 228, false, true),
                            true,
                            !change
                    ));
            break;
        }
        case 9: {
            generator = new RandomGenerator(
                    new LogarithmExponentialMethod(
                            new LinealCongruentialMethod(1489, false, true),
                            true,
                            !change
                    ));
            break;
        }
        case 10: {
            generator = new RandomGenerator(
                    new AhrensGammaMethod(
                            UnityMethod::getUnityMethod(false, true),
                            true,
                            !change
                    ));
            break;
        }
        default: {
            cout << "Wrong input, try again!" << endl;
            return 0;
        }
    }

    double lower, upper, step;
    if (number < 6) {
        lower = 0;
        upper = 1;
        step = 0.1;
    }
    else if (number >= 6 && number < 9) {
        lower = -3;
        upper = 3;
        step = 0.6;
    }
    else {
        lower = 0;
        upper = 100;
        step = 10;
    }
    auto distribution = generator->getDistribution(lower, upper, step, 100000);
    for (const auto &it: distribution) {
       cout << it.first << " --- " << it.second << endl;
    }



}