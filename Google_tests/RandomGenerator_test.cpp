//
// Created by seaeagle on 07.09.21.
//
#define TESTING
#include "gtest/gtest.h"
#include "../include/RandomGenerator.h"

using namespace std;
class RandomGeneratorUnitTest : public ::testing::Test {

public:
    RandomGeneratorUnitTest() : generator(nullptr) {}

protected:
    void addLore(vector<pair<string, string>> &list, double lower, double upper, double step) {
        generator.addLore(list, lower, upper, step);
    }

    void addValues(vector<pair<string, string>> &list, vector<double> &values, double lower,
                   double step) { generator.addValues(list, values, lower, step); }

    RandomGenerator generator;

};

TEST_F(RandomGeneratorUnitTest, Loretest) {
    vector<pair<string, string>> test;
    addLore(test, -3, 3, 0.6);

    vector<pair<string, string>> expected;

    expected.emplace_back(make_pair("[-3; -2.4)",""));
    expected.emplace_back(make_pair("[-2.4; -1.8)",""));
    expected.emplace_back(make_pair("[-1.8; -1.2)",""));
    expected.emplace_back(make_pair("[-1.2; -0.6)",""));
    expected.emplace_back(make_pair("[-0.6; 0)",""));
    expected.emplace_back(make_pair("[0; 0.6)",""));
    expected.emplace_back(make_pair("[0.6; 1.2)",""));
    expected.emplace_back(make_pair("[1.2; 1.8)",""));
    expected.emplace_back(make_pair("[1.8; 2.4)",""));
    expected.emplace_back(make_pair("[2.4; 3]",""));

    ASSERT_EQ(expected, test);

    test.clear();
    expected.clear();
    addLore(test, 0, 1, 0.1);

    expected.emplace_back(make_pair("[0; 0.1)",""));
    expected.emplace_back(make_pair("[0.1; 0.2)",""));
    expected.emplace_back(make_pair("[0.2; 0.3)",""));
    expected.emplace_back(make_pair("[0.3; 0.4)",""));
    expected.emplace_back(make_pair("[0.4; 0.5)",""));
    expected.emplace_back(make_pair("[0.5; 0.6)",""));
    expected.emplace_back(make_pair("[0.6; 0.7)",""));
    expected.emplace_back(make_pair("[0.7; 0.8)",""));
    expected.emplace_back(make_pair("[0.8; 0.9)",""));
    expected.emplace_back(make_pair("[0.9; 1]",""));

    ASSERT_EQ(expected, test);
}


TEST_F(RandomGeneratorUnitTest, Valuetest) {
    //addValues();
    mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
    vector<pair<string, string>> test;
    addLore(test, 0, 1, 0.1);
    vector<double> values;
    values.reserve(10000);
    for (int i = 0; i < 10000; i++) {
        values.emplace_back((double)(rnd() - mt19937::min()) / (mt19937::max() - mt19937::min() + 1));
    }
    addValues(test, values, 0, 0.1);
    for (const auto& it : test) {
        ASSERT_GT(it.second.substr(0, 4), "0.085");
        ASSERT_LT(it.second.substr(0, 4), "0.115");
    }
}






