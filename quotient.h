#ifndef QUOTIENT_H
#define QUOTIENT_H
#include "polynomial.h"
#include "function.h"

class Quotient : public Function
{
public:
    Polynomial *numerator;
    Polynomial *denominator;
    Quotient(Polynomial *polin_1, Polynomial *polin_2) : numerator(polin_1), denominator(polin_2){}
    double operator()(double x) const;
    void show() const;
    bool check(double x) const;
    void show_not_def(double x) const;
};

#endif // QUOTIENT_H
