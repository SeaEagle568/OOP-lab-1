//
// Created by seaeagle on 07.09.21.
//

#ifndef LAB1_ISTRATEGY_H
#define LAB1_ISTRATEGY_H


class IStrategy {
public:
    virtual double nextNumber() = 0;

    double nextNumber(double lower, double upper);

    virtual ~IStrategy() = default;
};


#endif //LAB1_ISTRATEGY_H
