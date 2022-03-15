//
// Created by Kamil on 15.03.2022.
//

#include "count.h"
#include "functions.h"
#include <iostream>
#include "cmath"

using namespace std;

int * count(int &ilosc_zlozen, int wybor_funkcji[], double &wartosc_x, double &potega, int wspolczynniki[], int &stopien, int &wolny) {
    int iteracje=0;
    while(iteracje < ilosc_zlozen) {
        if (wybor_funkcji[iteracje] == 1) {
            iteracje++;
            wartosc_x=sin(wartosc_x);
        } else if (wybor_funkcji[iteracje] == 2) {
            iteracje++;
            wartosc_x=cos(wartosc_x);
        } else if (wybor_funkcji[iteracje] == 3) {
            iteracje++;
            wartosc_x=tan(wartosc_x);
        } else if (wybor_funkcji[iteracje] == 4) {
            iteracje++;
            wartosc_x=horner(wartosc_x, wspolczynniki, stopien);
        } else if (wybor_funkcji[iteracje] == 5) {
            iteracje++;
            double s=wartosc_x;
            if(potega==0) wartosc_x=1;
            else {
                for (int k = 1; k < potega; k++) {
                    wartosc_x = wartosc_x * s;
                }
                cout << s << "^" << potega;
            }
        }
    }
    cout<<endl;
    return wybor_funkcji;
}


