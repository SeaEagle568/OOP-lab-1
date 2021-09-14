//
// Created by seaeagle on 07.09.21.
//

#ifndef LAB1_LINIALCONGRUENTIALMETHOD_H
#define LAB1_LINIALCONGRUENTIALMETHOD_H


#include "../IStrategy.h"

class LinialCongruentialMethod : public IStrategy {
public:
    //double nextNumber(double lower, double upper) override;

    double nextNumber() override;

    explicit LinialCongruentialMethod(int seed);

private:
    const long long m = (1ll << 31) - 1;
    const long long a = 2147483629;
    const long long c = 2147483587;
    long long seed;
    long long previous;
};


#endif //LAB1_LINIALCONGRUENTIALMETHOD_H
