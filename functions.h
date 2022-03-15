//
// Kamil Jóźwicki, Kacper Komorowski
//

#ifndef NUMERKI_FUNCTIONS_H
#define NUMERKI_FUNCTIONS_H

#include <string>
#include <vector>

double one_more_time(double x);
void range(double &a, double &b);
void method(int &i, double &E);
void iterations(int &i);
void epsilon(double &E);
double horner(double wartosc_x, int T[], int stopien);
double bisection(double a, double b, double &E, int &i, int wybor_funkcji[], int ilosc_zlozen, double &potega, int wspolczynniki[], int &stopien, int &wolny);
double regulaFalsi(double a, double b, double &E, int &i, int wybor_funkcji[], int ilosc_zlozen, double &potega, int wspolczynniki[], int &stopien, int &wolny);
void wykresy(double a, double b, double x0, double x1, std::vector<double> tablica1, std::vector<double> tablica2);
#endif //NUMERKI_FUNCTIONS_H