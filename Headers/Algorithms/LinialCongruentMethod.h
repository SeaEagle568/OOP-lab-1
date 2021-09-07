//
// Created by seaeagle on 07.09.21.
//

#ifndef LAB1_LINIALCONGRUENTMETHOD_H
#define LAB1_LINIALCONGRUENTMETHOD_H


#include "../IStrategy.h"

class LinialCongruentMethod : public IStrategy {
public:
    double nextNumber(double lower, double upper) override;

    double nextNumber() override;
};


#endif //LAB1_LINIALCONGRUENTMETHOD_H
