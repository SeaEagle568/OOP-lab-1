//
// Created by seaeagle on 05.10.21.
//

#ifndef LAB1_LOGARITHMEXPONENTIALMETHOD_H
#define LAB1_LOGARITHMEXPONENTIALMETHOD_H
#include "algorithms.h"
#include<bits/stdc++.h>
using namespace std;

class LogarithmExponentialMethod: public IStrategy {
public:
    explicit LogarithmExponentialMethod(IUniformStrategy *X, bool printInfo, bool useDefaults);
    double nextNumber() override;
    double nextNumber(double lower, double upper) override;
private:
    IUniformStrategy *X;
    double Mu = 8.3;
    void printInfo(bool useDefaults);
};


#endif //LAB1_LOGARITHMEXPONENTIALMETHOD_H
