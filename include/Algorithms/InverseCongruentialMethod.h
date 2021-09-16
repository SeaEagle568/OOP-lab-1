//
// Created by seaeagle on 14.09.21.
//

#ifndef LAB1_INVERSECONGRUENTIALMETHOD_H
#define LAB1_INVERSECONGRUENTIALMETHOD_H


#include "../IStrategy.h"
#include "Utils.h"

class InverseCongruentialMethod : public IStrategy {
public:
    //double nextNumber(double lower, double upper) override;

    double nextNumber() override;

    explicit InverseCongruentialMethod(int seed, bool printInfo, bool useDefaults);

private:
    long long m = (1ll << 31) - 1;
    long long a = 2147483629;
    long long c = 2147483586;
    long long previous;
    long long inv_coef;
    void printInfo(int seed, bool useDefaults);

};


#endif //LAB1_INVERSECONGRUENTIALMETHOD_H
