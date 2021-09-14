//
// Created by seaeagle on 14.09.21.
//

#ifndef LAB1_FIBONACCIMETHOD_H
#define LAB1_FIBONACCIMETHOD_H


#include "../IStrategy.h"

class FibonacciMethod : public IStrategy {
public:
    //double nextNumber(double lower, double upper) override;

    double nextNumber() override;

    explicit FibonacciMethod(int seed1, int seed2);

private:
    const long long m = (1ll << 31) - 1;
    long long previous;
    long long subprevious;
};



#endif //LAB1_FIBONACCIMETHOD_H
