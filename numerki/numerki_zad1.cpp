//
// Kamil Jóźwicki, Kacper Komorowski
//
#include <iostream>
#include "functions.h"
#define GNUPLOT_PATH "C:\\ProgramFiles\\gnuplot\\bin"

using namespace std;

int main (){
    double E,x0,fa,fb,w,a,b;
    int i=0,M;
    cout<<"Podaj wartosc w: ";
    cin>>w;
    choice(w);
    range(a,b);
    method(i, E);
    cout<<"Wynik po skorzystaniu z metody bisekcji: "<<bisection(a,b,E,i,M)<<"\n";
    cout<<"Wynik po skorzystaniu z regula Falsi: "<<regulaFalsi(a,b,E,i,M);
    return 0;
}