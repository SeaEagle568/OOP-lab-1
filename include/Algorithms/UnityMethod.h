//
// Created by seaeagle on 23.09.21.
//

#ifndef LAB1_UNITYMETHOD_H
#define LAB1_UNITYMETHOD_H


#include "../IStrategy.h"
#include "Utils.h"
#include "QuadraticCongruentialMethod.h"
#include "InverseCongruentialMethod.h"
#include<bits/stdc++.h>

using namespace std;


class UnityMethod : public IStrategy {
public:
    explicit UnityMethod(IStrategy *X, IStrategy *Y, bool printInfo, bool useDefaults);

    static UnityMethod *getUnityMethod(int seed1, int seed2, bool printInfo, bool useDefaults);

    static UnityMethod *getUnityMethod(bool printInfo, bool useDefaults);

    int nextInt() override;

    string getName() override;
private:
    long long m = (1ll << 31) - 1;
    IStrategy *X;
    IStrategy *Y;
    string name;

    void printInfo(bool useDefaults);

    void updatePrev(int newNumber) override;

    int getM() override;

};


#endif //LAB1_UNITYMETHOD_H
