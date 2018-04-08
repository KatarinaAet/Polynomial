#include "polynomial.h"
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;
const int N = 10;

Polynomial::Polynomial(int N, double *arr)
{
    polPower = N+1;
    polCoef = new double[polPower+1];
    memcpy(polCoef, arr, sizeof(double)*polPower);
}

Polynomial::Polynomial(const Polynomial &obj)
{
    polCoef = new double[obj.polPower];
    for (int i = 0; i < obj.polPower; i++)
        polCoef[i] = obj.polCoef[i];
    polPower = obj.polPower;

}

Polynomial& Polynomial::operator =(const Polynomial& other)
{
    if (this != &other){
        delete [] polCoef;
        polCoef = new double[other.polPower];
        memcpy(polCoef, other.polCoef, sizeof(double)*(other.polPower));
    }
    return *this;
}

Polynomial::~Polynomial()
{
        delete[]polCoef;
}

double Polynomial::operator()(double x) const{
    double res = 0.0;
    for (int i = 0; i < polPower; i++){
        res+=polCoef[i]*pow(x,i);
    }
    return (double)res;
}

double& Polynomial::operator[](int y) const{
    /*if (y > polPower-1 || y < 0){
        cout << "Invalid input"<< endl;
        return 0;}
     else*/
    return polCoef[y];
}

void Polynomial::show() const
{
    for (int i = polPower-1; i > 0; i--)
        cout << polCoef[i] << "*x^" << i <<" + ";
    cout << polCoef[0];
}

bool Polynomial::check(double x) const
{
    return true;
}

void Polynomial::show_not_def(double x) const
{

}

