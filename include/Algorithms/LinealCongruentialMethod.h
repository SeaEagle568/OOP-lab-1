//
// Created by seaeagle on 07.09.21.
//

#ifndef LAB1_LINEALCONGRUENTIALMETHOD_H
#define LAB1_LINEALCONGRUENTIALMETHOD_H


#include "../IStrategy.h"
#include "Utils.h"
#include<bits/stdc++.h>
using namespace std;


class LinealCongruentialMethod : public IStrategy {
public:
    //double nextNumber(double lower, double upper) override;

    double nextNumber() override;

    explicit LinealCongruentialMethod(int seed, bool printInfo, bool useDefaults);

private:
    long long m = (1ll << 31) - 1;
    long long a = 2147483629;
    long long c = 2147483587;
    long long previous;

    void printInfo(int seed, bool useDefaults);
};


#endif //LAB1_LINEALCONGRUENTIALMETHOD_H
