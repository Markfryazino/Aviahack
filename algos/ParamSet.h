//
// Created by data_sapiens on 09.05.2020.
//

#include <map>
#include <vector>
#include "structs.h"

#ifndef ALGOS_PARAMSET_H
#define ALGOS_PARAMSET_H


class ParamSet {
public:
    std::vector<Company> companies_;
    std::vector<Airplane> planes_;
    std::vector<Hangar> hangars_;
    std::vector<Order> orders_;

    std::map<std::string, int> company_to_id_;
    std::map<std::string, int> plane_to_id_;
    std::map<std::string, int> hangar_to_id_;
    std::map<std::string, int> order_to_id_;
};


#endif //ALGOS_PARAMSET_H
