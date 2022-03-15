//
// Kamil Jóźwicki, Kacper Komorowski
//

#include "functions.h"
#include <iostream>
#include <cmath>
#include <vector>
#include "count.h"
#include "gnuplot.h"
#include "vector"
#define GNUPLOT_PATH "C:\\minGW\\gnuplot\\bin"
std::string funkcja1;
std::vector<std::string> funkcja2;
using namespace std;

double one_more_time(double x) {
    while( x <= 0 ) {
        cout << "Podano zly numer, podaj jeszcze raz \n";
        cin >> x;
    }
    return x;
}

double horner(double wartosc_x, int T[], int stopien)
{
    int suma = T[0];
    for(int i=1;i<=stopien;i++)
        suma = suma * wartosc_x + T[i];
    return suma;
}
void range(double &a, double &b){
    cout<<"Podaj na jakim przedziale bedzie szukane miejsce zerowe (a,b).\n";
    cout<<"a=";
    cin>>a;
    cout<<"b=";
    cin>>b;
}
void method(int &i, double &E){
    iterations(i);
    epsilon(E);
}
void iterations(int &i){
    cout<<"Ile iteracji ma wykonac program:";
    cin>>i;
    one_more_time(i);
}
void epsilon(double &E){
    cout<<"Podaj epsilon:";
    cin>>E;
    one_more_time(E);
}
double bisection(double a, double b, double &E, int &i, int wybor_funkcji[], int ilosc_zlozen, double &potega, int wspolczynniki[], int &stopien, int &wolny){
        double acc, fa, x0, fx0;
        int rep=0;
        do {
            fa = a;
            count(ilosc_zlozen, wybor_funkcji, fa, potega, wspolczynniki, stopien, wolny);
            x0 = (a + b) / 2.0;
            fx0 = x0;
            count(ilosc_zlozen, wybor_funkcji, fx0, potega, wspolczynniki, stopien, wolny);
            if (fa * fx0 < 0)
                b = x0;
            else
                a = x0;
            i++;
            acc = fabs(fx0);
        }
        while((rep<i)&&(acc>E));
        return x0;
}
double regulaFalsi(double a, double b, double &E, int &i, int wybor_funkcji[], int ilosc_zlozen, double &potega, int wspolczynniki[], int &stopien, int &wolny) {
    double acc, fa, fb, x0, fx0;
        int rep=0;
        do {
            fa=a;
            fb=b;
            count(ilosc_zlozen, wybor_funkcji, fa, potega, wspolczynniki, stopien, wolny);
            count(ilosc_zlozen, wybor_funkcji, fb, potega, wspolczynniki, stopien, wolny);
            x0 = (a * fb - b * fa) / (fb - fa);
            fx0 = x0;
            count(ilosc_zlozen, wybor_funkcji, fx0, potega, wspolczynniki, stopien, wolny);
            if (fa * fx0 < 0)
                b = x0;
            else
                a = x0;
            i++;
            acc = fabs(fx0);
        }
        while((rep<i)&&(acc>E));
        if (x0 == -0)
            x0 = 0;
        return x0;
}
void wykresy(double a, double b, double x0, double x1,int ilosc_zlozen,int wybor_funkcji[],double &potega,int wspolczynniki[],int &stopien,int &wolny) {
   Gnuplot::set_GNUPlotPath( GNUPLOT_PATH );
   Gnuplot main_plot;

    main_plot.set_xlabel("Os x");
    main_plot.set_ylabel("Os y");
    main_plot.set_grid();
    main_plot.set_xrange(a, b);
    main_plot.set_yrange(-100, 100);
    main_plot.set_style("lines");
    main_plot.set_pointsize(2);

    vector<double> x;
    vector<double> y;
    vector<double> bisekcjazero;
    vector<double> falsizero;
    vector<double> zero;
    zero.push_back(0);
    falsizero.push_back(x1);
    bisekcjazero.push_back(x0);
    for(double i=a; i<b; i+=0.1) {
        x.push_back(i);
        double pom_i=i;
        count(ilosc_zlozen, wybor_funkcji, pom_i, potega, wspolczynniki, stopien, wolny);
        y.push_back(pom_i);
    }
    main_plot.plot_xy(x, y, "f(x)" );
    main_plot.plot_xy(bisekcjazero, zero, "bisekcja");
    main_plot.plot_xy(falsizero,zero, "falsi");
    system("cls");
    system("pause");
}
