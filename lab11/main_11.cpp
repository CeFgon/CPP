#include <iostream>

#include "SettlementStatisticsImpl.h"

using namespace std;

int main() {
    //std::cout << "Hello, Lab_11" << std::endl;
    SettlementStatisticsImpl s("telepulesek.csv");
    cout << "Number of Settlements:" << s.numSettlements() << endl;
    cout << "Number of Counties:" << s.numCounties() << endl;
    cout << "Number of Settlements in Harghita:" << s.numSettlementsByCounty("HR") << endl;
    vector<Settlement> HrS = s.findSettlementsByCounty("HR");
    cout << "Settlement in Harghita:";
    for (Settlement& s1 : HrS) {
        cout << s1;
    }
    Settlement p = s.findSettlementsByNameAndCounty("Praid","HR");
    cout << "Finding : Praid -HR:" << p;
    vector<Settlement> sov = s.findSettlementsByName("Sovata");
    cout << "Finding Sovata: ";
    for (Settlement s1 : sov) {
        cout << s1;
    }
    Settlement max=s.maxPopulationBySettlement() ,min = s.minPopulationBySettlement();
    cout << "Max Population: " << max << "\t Min Population" << min;
    return 0;
}