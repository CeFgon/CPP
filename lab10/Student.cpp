//
// Created by cefgo on 26/11/2025.
//

#include "Student.h"

Student::Student(int id, const string &firstName, const string &lastName) {
    this->id = id;
    this->firstName=firstName;
    this->lastName=lastName;
}

int Student::getId() const {
    return this->id;
}

void Student::setId(int id) {
}

const string & Student::getFirstName() const {
    return this->firstName;
}

const string & Student::getLastName() const {
    return this->lastName;
}

void Student::addGrade(const string &subject, double grade) {
    this->grades.insert(make_pair(subject,grade));
}

double Student::getGrade(const string &subject) const {
    double result = grades.find(subject)->second;
    return result;
}

const map<string, double> & Student::getGrades() const {
    return this->grades;
}

void Student::computeAverage() {
    double sum;
    for (auto& t : grades) {

    }
    this->average = sum/grades.size();
}

double Student::getAverage() const {
    return this->average;
}

ostream & operator<<(ostream &os, const Student &student) {
    os << student.id << " " << student.firstName << " " << student.lastName << " - " << student.average << "\nGrades: ";
    for (auto& t : student.grades) {
        os << t.first << ": " << t.second << " ";
    }
    os << endl;
    return os;
}
