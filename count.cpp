//
// Created by Kamil on 15.03.2022.
//

#include "count.h"
#include "functions.h"
#include <iostream>
#include "cmath"

using namespace std;

int * count(int &ilosc_zlozen, int wybor_funkcji[], double &wartosc_x) {
    int iteracje=0, stopien, potega;
    double wolny=0;
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
            cout<< "Podaj stopien wielomianu: ";
            cin >> stopien;
            int wspolczynniki [stopien];
            cout<< "Podaj wspolczynniki od najwyzszego stopnia do najmniejszego: ";
            for (int z=0; z < stopien; z++) {
                cin>>wspolczynniki[z];
            }
            cout<< "Podaj wyraz wolny: ";
            cin >> wolny;
            for (int z=stopien,i=0; z > 0; z--,i++) {
                cout << wspolczynniki[i];
                cout<<"x^";
                cout<<z;
                cout<<" + ";
            }
            cout<<wolny;
            cout<<endl;
            wartosc_x=horner(wartosc_x, wspolczynniki, stopien);
        } else if (wybor_funkcji[iteracje] == 5) {
            iteracje++;
            double s=wartosc_x;
            cout<<"Podaj do ktorej potegi podniesc liczbe: ";
            cin >> potega;
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


