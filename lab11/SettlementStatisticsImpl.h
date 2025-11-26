//
// Created by cefgo on 26/11/2025.
//

#ifndef SETTLEMENTSTATISTICIMPL_H
#define SETTLEMENTSTATISTICIMPL_H

#include <map>
#include <set>

#include "SettlementStatistics.h"

class SettlementStatisticsImpl : public SettlementStatistics {
private:
    multimap<string,Settlement> settlements;
public:
    SettlementStatisticsImpl(string filename);

    virtual int numSettlements() const;
    virtual int numCounties() const;
    virtual int numSettlementsByCounty(const string& county) const;
    virtual vector<Settlement> findSettlementsByCounty(const string& county) const;
    virtual Settlement findSettlementsByNameAndCounty(const string& name, const string& county) const;
    virtual Settlement maxPopulationBySettlement() const;
    virtual Settlement minPopulationBySettlement() const;
    virtual vector<Settlement> findSettlementsByName(const string& name);
};

#endif //SETTLEMENTSTATISTICIMPL_H
