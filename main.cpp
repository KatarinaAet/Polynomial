#include <iostream>
#include <cstring>
#include "polynomial.h"
#include "quotient.h"
#include <assert.h>
#include "function.h"
#include "storage.h"

using namespace std;

int main()
{
    int N;
    int choice;
    do {
    cout << "Enter:\n1-for calculating the meaning of polynomial in point\n2-for calculating rational function\n3-for testing\n4-for working with list(with ready input)\nany other - for quitting\n";
    cin >> choice;
    switch (choice){
    case 1:
    {
        do {
            cout << "Enter the polynomial power, less than 10" << endl;
            cin >> N;
        } while (N >= 10 || N < 0);
        double* arr = new double[N+1];
        cout << "Enter the coef polynomial, beginning from the zero power" << endl;
        for (int i = 0; i <= N; i++)
            cin >> arr[i];
        Polynomial pol(N,arr);
        int y;
        double x;
        cout << "Enter the point, which you want to calculate the polynomial in" << endl;
        cin >> x;
        cout << "Your result:" << endl;
        cout << pol(x) << endl;
        cout << "i'm here" << endl;
        cout << "Enter the power, where you want to know the coefficient:" << endl;
        cout << "i'm here too" << endl;
        cin >> y;
        cout << "Your result:" << endl;
        cout << pol[y] << endl;
        break;

    }
    case 2:
    {
        int K;
        do {
            cout << "Enter the numerator's power, less than 10" << endl;
            cin >> N;
        } while (N >= 10 || N < 0);
        cout << "Enter the numerator's coefficiences, beginning from the zero power" << endl;
        double* arr_2 = new double[N+1];
        for (int i = 0; i <= N; i++)
            cin >> arr_2[i];
        Polynomial *ppol_2 = new Polynomial(N, arr_2);
        do {
            cout << "Enter the denominator's power, less than 10" << endl;
            cin >> K;
        } while (K >= 10 || K < 0);
        cout << "Enter the denominator's coefficiences, beginning from the zero power" << endl;
        double* arr_3 = new double[K+1];
        for (int i = 0; i <= K; i++)
            cin >> arr_3[i];
        Polynomial *ppol_3 = new Polynomial (N, arr_3);
        Quotient quo(ppol_2,ppol_3);
        cout << "Enter the point which you want to calculate the polynomial in" << endl;
        double x0;
        cin >> x0;
        cout << "Your result:" << endl;
        cout << quo(x0) << endl;
        break;
    }
    case 3:
    {
        cout << "Some Tests!" << endl;
        double arr_t[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        Polynomial pol_t(9, arr_t);
        assert(pol_t(1) == 55);
        assert(pol_t(2) == 9217);
        assert(pol_t[1] == 2);
        assert(pol_t[3] == 4);
        assert(pol_t[4] == 5);
        assert(pol_t.check(1) == 1);
        cout << "Set #1 of tests has successfully finished!" << endl;
        double arr_t2[6] = {2, 2, 2, 2, 2, 2};
        double arr_t3[4] = {1, 1, 1, 1};
        Quotient quo_t(new Polynomial(5, arr_t2), new Polynomial(3, arr_t3));
        assert(quo_t(1) == 3);
        assert(quo_t(2) == 8.4);
        assert(quo_t(-3) == 18.2);
        assert(quo_t.check(1) == 1);
        assert(quo_t.check(-1) == 0);
        cout << "Set #2 of tests has successfully finished!" << endl;
        Storage store_t;
        store_t.Add(new Polynomial(9,arr_t));
        assert(store_t.Count() == 1);
        assert(store_t.operator ()(1.0) == 55);
        store_t.Add(&quo_t);
        assert(store_t.Count() == 2);
        cout << "Set #3 of tests has successfully finished!" << endl;
        break;

    }
    case 4:
    {
        double arr_t[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        Storage store;
        store.Add(new Polynomial(9,arr_t));
        double arr_t2[6] = {2, 2, 2, 2, 2, 2};
        double arr_t3[4] = {1, 1, 1, 1};
        double arr_t4[3] = {1, 2, 6};
        double arr_t5[4] = {5, 5, 5, 5};
        store.Add(new Polynomial(5, arr_t2));
        Quotient quo_t(new Polynomial(5, arr_t2), new Polynomial(3, arr_t3));
        store.Add(&quo_t);
        Quotient quo_t2(new Polynomial(2, arr_t4), new Polynomial(3, arr_t5));
        store.Add(&quo_t2);
        cout << "Showing created list" << endl;
        store.show();
        cout << store.Count() << endl;
        cout << "Calculating:" << endl;
        store.operator ()(-1.0);
        break;
  }

}

    }
    while (choice > 0 && choice <= 4);
}
