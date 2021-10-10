//
// Created by seaeagle on 28.09.21.
//

#ifndef LAB1_IUNIFORMSTRATEGY_H
#define LAB1_IUNIFORMSTRATEGY_H
#include<bits/stdc++.h>
#include "IStrategy.h"

using namespace std;

class IUniformStrategy: public IStrategy{

public:
    virtual std::string getName() = 0;
    virtual int nextInt() = 0;
    double nextNumber() override;
    double nextNumber(double lower, double upper) override;
private:
    virtual void updatePrev(int newNumber) = 0;
    virtual int getM() = 0;
};


#endif //LAB1_IUNIFORMSTRATEGY_H
