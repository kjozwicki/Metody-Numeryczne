//
// Created by Kamil on 15.03.2022.
//

#include "count.h"
#include <iostream>
#include "functions.h"

using namespace std;

int choice(int wybor_funkcji[], int &ilosc_zlozen) {
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
    }
    cout<<"----------"<<endl;
    return wybor_funkcji, ilosc_zlozen;
}