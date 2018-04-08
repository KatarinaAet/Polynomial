#ifndef FUNCTION_H
#define FUNCTION_H


class Function
{
public:
    virtual double operator() (double x) const = 0;
    virtual void show() const = 0;
    virtual bool check(double x) const = 0;
    virtual void show_not_def(double x) const = 0;
};

#endif // FUNCTION_H
