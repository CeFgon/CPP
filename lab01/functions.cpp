//
// Created by cefgo on 17/09/2025.
//
//git add .
//git commit -m "..."
//git push

#include "functions.h"
#include <iostream>
#include <cmath>

using namespace std;

int countBits(int number) {
    int count = 0;
    while (number != 0) {
        if (number & 1) {
            count++;
        }
        number >>= 1;
    }
    return count;
}

bool setBit(int& number, int order) {
    if (order >= 0 && order <=31) {
        int mask = 1 << order;
        number = number | mask;
        return true;
    }
    return false;
}

double mean(double array[], int numElements) {
    if (numElements == 0) {
        return NAN;
    }
    else {
        double mean;
        for (int i=0; i<numElements; i++) {
            mean += array[i];
        }
        mean = mean/numElements;
        return mean;
    }
}

double stddev(double array[], int numElements); {

}
