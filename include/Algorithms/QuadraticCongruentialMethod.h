//
// Created by seaeagle on 14.09.21.
//

#ifndef LAB1_QUADRATICCONGRUENTIALMETHOD_H
#define LAB1_QUADRATICCONGRUENTIALMETHOD_H


#include "../IStrategy.h"
#include<bits/stdc++.h>
#include "Utils.h"
#include "../IUniformStrategy.h"

using namespace std;

class QuadraticCongruentialMethod : public IUniformStrategy{
public:
    int nextInt() override;

    explicit QuadraticCongruentialMethod(int seed, bool printInfo, bool useDefaults);

    string getName() override;
private:
    long long m = (1ll << 31) - 1;
    long long a = 2147483629;
    long long c = 2147483587;
    long long d = 2147483628;
    long long previous;
    string name;
    void printInfo(int seed, bool useDefaults);

    void updatePrev(int newNumber) override;

    int getM() override;


};


#endif //LAB1_QUADRATICCONGRUENTIALMETHOD_H
