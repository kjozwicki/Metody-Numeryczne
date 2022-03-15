//
// Kamil Jóźwicki, Kacper Komorowski
//

#include "functions.h"
#include <iostream>
#include <cmath>

using namespace std;

int choice (double wartosc_x) {
    int wybor,stopien,m,p,i=1;
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
            i++;
            wartosc_x=sin(wartosc_x);
        } else if (wybor == 2) {
            i++;
            wartosc_x=cos(wartosc_x);
        } else if (wybor == 3) {
            i++;
            wartosc_x=tan(wartosc_x);
        } else if (wybor == 4) {
            i++;
            cout<< "Podaj stopien wielomianu: ";
            cin >> stopien;
            int wspolczynniki [stopien];
            cout<< "Podaj wspolczynniki od najwyzszego stopnia do najmniejszego: ";
            for (int z=0; z < stopien; z++) {
                cin>>wspolczynniki[z];
            }
            for (int z=stopien,i=0; z > 0; z--,i++) {
                cout << wspolczynniki[i];
                cout<<"wybor^";
                cout<<z;
                if ( z >1 )
                    std::cout<<" + ";
            }
            cout<<endl;
            wartosc_x=horner(wartosc_x, wspolczynniki, stopien);
        } else if (wybor == 5) {
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
    i=0;
    while((i<m)&&(acc>E)) {
        fa = choice(a);
        x0 = (a + b) / 2.0;
        fx0 = choice(x0);
        if (fa * fx0 < 0)
            b = x0;
        else
            a = x0;
        i++;
        acc = fabs(fx0);
        cout << x0 << "\n";
        cout << choice(x0) << "\n";
    }
    cout<<"Wynik po skorzystaniu z metody bisekcji: "<<x0<< "\n";
    return x0;
}
double regulaFalsi(double a, double b, double &E, int &i, int m){
    double acc, fa, fb, x0, fx0;
    i=0;
    while((i<m)&&(acc>E))
    {
        fa=choice(a);
        fb=choice(b);
        x0=(a*fb - b*fa)/(fb-fa);
        fx0=choice(x0);
        if(fa*fx0<0)
            b=x0;
        else
            a=x0;
        i++;
        acc=fabs(fx0);
    }
    cout<<"Wynik po skorzystaniu z regula Falsi: "<<x0;
    return x0;
}
