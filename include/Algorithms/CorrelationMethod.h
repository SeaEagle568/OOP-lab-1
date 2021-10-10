//
// Created by seaeagle on 07.10.21.
//

#ifndef LAB1_CORRELATIONMETHOD_H
#define LAB1_CORRELATIONMETHOD_H
#include "algorithms.h"
#include<bits/stdc++.h>
using namespace std;

class CorrelationMethod: public IStrategy {
public:
    explicit CorrelationMethod(IUniformStrategy *X, bool printInfo, bool useDefaults);
    double nextNumber() override;
    double nextNumber(double lower, double upper) override;
private:
    IUniformStrategy *Y;
    void printInfo(bool useDefaults);
};

#endif //LAB1_CORRELATIONMETHOD_H
