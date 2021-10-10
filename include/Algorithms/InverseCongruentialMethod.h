//
// Created by seaeagle on 14.09.21.
//

#ifndef LAB1_INVERSECONGRUENTIALMETHOD_H
#define LAB1_INVERSECONGRUENTIALMETHOD_H


#include "../IStrategy.h"
#include "Utils.h"
#include "../IUniformStrategy.h"

class InverseCongruentialMethod : public IUniformStrategy {
public:
    explicit InverseCongruentialMethod(int seed, bool printInfo, bool useDefaults);

    int nextInt() override;

    string getName() override;
private:
    long long m = (1ll << 31) - 1;
    long long a = 2147483629;
    long long c = 2147483586;
    long long previous;
    long long inv_coef;
    string name;

    void printInfo(int seed, bool useDefaults);

    void updatePrev(int newNumber) override;

    int getM() override;


};


#endif //LAB1_INVERSECONGRUENTIALMETHOD_H
