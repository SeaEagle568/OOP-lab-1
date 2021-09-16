#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2")
#include<bits/stdc++.h>
#include "include/IStrategy.h"
#include "include//Algorithms/LinealCongruentialMethod.h"
#include "include/RandomGenerator.h"
#include "include/Algorithms/QuadraticCongruentialMethod.h"
#include "include/Algorithms/FibonacciMethod.h"
#include "include/Algorithms/InverseCongruentialMethod.h"
#include "include/Algorithms/Utils.h"


using namespace std;

int main()
{
    IStrategy *method = new InverseCongruentialMethod(2281488, true, true);

    RandomGenerator generator(method);

    auto distribution = generator.getDistribution(0, 1, 0.1, 100000);

    for (const auto& it : distribution) {
        cout << it.first << " --- " << it.second << endl;
    }


}