//
// Created by seaeagle on 16.09.21.
//

#include "../include/Algorithms/Utils.h"

vector<ll> Utils::factorize(ll n) {
    vector<ll> answer;
    for (ll i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            answer.emplace_back(i);
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) answer.emplace_back(n);
    return answer;
}

ll Utils::binpow(ll base, ll n, ll mod) {
    ll res = 1;
    while (n) {
        if (n & 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        n =  (n >> 1) % mod;
    }
    return static_cast<int>(res % mod);
}

ll Utils::phi(ll n) {
    ll result = n;
    for (ll i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0){
                n /= i;
            }
            result -= result / i;
        }
    }
    if (n > 1) {
        result -= result / n;
    }

    return result;
}

