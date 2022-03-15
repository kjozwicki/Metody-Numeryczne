//
// Kamil Jóźwicki, Kacper Komorowski
//
#include <iostream>
#include "functions.h"
#include "choice.h"
#include "count.h"

using namespace std;

int main (){

    cout<<"Program wykonujacy obliczenia na funkcjach"<<endl;
    double wartosc_x, potega=0;
    cout<<"Podaj wartosc x:";
    cin>>wartosc_x;
    int ilosc_zlozen, wybor_funkcji[ilosc_zlozen], stopien, wspolczynniki[stopien], wolny=0;
    wybor_funkcji[ilosc_zlozen] = choice(wybor_funkcji, ilosc_zlozen, potega, wspolczynniki, stopien, wolny);
    count(ilosc_zlozen, wybor_funkcji, wartosc_x, potega, wspolczynniki, stopien, wolny);
    cout<<"Wartosc funkcji dla podanego x: "<<wartosc_x<<endl;
    cout<<endl;

    double epsilon=0, granica_dolna,granica_gorna;
    int iteracja=0;
    range(granica_dolna, granica_gorna);
    method(iteracja, epsilon);
    double x0 = bisection(granica_dolna,granica_gorna,epsilon,iteracja,wybor_funkcji,ilosc_zlozen,potega, wspolczynniki, stopien, wolny);
    cout<<"Wynik po skorzystaniu z metody bisekcji: "<<x0<< "\n";
    double x1 = regulaFalsi(granica_dolna,granica_gorna,epsilon,iteracja,wybor_funkcji,ilosc_zlozen,potega, wspolczynniki, stopien, wolny);
    cout<<"Wynik po skorzystaniu z regula Falsi: "<<x1;

    wykresy(granica_dolna,granica_gorna,x0, x1, ilosc_zlozen, wybor_funkcji, potega, wspolczynniki, stopien, wolny);

    return 0;
}