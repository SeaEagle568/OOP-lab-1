//
// Created by seaeagle on 23.09.21.
//

#ifndef LAB1_THREESIGMAMETHOD_H
#define LAB1_THREESIGMAMETHOD_H


#include "../IStrategy.h"
#include "Utils.h"
#include "../IUniformStrategy.h"
#include<bits/stdc++.h>

using namespace std;


class ThreeSigmaMethod : public IStrategy {
public:
    explicit ThreeSigmaMethod(IUniformStrategy *X, bool printInfo, bool useDefaults);
    double nextNumber() override;
    double nextNumber(double lower, double upper) override;
private:
    IUniformStrategy *X;
    void printInfo(bool useDefaults);
};


#endif //LAB1_THREESIGMAMETHOD_H
