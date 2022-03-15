//
// Kamil Jóźwicki, Kacper Komorowski
//

#include "functions.h"
#include <iostream>
#include <cmath>
#include "gnuplot.h"
#define GNUPLOT_PATH "C:\\minGW\\gnuplot\\bin"
std::string funkcja1;
std::vector<std::string> funkcja2;
using namespace std;

int choice (double wartosc_x) {
    int stopien,m,wybor,p,i=1;
    double wolny=0;
    cout<<"Ile zlozen funcji wykonac: ";
    cin>>m;
    while(i<=m) {
        cout<<"----------"<<endl;
        cout
                << "Wybierz funkcje: \n1.Sinus \n2.Cosinus \n3.Tanges \n4.Funcja wielomianowa \n5.Funcja wykladnicza \nWybor:  ";
        cin >> wybor;
        cout<<"----------"<<endl;
        if (wybor > 5 || wybor < 1) cout << "Podano zly numer, podaj jeszcze raz \n";
        else if (wybor == 1) {
            funkcja1="sinus";
            i++;
            wartosc_x=sin(wartosc_x);
        } else if (wybor == 2) {
            funkcja1="cosinus";
            i++;
            wartosc_x=cos(wartosc_x);
        } else if (wybor == 3) {
            funkcja1="tanges";
            i++;
            wartosc_x=tan(wartosc_x);
        } else if (wybor == 4) {
            funkcja1="wielomianowa";
            i++;
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
                std::cout<<" + ";
            }
            std::cout<<wolny;
            cout<<endl;
            wartosc_x=horner(wartosc_x, wspolczynniki, stopien);
        } else if (wybor == 5) {
            funkcja1="wykladnicza";
            i++;
            double s=wartosc_x;
            cout<<"Podaj do ktorej potegi podniesc liczbe: ";
            cin >> p;
            if(p==0) wartosc_x=1;
            else {
                for (int k = 1; k < p; k++) {
                    wartosc_x = wartosc_x * s;
                }
                cout << s << "^" << p;
            }
        }
    }
    cout<<endl;
    funkcja2.push_back(&wartosc_x);
    cout << "Wynik: " << wartosc_x <<endl;
    return wartosc_x;
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
    int m;
    cout<<"\nPodaj z czego korzystac przy szukaniu miejsca zerowego \n1.Liczba iteracji \n2.Podany epsilon "<<endl;
    cin>>m;
    if(m!=1&&m!=2)    cout<<"Podano zly numer\n";
    else if (m == 1) iterations(i);
    else if (m == 2)  epsilon(E);
}
void iterations(int &i){
    cout<<"Ile iteracji ma wykonac program:";
    cin>>i;
}
void epsilon(double &E){
    cout<<"Podaj epsilon:";
    cin>>E;
}
double bisection(double a, double b, double &E, int &i, int m){
        double acc, fa, x0, fx0;
        int rep=0;
        do {
            fa = choice(a);
            x0 = (a + b) / 2.0;
            fx0 = choice(x0);
            if (fa * fx0 < 0)
                b = x0;
            else
                a = x0;
            i++;
            acc = fabs(fx0);
        }
        while((rep<i)&&(acc>E));
        cout<<"Wynik po skorzystaniu z metody bisekcji: "<<x0<< "\n";
        return x0;
}
double regulaFalsi(double a, double b, double &E, int &i, int m){
        double acc, fa, fb, x0, fx0;
        int rep=0;
        do {
            fa = choice(a);
            fb = choice(b);
            x0 = (a * fb - b * fa) / (fb - fa);
            fx0 = choice(x0);
            if (fa * fx0 < 0)
                b = x0;
            else
                a = x0;
            i++;
            acc = fabs(fx0);
        }
        while((rep<i)&&(acc>E));
        cout<<"Wynik po skorzystaniu z regula Falsi: "<<x0;
        return x0;
}
void wykresy(double a, double b, double &E, int &i, int m, double wartosc_x) {
    //wykresy
    Gnuplot::set_GNUPlotPath( GNUPLOT_PATH );
    Gnuplot main_plot;

    // Podpisy na wykresie, zeby bylo wiadomo co na nim widac
    main_plot.set_title( "Funkcja"+funkcja1);

    // styl rysowania wykresu
    main_plot.set_style( "lines" );

    // siatka poprawia czytelnosc
    main_plot.set_grid();

    // zakres osi x
    main_plot.set_xrange( a , b ) ;

    // funkcja do narysowania
    // UWAGA: poniższy przykład służy jedynie zademonstrowaniu, że gnuplot jest w
    // stanie rysować wykresy na podstawie wzoru funkcji. Proszę jednak pamiętać,
    // że zgodnie z wytycznymi zamieszczonymi na Wikampie nie wolno z tej
    // możliwości korzystać. Dane do wykresu zawsze należy przekazywać w tablicy -
    // przykład poniżej.
    main_plot.plot_equation( funkcja2 ) ;

    // teraz narsujemy kilka punktow. Na poczatek zmiana stylu rysowania:
    main_plot.set_style( "points" );
    main_plot.set_pointsize( 2.0 );

    // Tworzenie danych do wykresu. Potrzebne sa dwa wektory STL. Jeden opisuje
    // polozenie punktow na osi X, drugi na osi Y. W rzeczywistym programie
    // dane nie beda oczywiscie wpisywane na sztywno w kodzie, a wyliczane w oparciu
    // o parametry wprowadzone przez uzytkownika.
    main_plot.plot_xy( bisection(a,b,E,i,m), regulaFalsi(a,b,E,i,m), "podpis - opcjonalnie" );

    // czekamy na nacisniecie klawisza Enter
    getchar();
}
