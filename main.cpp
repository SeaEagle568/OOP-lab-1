#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2")
#include<bits/stdc++.h>
#include "Headers/IStrategy.h"
#include "Headers/Algorithms/LinialCongruentMethod.h"

#define cdbg cerr << "Debug in " << __func__ << ", " << __LINE__ << ": "
#define q <<  '\n'
#define ld long double
#define ll long long



using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    IStrategy *test = new LinialCongruentMethod();



}