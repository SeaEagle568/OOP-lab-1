//
// Created by seaeagle on 07.09.21.
//

#ifndef LAB1_ISTRATEGY_H
#define LAB1_ISTRATEGY_H
#include<bits/stdc++.h>

class IStrategy {
public:

    virtual double nextNumber() = 0;
    virtual double nextNumber(double lower, double upper) = 0;

    virtual ~IStrategy() = default;
};


#endif //LAB1_ISTRATEGY_H
