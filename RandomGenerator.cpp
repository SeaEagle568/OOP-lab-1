//
// Created by seaeagle on 07.09.21.
//

#include "include/RandomGenerator.h"
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
    addValues(result, generatedValues, lower, step);
    return result;
}

vector<double> RandomGenerator::generateValues(double lower, double upper, int n) {
    vector<double> generatedValues;
    generatedValues.reserve(n);
    for (int i = 0; i < n; i++) {
        generatedValues.push_back(strategy->nextNumber(lower, upper));
    }
    return generatedValues;
}


void RandomGenerator::addLore(vector<pair<string, string>> &list, double lower, double upper, double step) {
    size_t maxLength = 0;
    for (double i = lower; upper - i > EPS; i += step) {
        string left = removeZeros(to_string(i));
        string right = removeZeros(to_string(i + step));
        string lore = "[" + left.append(" ; ").append(right) + ")";
        maxLength = max(maxLength, lore.size());
        list.emplace_back(lore, "");
    }

    for (auto &it: list) {
        for (size_t i = it.first.size(); i < maxLength; i++) {
            it.first += " ";
        }
    }

    if (list.empty()) return;
    string &last = list.rbegin()->first;
    last.replace(last.find(')'), 1, "]");
}

void RandomGenerator::addValues(vector<pair<string, string>> &list, vector<double> &values, double lower, double step) {
    map<double, int> countList;
    map<int, double> temp;
    for (auto it: values) {
        countList[it]++;
    }
    for (auto it: countList) {
        int index = (int) ((it.first - lower) / step);
        if (index >= list.size()) index = (int) (list.size() - 1);
        temp[index] += (double) it.second / (double) values.size();
    }
    for (auto it: temp) {
        list[it.first].second = removeZeros(to_string(it.second));
    }
}

double RandomGenerator::nextNumber() {
    return strategy->nextNumber();
}

string RandomGenerator::removeZeros(string input) {
    size_t dotpos = input.find_first_of('.');
    if (dotpos != string::npos) {
        size_t pos = input.size() - 1;
        while ((input[pos] == '0' || input[pos] == '.') && pos >= dotpos) {
            --pos;
        }
        input.erase(pos + 1, string::npos);
    }
    return input;
}

RandomGenerator::~RandomGenerator() = default;



