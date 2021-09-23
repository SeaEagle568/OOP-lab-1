//
// Created by seaeagle on 14.09.21.
//

#ifndef LAB1_FIBONACCIMETHOD_H
#define LAB1_FIBONACCIMETHOD_H


#include "../IStrategy.h"
#include<bits/stdc++.h>

using namespace std;

class FibonacciMethod : public IStrategy {
public:
    explicit FibonacciMethod(int seed1, int seed2, bool printInfo, bool useDefaults);

    int nextInt() override;

    string getName() override;

private:
    long long m = (1ll << 31) - 1;
    long long previous;
    long long subprevious;
    string name;

    void printInfo(int seed1, int seed2, bool useDefaults);

    void updatePrev(int newNumber) override;

    int getM() override;

};


#endif //LAB1_FIBONACCIMETHOD_H
