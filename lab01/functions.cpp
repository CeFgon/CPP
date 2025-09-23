//
// Created by cefgo on 17/09/2025.
//
//git add .
//git commit -m "..."
//git push

#include "functions.h"

#include <algorithm>

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

double stddev(double array[], int numElements) {
    if (numElements <= 0) {
        return NAN;
    }

    double arrayMean = mean(array, numElements);

    double sqDiffSum = 0.0;
    for (int i = 0; i < numElements; i++) {
        double diff = array[i] - arrayMean;
        sqDiffSum += diff * diff;
    }

    double variance = sqDiffSum / numElements;

    return sqrt(variance);
}

std::pair<double, double> max2(double array[], int numElements) {
    std::pair<double, double> maxNrs;
    maxNrs.first = 0;
    maxNrs.second = 0;
    if (numElements <= 0) {
        maxNrs.first = NAN;
        maxNrs.second = NAN;
    }
    else if (numElements == 1) {
        maxNrs.first = array[0];
        maxNrs.second = array[0];
    }
    else {
        for (int i = 0; i < numElements; i++) {
            if (array[i] > maxNrs.first) {
                maxNrs.second = maxNrs.first;
                maxNrs.first = array[i];
            }
            else if (array[i] > maxNrs.second) {
                maxNrs.second = array[i];
            }
        }
    }
    return maxNrs;
}

int countWords(std::string text) {
    int nrWords = 0;
    istringstream inputstream(text);
    string word;
    while(inputstream >> word){
        istringstream wordstream(word);
        nrWords++;
    }
    return nrWords;
}

string code(string text) {
    for (int i = 0; i < text.length(); i++) {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) {
            if (text[i] == 'z') {
                text[i] = 'a';
            }
            else if (text[i] == 'Z') {
                text[i] = 'A';
            }
            else {
                text[i] = text[i]+1;
            }
        }
    }
    return text;
}

std::string capitalizeWords(std::string text) {
    for (int i = 0; i < text.length(); i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            if (i == 0 || text[i-1] == ' ') {
                text[i] = toupper(text[i]);
            }
        }
    }
    return text;
}
