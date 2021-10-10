//
// Created by seaeagle on 05.10.21.
//

#ifndef LAB1_POLARCOORDINTESMETHOD_H
#define LAB1_POLARCOORDINTESMETHOD_H
#include "algorithms.h"
#include<bits/stdc++.h>
using namespace std;

const double inf = 1e9;
class PolarCoordintesMethod: public IStrategy {
public:
    explicit PolarCoordintesMethod(IUniformStrategy *X, bool printInfo, bool useDefaults);
    double nextNumber() override;
    double nextNumber(double lower, double upper) override;
private:
    IUniformStrategy *X;
    void printInfo(bool useDefaults);
    double cache = -inf;
};


#endif //LAB1_POLARCOORDINTESMETHOD_H
