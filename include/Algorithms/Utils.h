//
// Created by seaeagle on 16.09.21.
//

#ifndef LAB1_UTILS_H
#define LAB1_UTILS_H
#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Utils {
public:
    static vector<ll> factorize(ll n);
    static ll binpow(ll base, ll n, ll mod);
    static ll phi(ll n);
    static ll mmod(ll x, ll m);
    static ll modmin(ll x, ll y, ll m);
};


#endif //LAB1_UTILS_H
