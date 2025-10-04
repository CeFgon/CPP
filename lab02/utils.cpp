//
// Created by cefgo on 24/09/2025.
//

#include "utils.h"

using namespace std;

double distance(const Point& a, const Point& b){
    return sqrt(pow((b.getX() - a.getX()),2) + pow((b.getY() - a.getY()),2));
}

bool isSquare(const Point &a, const Point &b, const Point &c, const Point &d) {
    double t[6]{
            distance(a,b), distance(a,c), distance(a,d), distance(b,c), distance(b,d), distance(c,d)
    };
    std::sort(t,t+6);
    return t[0] == t[3] && t[4] == t[5] && t[3] < t[5];
}

void testIsSquare(const char *filename) {
    std:: ifstream in (filename);
    if(! in) {
    std::cout<<"Couldn't open file :(."<<std::endl;
        return;
    }
    std::string line;
    while(std::getline(in,line))
    {
        std::stringstream ss(line);
        int x1,x2,x3,x4,y1,y2,y3,y4;
        ss>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        if (isSquare(Point(x1,y1),Point(x2,y2),Point(x3,y3),Point(x4,y4)))
        {
            std::cout<<"Square "<< line<< std::endl;
        }
        else{
            std::cout<<"No square "<<line<<std::endl;
        }
    }
    in.close();
}

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
    for (int i = 0; i < numPoints; ++i) {
        std::cout << "Point " << i << ": ";
        points[i].print();
    }
}

std::pair<Point, Point> closestPoints(Point *points, int numPoints) {
    if(numPoints < 2) {
        throw std::invalid_argument("Not enough points in the array, need at least 2");
    }
    double minDist = distance(points[0], points[1]);
    std::pair<Point, Point> result(points[0], points[1]);
    for (int i = 0; i < numPoints; ++i) {
        for (int j = i + 1; j < numPoints; ++j) {
            double d = distance(points[i], points[j]);
            if (d < minDist) {
                minDist = d;
                result = { points[i], points[j] };
            }
        }
    }
    return result;
}

std::pair<Point, Point> farthestPoints(Point *points, int numPoints) {
    if (numPoints < 2) {
        throw std::invalid_argument("Need at least 2 points");
    }

    double maxDist = distance(points[0], points[1]);
    std::pair<Point, Point> result(points[0], points[1]);

    for (int i = 0; i < numPoints; ++i) {
        for (int j = i + 1; j < numPoints; ++j) {
            double d = distance(points[i], points[j]);
            if (d > maxDist) {
                maxDist = d;
                result = { points[i], points[j] };
            }
        }
    }
    return result;
}

void sortPoints(Point *points, int numPoints) {
    std::sort(points, points + numPoints, [](const Point& a, const Point& b) {
           if (a.getX() == b.getX())
               return a.getY() < b.getY();
           return a.getX() < b.getX();
       });
}

double distanceFromOrigin(const Point& p) {
    return std::sqrt(p.getX()*p.getX() + p.getY()*p.getY());
}

Point* farthestPointsFromOrigin(Point* points, int numPoints) {
    if (numPoints == 0) return nullptr;

    // find max distance
    double maxDist = distanceFromOrigin(points[0]);
    for (int i = 1; i < numPoints; ++i) {
        double d = distanceFromOrigin(points[i]);
        if (d > maxDist) {
            maxDist = d;
        }
    }

    // count how many points match maxDist
    int count = 0;
    for (int i = 0; i < numPoints; ++i) {
        if (std::abs(distanceFromOrigin(points[i]) - maxDist) < 1e-9) {
            count++;
        }
    }

    // allocate and fill result array
    Point* result = new Point[count];
    int idx = 0;
    for (int i = 0; i < numPoints; ++i) {
        if (std::abs(distanceFromOrigin(points[i]) - maxDist) < 1e-9) {
            result[idx++] = points[i];
        }
    }

    return result;
}

void deletePoints(Point *points) {
    delete[] points;
}