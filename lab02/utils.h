//
// Created by cefgo on 24/09/2025.
//

#ifndef UTILS_H
#define UTILS_H

#include "point.h"

double distance(const Point& a, const Point& b);
bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d);
void testIsSquare(const char * filename);
Point* createArray(int numPoints);
void printArray(Point* points, int numPoints);
std::pair<Point, Point> closestPoints(Point* points, int numPoints);
std::pair<Point, Point> farthestPoints(Point* points, int numPoints);
void sortPoints(Point* points, int numPoints);

#endif //UTILS_H
