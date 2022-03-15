//
// Created by Kamil on 15.03.2022.
//

#include "count.h"
#include <iostream>
#include "functions.h"

using namespace std;

int choice(int wybor_funkcji[], int &ilosc_zlozen, double &potega, int wspolczynniki[], int &stopien, int &wolny) {
    cout<<"Ile zlozen funcji wykonac: ";
    cin>>ilosc_zlozen;
    one_more_time(ilosc_zlozen);
    cout<<"----------"<<endl;
    cout<< "Wybierz funkcje: \n1.Sinus \n2.Cosinus \n3.Tanges \n4.Funcja wielomianowa \n5.Funcja wykladnicza \nWybor:  ";
    for (int i=0;i<ilosc_zlozen;i++) {
        cin >> wybor_funkcji[i];
        while( wybor_funkcji[i] > 5 || wybor_funkcji[i] < 1 ) {
            cout << "Podano zly numer, podaj jeszcze raz \n";
            cin >> wybor_funkcji[i];
        }
        if(wybor_funkcji[i] == 5) {
            cout << "Podaj potege";
            cin >> potega;
        }
        if(wybor_funkcji[i] ==4) {
            cout<< "Podaj stopien wielomianu: ";
            cin >> stopien;
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
        }
    }
    cout<<"----------"<<endl;
    return wybor_funkcji, ilosc_zlozen;
}