//
// Created by seaeagle on 14.09.21.
//

#ifndef LAB1_QUADRATICCONGRUENTIALMETHOD_H
#define LAB1_QUADRATICCONGRUENTIALMETHOD_H


#include "../IStrategy.h"
#include<bits/stdc++.h>
#include "Utils.h"
using namespace std;

class QuadraticCongruentialMethod : public IStrategy {
public:
    //double nextNumber(double lower, double upper) override;

    double nextNumber() override;

    explicit QuadraticCongruentialMethod(int seed, bool printInfo, bool useDefaults);

private:
    long long m = (1ll << 31) - 1;
    long long a = 2147483629;
    long long c = 2147483587;
    long long d = 2147483628;
    long long previous;
    void printInfo(int seed, bool useDefaults);
};


#endif //LAB1_QUADRATICCONGRUENTIALMETHOD_H
