//
// Kamil Jóźwicki, Kacper Komorowski
//

#include "functions.h"
#include <iostream>
#include <cmath>

int choice (double w) {
    int x,s,m,p,i=1;
    std::cout<<"Ile zlozen funcji wykonac: ";
    std::cin>>m;
    while(i<=m) {
        std::cout
                << "Wybierz funkcje: \n1.Sinus \n2.Cosinus \n3.Tanges \n4.Funcja wielomianowa \n5.Funcja wykladnicza \n\nWybor:  ";
        std::cin >> x;
        if (x > 5 || x < 1) std::cout << "Podano zly numer, podaj jeszcze raz \n";
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
            std::cout<< "Podaj stopien wielomianu: ";
            std::cin >> s;
            int wspolczynniki [s];
            std::cout<< "Podaj wspolczynniki od najwyzszego stopnia do najmniejszego: ";
            for (int z=0;z<s;z++) {
                std::cin>>wspolczynniki[z];
            }
            for (int z=s,i=0;z>0;z--,i++) {
                std::cout << wspolczynniki[i];
                std::cout<<"x^";
                std::cout<<z;
                if ( z >1 )
                    std::cout<<" + ";
            }
            horner(w,wspolczynniki,s);
        } else if (x == 5) {
            std::cout<<"Podaj do ktorej potegi podniesc liczbe: ";
            std::cin >> p;
            if(p==0) w=1;
            for (int k=1;k<=p;k++) {
                w*w;
            }
        }
    }
    std::cout<<"Wynik: "<<w<<"\n";
    return w;
}

void iterations(int &i){

    std::cout<<"Ile iteracji ma wykonac program: ";
    std::cin>>i;
}



    double horner(double x, int T[], int s)
    {
        int w = T[0];

        for(int i=1;i<=s;i++)
            w = w*x + T[i];
        return w;
    }

double bisection(double a, double b, double E, int &i, int maks){
    double acc, fa, x0, fx0;
    i=0;
    while((i<maks)&&(acc>E)) {
        fa = choice(a);
        x0 = (a + b) / 2.0;
        fx0 = choice(x0);
        if (fa * fx0 < 0)
            b = x0;
        else
            a = x0;
        i++;
        acc = fabs(fx0);
        std::cout << x0 << "\n";
        std::cout << choice(x0) << "\n";
    }
    return x0;
}

double regulaFalsi(double a, double b, double E, int &i, int maks){
    double acc, fa, fb, x0, fx0;
    i=0;
    while((i<maks)&&(acc>E))
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
    return x0;
}
