//
// Created by komor on 08.03.2022.
//

#ifndef NUMERKI_FUNCTIONS_H
#define NUMERKI_FUNCTIONS_H

int choice (double w);
void iterations(int &i);
double horner(double x, double T[], int y);
double bisection(double a, double b, double E, int &i, int f, int maks);
double regulaFalsi(double a, double b, double E, int &i, int f, int maks);

#endif //NUMERKI_FUNCTIONS_H