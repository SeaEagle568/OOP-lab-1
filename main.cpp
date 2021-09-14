#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2")
#include<bits/stdc++.h>
#include "include/IStrategy.h"
#include "include//Algorithms/LinialCongruentialMethod.h"
#include "include/RandomGenerator.h"
#include "include/Algorithms/QuadraticCongruentialMethod.h"
#include "include/Algorithms/FibonacciMethod.h"

#define cdbg cerr << "Debug in " << __func__ << ", " << __LINE__ << ": "
#define q <<  '\n'
#define ld long double
#define ll long long



using namespace std;

int main()
{

    IStrategy *method = new FibonacciMethod(228,1488);

    RandomGenerator generator(method);

    auto distribution = generator.getDistribution(-1, 1, 0.1, 100000);

    for (const auto& it : distribution) {
        cout << it.first << " --- " << it.second << endl;
    }


}