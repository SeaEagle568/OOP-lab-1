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
    //double nextNumber(double lower, double upper) override;

    double nextNumber() override;

    explicit FibonacciMethod(int seed1, int seed2, bool printInfo, bool useDefaults);

private:
    long long m = (1ll << 31) - 1;
    long long previous;
    long long subprevious;
    void printInfo(int seed1, int seed2, bool useDefaults);
};



#endif //LAB1_FIBONACCIMETHOD_H
