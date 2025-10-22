//
// Created by cefgo on 22/10/2025.
//

#include "user.h"

int User::count = 0;

int User::get_id() const {
    return id;
}

string User::get_name() const {
    return name;
}

map<int, double> User::get_results() const {
    return results;
}

User::User(const string &name) {
    this->id = count;
    count++;
    this->name = name;
}

void User::addResult(const int id, const double result) {
    this->results.insert({id,result});
}

void User::printResults() {
    cout << endl << "Results:" << endl;
    for (const auto &i : results) {
        cout << i.first << ": " << i.second << endl;
    }
}
