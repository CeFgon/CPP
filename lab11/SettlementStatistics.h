//
// Created by cefgo on 26/11/2025.
//

#ifndef SETTLEMENTSTATISTICS_H
#define SETTLEMENTSTATISTICS_H

#include "Settlement.h"

struct SettlementStatistics {
    virtual int numSettlements() const;
    virtual int numCounties() const;
    virtual int numSettlementsByCounty(const string& county) const;
    virtual vector<Settlement> findSettlementsByCounty(const string& county) const;
    virtual Settlement findSettlementsByNameAndCounty(const string& name, const string& county) const;
    virtual Settlement maxPopulationBySettlement() const;
    virtual Settlement minPopulationBySettlement() const;
    virtual vector<Settlement> findSettlementsByName(const string& name);
};

#endif //SETTLEMENTSTATISTICS_H
