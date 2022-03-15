//
// Kamil Jóźwicki, Kacper Komorowski
//
#include <iostream>
#include "functions.h"

using namespace std;

int main (){

    //glowne funkcje
    double E,x0,fa,fb,wartosc_x,a,b;
    int i=0,M;
    cout<<"Podaj wartosc x:";
    cin >> wartosc_x;
    choice(wartosc_x);
    range(a,b);
    method(i, E);
    bisection(a,b,E,i,M);
    regulaFalsi(a,b,E,i,M);
    wykresy(a,b,E,i,M, wartosc_x);
    return 0;
}