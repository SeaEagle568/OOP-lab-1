//
// Created by seaeagle on 07.09.21.
//

#ifndef LAB1_ISTRATEGY_H
#define LAB1_ISTRATEGY_H
#include<bits/stdc++.h>

class IStrategy {
public:
    double nextNumber();

    double nextNumber(double lower, double upper);

    virtual ~IStrategy() = default;

    virtual int nextInt() = 0;

    virtual std::string getName() = 0;

private:
    virtual void updatePrev(int newNumber) = 0;
    virtual int getM() = 0;
};


#endif //LAB1_ISTRATEGY_H
