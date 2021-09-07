//
// Created by seaeagle on 07.09.21.
//

#include "Headers/RandomGenerator.h"
#include<bits/stdc++.h>

using namespace std;
const double EPS = 1e-8;

RandomGenerator::RandomGenerator(IStrategy *strategy) {
    this->strategy = strategy;
}

vector<pair<string, string>>
RandomGenerator::getDistribution(double lower, double upper, double step, int iterations) {
    //TODO: add fool check
    vector<double> generatedValues = generateValues(lower, upper, iterations);
    vector<pair<string, string>> result;

    addLore(result, lower, upper, step);
    addValues(result, generatedValues);
    return result;
}

vector<double> RandomGenerator::generateValues(double lower, double upper, int n) {
    vector<double> generatedValues;
    for (int i = 0; i < n; i++) {
        generatedValues.push_back(strategy->nextNumber(lower, upper));
    }
    return generatedValues;
}

void RandomGenerator::addLore(vector<pair<string, string>> &list, double lower, double upper, double step) {
    for (double i = lower; upper - i - step > EPS; i += step) {
        string lore = "[" + to_string(i) + "; " + to_string(i + step) + ")";
        list.emplace_back(lore, "");
    }
    string &last = list.end()->first;
    last.replace(last.find(')'), 1, "]");
}

void RandomGenerator::addValues(vector<pair<string, string>> &list, vector<double> &values, double lower, double step) {
    map<double, int> countList;
    for (auto it: values) {
        countList[it]++;
    }
    for (auto it: countList) {
        int index = (int) ((it.first - lower) / step);
        list[index].second = to_string((double) it.second / (double) values.size());
    }
}

double RandomGenerator::nextNumber() {
    return strategy->nextNumber();
}

RandomGenerator::~RandomGenerator() = default;



