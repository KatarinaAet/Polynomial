#include "quotient.h"
#include "polynomial.h"
#include <iostream>

using namespace std;

double Quotient::operator ()(double x) const
{
    double num_r = (*numerator)(x);
    double dem_r = (*denominator)(x);
    if (dem_r == 0 && num_r != 0){
        return 0;
    }
    else
        return (double)num_r/dem_r;
}

void Quotient::show() const
{
    numerator->show();
    cout << " / ";
    denominator->show();
}

bool Quotient::check(double x) const
{
    double num_r = (*numerator)(x);
    double dem_r = (*denominator)(x);
    if ((num_r == 0) && (dem_r == 0))
            return false;
    if ((dem_r == 0))
        return false;
    else
        return true;

}

void Quotient::show_not_def(double x) const
{
    if (!check(x)){
        cout << "(" << (*numerator)(x) << ")" << " / " << "(" << (*denominator)(x) << ")" << endl;
    }

}
