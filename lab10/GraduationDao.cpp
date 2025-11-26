//
// Created by cefgo on 26/11/2025.
//

#include "GraduationDao.h"

#include <fstream>
#include <sstream>

void GraduationDao::enrollStudents(const string &filename) {
    ifstream f(filename);
    if (!f.is_open()) {
        cerr << "Error" << endl;
        return;
    }
    string temp;
    while (getline(f,temp)) {
        stringstream ss(temp);
        string id,fname,lname;
        int ids;
        ss>>id>>fname>>lname;

        if (id.empty()) {
            ids=0;
        }
        else {
            ids=stoi(id);
        }
        Student s(ids,fname,lname);
        this->students.insert(make_pair(ids,s));
    }
}

void GraduationDao::readGradesSubject(const string &subject, const string &filename) {
    ifstream f(filename);
    if (!f.is_open()) {
        cerr << "Error" << endl;
        return;
    }
    string temp;
    while (getline(f,temp)) {
        stringstream ss(temp);
        string id,grade;
        int ids;
        double grades;
        ss>>id>>grade;

        if (grade.empty()) {
            grades=0.0;
        }
        else {
            grades=stod(grade);
        }
        this->students.find(ids)->second.addGrade(subject,grades);
    }
}

void GraduationDao::computeAverage() {
    for (auto& t : students) {
        t.second.computeAverage();
    }
}

int GraduationDao::numEnrolled() const {
    return students.size();
}

int GraduationDao::numPassed() const {
    int count = 0;
    for (auto& t : students) {
        if (t.second.getAverage() > 6) {
            count++;
        }
    }
    return count;
}

Student GraduationDao::findById(int id) const {
    if (students.find(id) != students.end()) {
        return students.find(id)->second;
    }
    throw out_of_range("Nincs benne");
}

double GraduationDao::getAverageBySubject(const string &subject) const {
    double sum = 0;
    int count = 0;
    for (auto& t : students) {
        sum += t.second.getGrade(subject);
        count++;
    }
    return sum/count;
}
