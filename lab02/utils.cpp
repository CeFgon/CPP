//
// Created by cefgo on 24/09/2025.
//

//BEFEJEZNI JOVOHET VASARNAPIG

#include "utils.h"

#include <algorithm>

#include "point.h"
#include <cmath>
#include <fstream>
#include <random>
using namespace std;

double distance(const Point& a, const Point& b){
    return sqrt(pow((b.getX() - a.getX()),2) + pow((b.getY() - a.getY()),2));
}

//Kibogozni
//->
/*
bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d) {
    int d1 = distance(a,b);
    int d2 = distance(a,c);
    int d3 = distance(a,d);
    int d4 = distance(b,c);
    int d5 = distance(b,d);
    int d6 = distance(c,d);

    if (distance(a,b) == distance(c,d) == distance(b,c) == distance(a,d)) {
        if (distance(b,d) == distance(a,c)) {
            return true;
        }
    }
    if (distance(a,b) == distance(c,d) == distance(a,c) == distance(b,d)) {
        if (distance(a,d) == distance(c,b)) {
            return true;
        }
    }
    if (distance(a,d) == distance(c,b) == distance(a,c) == distance(d,b)) {
        if (distance(a,b) == distance(c,d)) {
            return true;
        }
    }
    if (distance(d,a) == distance(b,c) == distance(b,d) == distance(a,c)) {
        if (distance(d,c) == distance(b,a)) {
            return true;
        }
    }
    return false;
}

void testIsSquare(const char * filename) {
    std::ifstream f(filename);
    if (!f.is_open()) {
        exit(404);
    }
    for (int i=0; i < 8; i++) {
        int x1,x2,x3,x4,y1,y2,y3,y4;
        f>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        Point p1(x1,y1);
        Point p2(x2,y2);
        Point p3(x3,y3);
        Point p4(x4,y4);
        p1.print();
        p2.print();
        p3.print();
        p4.print();
        if (isSquare(p1,p2,p3,p4) == true) {
            cout<<"KOCKA"<<endl;
        }
        else {
            cout<<"NEM KOCKA"<<endl;
        }
    }
}
*/
// <-

Point* createArray(int numPoints) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1,2000);
    Point* array = new Point[numPoints];
    for (int i = 0; i < numPoints; i++) {
        int x = distrib(gen);
        int y = distrib(gen);
        array[i] = Point(x,y);
    }
}

void printArray(Point* points, int numPoints) {
    for (int i=0; i < numPoints; i++) {
        points[i].print();
    }
}

pair<Point, Point> closestPoints(Point* points, int numPoints) {
    int minimum = INT_MAX;
    Point x,y;
    for (int i = 0; i < numPoints; i++) {
        for (int j = 0; j < numPoints; j++) {
            if (distance(points[i],points[j]) < minimum) {
                minimum = distance(points[i],points[j]);
                x = points[i];
                y = points[j];
            }
        }
    }
    return make_pair(x,y);
}

pair<Point, Point> farthestPoints(Point* points, int numPoints) {
    int maximum = 0;
    Point x,y;
    for (int i = 0; i < numPoints; i++) {
        for (int j = 0; j < numPoints; j++) {
            if (distance(points[i],points[j]) > maximum) {
                maximum = distance(points[i],points[j]);
                x = points[i];
                y = points[j];
            }
        }
    }
    return make_pair(x,y);
}

void sortPoints(Point* points, int numPoints) {
    sort(points,points+numPoints,[](const Point& a,const Point& b){return b.getX() > a.getX();});
}