//
// Created by seaeagle on 07.10.21.
//

#ifndef LAB1_AHRENSGAMMAMETHOD_H
#define LAB1_AHRENSGAMMAMETHOD_H
#include "algorithms.h"
#include<bits/stdc++.h>
using namespace std;

class AhrensGammaMethod: public IStrategy {
public:
    explicit AhrensGammaMethod(IUniformStrategy *X, bool printInfo, bool useDefaults);
    double nextNumber() override;
    double nextNumber(double lower, double upper) override;
private:
    IUniformStrategy *Y;
    void printInfo(bool useDefaults);
    double a = 1;
};


#endif //LAB1_AHRENSGAMMAMETHOD_H
