//
// Created by cefgo on 17/09/2025.
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <utility>
#include <cmath>
#include <sstream>
#include <string>

int countBits(int number);
bool setBit(int& number, int order);
double mean(double array[], int numElements);
double stddev(double array[], int numElements);
std::pair<double, double> max2(double array[], int numElements);
int countWords(std::string text);
std::string code(std::string text);
std::string capitalizeWords(std::string text);

#endif //FUNCTIONS_H
