//
// Kamil Jóźwicki, Kacper Komorowski
//

#include "functions.h"
#include <iostream>
#include <cmath>
#include <vector>
#include "count.h"
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
double regulaFalsi(double a, double b, double &E, int &i, int wybor_funkcji[], int ilosc_zlozen, double &potega, int wspolczynniki[], int &stopien, int &wolny){
        double acc, fa, fb, x0, fx0;
        int rep=0;
        do {
            count(ilosc_zlozen, wybor_funkcji, a, potega, wspolczynniki, stopien, wolny);
            count(ilosc_zlozen, wybor_funkcji, b, potega, wspolczynniki, stopien, wolny);
            x0 = (a * fb - b * fa) / (fb - fa);
            fx0 =x0;
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
//void wykresy(double a, double b, double &E, int &i, int m, double wartosc_x) {
//    //wykresy
////    Gnuplot::set_GNUPlotPath( GNUPLOT_PATH );
////    Gnuplot main_plot;
//
//    // Podpisy na wykresie, zeby bylo wiadomo co na nim widac
//    main_plot.set_title( "Funkcja"+funkcja1);
//
//    // styl rysowania wykresu
//    main_plot.set_style( "lines" );
//
//    // siatka poprawia czytelnosc
//    main_plot.set_grid();
//
//    // zakres osi x
//    main_plot.set_xrange( a , b ) ;
//
//    // funkcja do narysowania
//    // UWAGA: poniższy przykład służy jedynie zademonstrowaniu, że gnuplot jest w
//    // stanie rysować wykresy na podstawie wzoru funkcji. Proszę jednak pamiętać,
//    // że zgodnie z wytycznymi zamieszczonymi na Wikampie nie wolno z tej
//    // możliwości korzystać. Dane do wykresu zawsze należy przekazywać w tablicy -
//    // przykład poniżej.
////    main_plot.plot_equation( funkcja2 ) ;
//
//    // teraz narsujemy kilka punktow. Na poczatek zmiana stylu rysowania:
//    main_plot.set_style( "points" );
//    main_plot.set_pointsize( 2.0 );
//
//    // Tworzenie danych do wykresu. Potrzebne sa dwa wektory STL. Jeden opisuje
//    // polozenie punktow na osi X, drugi na osi Y. W rzeczywistym programie
//    // dane nie beda oczywiscie wpisywane na sztywno w kodzie, a wyliczane w oparciu
//    // o parametry wprowadzone przez uzytkownika.
////    main_plot.plot_xy( bisection(a,b,E,i,m), regulaFalsi(a,b,E,i,m), "podpis - opcjonalnie" );
//
//    // czekamy na nacisniecie klawisza Enter
//    getchar();
//}
