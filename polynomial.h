#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include "function.h"

class Polynomial : public Function
{
    int id;
    long int polPower;
    double *polCoef;
public:
    Polynomial(int N, double *arr);
    Polynomial(const Polynomial &obj);
    Polynomial& operator = (const Polynomial &other);
    ~Polynomial();
    double get_polPower() const { return polPower; }
    double* get_polCoef() const { return polCoef; }
    double operator()(double x) const;
    double& operator[](int y) const;
    void show() const;
    bool check(double x) const;
    void show_not_def(double x) const;
};

#endif // POLYNOMIAL_H
