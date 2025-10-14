//
// Created by cefgo on 08/10/2025.
//
//P(x) = a_0X^n + a_1X^(n-1) + …+ a_(n-1)x + a_n
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>

using namespace std;

class Polynomial {
    // Polinom együtthatói
    double *coefficients;
    // Polinom együtthatóinak a száma
    int capacity;
public:
    Polynomial(int degree, const double coefficients[]);
    Polynomial(const Polynomial &that);
    ~Polynomial() = default;
    // Polinom fokszáma
    int degree() const;
    // Polinom értéke a megadott pontban
    double evaluate(double x) const;
    // Polinom deriváltja
    Polynomial derivative() const;
    double operator[](int index) const;
    friend Polynomial operator -(const Polynomial &a);
    friend Polynomial operator +(const Polynomial &a, const Polynomial &b);
    friend Polynomial operator -(const Polynomial &a, const Polynomial &b);
    friend Polynomial operator *(const Polynomial &a, const Polynomial &b); //HF megirni
    friend ostream & operator <<(ostream& out, const Polynomial& what);
    /* copy assignment - mély másolat letiltása értékadásra nézve */
    Polynomial& operator=(const Polynomial&) = delete;
};

#endif
