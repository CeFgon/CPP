//
// Created by cefgo on 08/10/2025.
//

#include "Polynomial.h"

#include <valarray>

Polynomial::Polynomial(int degree, const double coefficients[]) {
    capacity = degree + 1;
    this -> coefficients = new double(capacity);
    copy(coefficients,coefficients + degree + 1,this -> coefficients);
}

Polynomial::Polynomial(const Polynomial &that) {
    this -> capacity = that.capacity;
    this -> coefficients = new double(that.capacity);
    //copy(that.coefficients,that.coefficients + that.capacity,this->coefficients);
    for (int i = 0; i < that.capacity; ++i) {
        this -> coefficients[i] = that.coefficients[i];
    }
}

/*Polynomial::~Polynomial() {
   delete [] coefficients;
}*/

int Polynomial::degree() const {
    return this -> capacity - 1;
}

double Polynomial::evaluate(double x) const {
    double result = 0;
    for (int i = 0; i < this -> capacity; ++i) {
        result += coefficients[i] * pow(x,capacity - 1 - i);
    }
    return result;
}

Polynomial Polynomial::derivative() const {
    double* newCoefficients = new double[capacity - 1];
    for (int i = 0; i < capacity - 1; ++i) {
        newCoefficients[i] = coefficients[i] * (capacity - 1);
    }
    Polynomial newPoly(capacity - 2, newCoefficients);
    delete[] newCoefficients;
    return newPoly;
}

double Polynomial::operator[](int index) const {
    return coefficients[index];
}


Polynomial operator-(const Polynomial &a) {
    double* newCoefficients = new double[a.capacity - 1];
    for (int i = 0; i < a.capacity ; ++i) {
        newCoefficients[i] *= -1;
    }
    Polynomial newPoly(a.capacity - 1, newCoefficients);
    delete[] newCoefficients;
    return newPoly;
}

Polynomial operator+(const Polynomial &a, const Polynomial &b) {
    if (a.capacity > b.capacity) {
        double* newCoefficients = new double[a.capacity - 1];
        copy(a.coefficients,a.coefficients + a.capacity,newCoefficients);
        for (int i = b.capacity - 1; i >= 0; --i) {
            newCoefficients[i] += b.coefficients[i];
        }
        Polynomial newPoly(a.capacity - 1, newCoefficients);
        delete[] newCoefficients;
        return newPoly;
    }
    else {
        double* newCoefficients = new double[b.capacity - 1];
        copy(b.coefficients,b.coefficients + b.capacity,newCoefficients);
        for (int i = a.capacity - 1; i >= 0; --i) {
            newCoefficients[i] += a.coefficients[i];
        }
        Polynomial newPoly(b.capacity - 1, newCoefficients);
        delete[] newCoefficients;
        return newPoly;
    }
}

Polynomial operator-(const Polynomial &a, const Polynomial &b) {
    if (a.capacity > b.capacity) {
        double* newCoefficients = new double[a.capacity - 1];
        copy(a.coefficients,a.coefficients + a.capacity,newCoefficients);
        for (int i = b.capacity - 1; i >= 0; --i) {
            newCoefficients[i] -= b.coefficients[i];
        }
        Polynomial newPoly(a.capacity - 1, newCoefficients);
        delete[] newCoefficients;
        return newPoly;
    }
    else {
        double* newCoefficients = new double[b.capacity - 1];
        copy(b.coefficients,b.coefficients + b.capacity,newCoefficients);
        for (int i = a.capacity - 1; i >= 0; --i) {
            newCoefficients[i] -= a.coefficients[i];
        }
        Polynomial newPoly(b.capacity - 1, newCoefficients);
        delete[] newCoefficients;
        return newPoly;
    }
}

Polynomial operator*(const Polynomial &a, const Polynomial &b) {
    double* newCoefficients = new double[a.capacity - 1];
    for (int i = 0; i <= a.degree(); ++i) {
        for (int j = 0; j <= b.degree(); ++j) {
            newCoefficients[i + j] += a.coefficients[i] * b.coefficients[j];
        }
    }
    Polynomial newPoly(a.degree()+b.degree(), newCoefficients);
    delete[] newCoefficients;
    return newPoly;
}

ostream& operator<<(ostream &out, const Polynomial &what) {
    out << "P(x) = ";
    for (int i = 0; i < what.capacity - 1; i++) {
        out << what.coefficients[i] << "X^" << (what.capacity - i - 1) << "+";
    }
    out << what.coefficients[what.capacity - 1] << endl;
    return out;
}
