//
// Created by seaeagle on 07.09.21.
//

#ifndef LAB1_LINEALCONGRUENTIALMETHOD_H
#define LAB1_LINEALCONGRUENTIALMETHOD_H


#include "../IStrategy.h"
#include "Utils.h"
#include "../IUniformStrategy.h"
#include<bits/stdc++.h>

using namespace std;


class LinealCongruentialMethod : public IUniformStrategy {
public:
    explicit LinealCongruentialMethod(int seed, bool printInfo, bool useDefaults);

    int nextInt() override;

    string getName() override;

private:
    long long m = (1ll << 31) - 1;
    long long a = 2147483629;
    long long c = 2147483587;
    long long previous;
    string name;
    void printInfo(int seed, bool useDefaults);

    void updatePrev(int newNumber) override;

    int getM() override;

protected:

};


#endif //LAB1_LINEALCONGRUENTIALMETHOD_H
