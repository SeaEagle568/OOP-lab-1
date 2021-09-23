#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2")

#include<bits/stdc++.h>
#include "include/IStrategy.h"
#include "include/RandomGenerator.h"
#include "include/Algorithms/algorithms.h"

using namespace std;

int main() {
    IStrategy *method = UnityMethod::getUnityMethod(true, true);
    // IStrategy *method = new QuadraticCongruentialMethod(420, true, true);
    /*for (int i = 0; i <= 10; i++) {
        cout << method->nextInt() << endl;
    }
     */
    RandomGenerator generator(method);

    auto distribution = generator.getDistribution(0, 1, 0.1, 100000);

    for (const auto &it: distribution) {
        cout << it.first << " --- " << it.second << endl;
    }

}