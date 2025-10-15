//
// Created by cefgo on 24/09/2025.
//

#include <iostream>

#include "point.h"

Point::Point(int x, int y) {
    if (x >= 0 && x <= 2000 && y >= 0 && y <= 2000) {
        this->x = x;
        this->y = y;
    }
    else {
        this->x = 0;
        this->y = 0;
    }
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

void Point::print() const {
    std::cout<<"x component: "<<this->getX()<<" y component: " <<this->getY()<<std::endl;
}