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
    bisection(a,b,E,i,M);
    regulaFalsi(a,b,E,i,M);
    return 0;
}