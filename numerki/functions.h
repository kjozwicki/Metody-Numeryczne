//
// Created by komor on 08.03.2022.
//

#ifndef NUMERKI_FUNCTIONS_H
#define NUMERKI_FUNCTIONS_H

int choice (double w);
void range(double &a, double &b);
void method(int &i, double &E);
void iterations(int &i);
void epsilon(double &E);
double horner(double x, int T[], int y);
double bisection(double a, double b, double &E, int &i, int maks);
double regulaFalsi(double a, double b, double &E, int &i, int maks);

#endif //NUMERKI_FUNCTIONS_H