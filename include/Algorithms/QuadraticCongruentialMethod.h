//
// Created by seaeagle on 14.09.21.
//

#ifndef LAB1_QUADRATICCONGRUENTIALMETHOD_H
#define LAB1_QUADRATICCONGRUENTIALMETHOD_H


#include "../IStrategy.h"

class QuadraticCongruentialMethod : public IStrategy {
public:
    //double nextNumber(double lower, double upper) override;

    double nextNumber() override;

    explicit QuadraticCongruentialMethod(int seed);

private:
    const long long m = (1ll << 31) - 1;
    const long long a = 2147483629;
    const long long c = 2147483587;
    const long long d = 2147483628;
    long long seed;
    long long previous;

};


#endif //LAB1_QUADRATICCONGRUENTIALMETHOD_H
