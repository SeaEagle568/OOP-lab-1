//
// Created by seaeagle on 07.09.21.
//

#ifndef LAB1_RANDOMGENERATOR_H
#define LAB1_RANDOMGENERATOR_H


#include <bits/stdc++.h>
#include "IStrategy.h"

using namespace std;

class RandomGenerator {
private:
    IStrategy *strategy;

    vector<double> generateValues(double lower, double upper, int n);

    static void addLore(vector<pair<string, string>> &list, double lower, double upper, double step);

    static void addValues(vector<pair<string, string>> &list, vector<double> &values, double lower, double step);

public:
    explicit RandomGenerator(IStrategy *strategy);

    vector<pair<string, string>> getDistribution(double lower, double upper, double step, int iterations);

    double nextNumber();

    ~RandomGenerator();
};


#endif //LAB1_RANDOMGENERATOR_H
