//
// Created by cefgo on 26/11/2025.
//

#ifndef SETTLEMENT_H
#define SETTLEMENT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Settlement {
    string name = "";
    string county = "";
    int population = 0;
    // constructor, getters, setters, inserter operator
public:
    Settlement();

    Settlement(const string &name, const string &county, int population)
        : name(name),
          county(county),
          population(population) {
    }

    string getName() const;

    string getCounty() const;

    int getPopulation() const;

    Settlement& operator=(const Settlement& other)
    {
        if (this == &other) return *this;
        this->name = other.name;
        this->county = other.county;
        this->population = other.population;

        return *this;
    }
    friend ostream& operator<<(ostream& os,const Settlement& what) {
        os << what.name << "(" << what.county << "):" << what.population << endl;
        return os;
    }
};

#endif //SETTLEMENT_H
