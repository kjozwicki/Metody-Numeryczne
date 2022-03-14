//
// Kamil Jóźwicki, Kacper Komorowski
//

#include "functions.h"
#include <iostream>
#include <cmath>

using namespace std;

int choice (double w) {
    int x,s,m,p,i=1;
    cout<<"Ile zlozen funcji wykonac: ";
    cin>>m;
    while(i<=m) {
        cout
                << "Wybierz funkcje: \n1.Sinus \n2.Cosinus \n3.Tanges \n4.Funcja wielomianowa \n5.Funcja wykladnicza \nWybor:  ";
        cin >> x;
        if (x > 5 || x < 1) cout << "Podano zly numer, podaj jeszcze raz \n";
        else if (x == 1) {
            i++;
            w=sin(w);
        } else if (x == 2) {
            i++;
            w=cos(w);
        } else if (x == 3) {
            i++;
            w=tan(w);
        } else if (x == 4) {
            i++;
            cout<< "Podaj stopien wielomianu: ";
            cin >> s;
            int wspolczynniki [s];
            cout<< "Podaj wspolczynniki od najwyzszego stopnia do najmniejszego: ";
            for (int z=0;z<s;z++) {
                cin>>wspolczynniki[z];
            }
            for (int z=s,i=0;z>0;z--,i++) {
                cout << wspolczynniki[i];
                cout<<"x^";
                cout<<z;
                if ( z >1 )
                    std::cout<<" + ";
            }
            horner(w,wspolczynniki,s);
        } else if (x == 5) {
            i++;
            double s=w;
            cout<<"Podaj do ktorej potegi podniesc liczbe: ";
            cin >> p;
            if(p==0) w=1;
            else {
                for (int k = 1; k < p; k++) {
                    w = w * s;
                }
                cout<<w<<"^ ";
                cout<<p;
            }
        }
    }
    cout<<"Wynik: "<<w<<"\n";
    return w;
}
void range(double &a, double &b){
    cout<<"Podaj na jakim przedziale bedzie szukane miejsce zerowe (a,b).\n";
    cout<<"a= ";
    cin>>a;
    cout<<"b= ";
    cin>>b;
}
void method(int &i, double &E){
    int m;
    cout<<"\nPodaj z czego korzystac przy szukaniu miejsca zerowego(1.Liczba iteracji, 2.Podany epsilon) : ";
    cin>>m;
    if(m!=1&&m!=2)    cout<<"Podano zly numer\n";
    else if (m == 1) iterations(i);
    else if (m == 2)  epsilon(E);
}
void iterations(int &i){
    cout<<"Ile iteracji ma wykonac program: ";
    cin>>i;
}
void epsilon(double &E){
    cout<<"Podaj epsilon: ";
    cin>>E;
}
double horner(double x, int T[], int s)
    {
        int w = T[0];
        for(int i=1;i<=s;i++)
            w = w*x + T[i];
        return w;
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
    cout<<x0; //nie wiem czy zwracac czy wyswietlac
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
    cout<<x0; //nie wiem czy zwracac czy wyswietlac
    return x0;
}
