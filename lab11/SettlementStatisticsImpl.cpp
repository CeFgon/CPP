//
// Created by cefgo on 26/11/2025.
//

#include "SettlementStatisticsImpl.h"
#include <fstream>
#include <sstream>

SettlementStatisticsImpl::SettlementStatisticsImpl(string filename) {
    ifstream f(filename);
    if (f.is_open()) {
        cerr<<"Error"<<endl;
        return;
    }
    string temp;
    getline(f,temp);
    while (getline(f,temp)) {
        stringstream ss(temp);
        string name,code,p;
        int popularity;
        getline(ss,name,',');
        getline(ss,code,',');
        getline(ss,p);
        if (p.empty()) {
            popularity=0;
        }
        else {
            popularity=stoi(p);
        }
        Settlement temps(name,code,popularity);
        cout << temps << endl;
        settlements.insert({code,temps});
    }
}

int SettlementStatisticsImpl::numSettlements() const {
    return settlements.size();
}

int SettlementStatisticsImpl::numCounties() const {
    set<string> codes;
    for (auto &a:settlements) {
        codes.insert(a.first);
    }
    return codes.size();
}

int SettlementStatisticsImpl::numSettlementsByCounty(const string &county) const {
    int count = 0;
    for (auto&a : settlements) {
        if (a.first == county) {
            count++;
        }
    }
    return count;
}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByCounty(const string &county) const {
    vector<Settlement> result;
    for (auto&a : settlements) {
        if (a.first == county) {
            result.push_back(a.second);
        }
    }
    return result;
}

Settlement SettlementStatisticsImpl::findSettlementsByNameAndCounty(const string &name, const string &county) const {
    for (auto &a : settlements) {
        if (a.first == county && a.second.getName()==name) {
            return a.second;
        }
    }
    throw out_of_range("Nincs benne");
}

Settlement SettlementStatisticsImpl::maxPopulationBySettlement() const {
    int max = 0;
    Settlement maxs;
    for (auto &a : settlements) {
        if (a.second.getPopulation()>max) {
            return a.second;
        }
    }
}

Settlement SettlementStatisticsImpl::minPopulationBySettlement() const {
    int min = INT_MAX;
    Settlement mins;
    for (auto &a : settlements) {
        if (a.second.getPopulation()<min) {
            return a.second;
        }
    }
}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByName(const string &name) {
    return SettlementStatistics::findSettlementsByName(name);
}
