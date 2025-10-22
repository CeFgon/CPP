//
// Created by cefgo on 22/10/2025.
//

#ifndef USER_H
#define USER_H

#include <iostream>
#include <map>
#include <string>

using namespace std;

class User {
public:
    int get_id() const;

    string get_name() const;

    map<int, double> get_results() const;

private:
    int id;
    static int count;
    string name;
    map<int,double> results;

public:
    User(const string &name);
    void addResult(const int id,const double result);
    void printResults();
};

#endif //USER_H
