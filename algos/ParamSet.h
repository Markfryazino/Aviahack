//
// Created by data_sapiens on 09.05.2020.
//

#include <map>
#include <vector>
#include "structs.h"
#include "TimeToInt.h"

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
    Company* get_company(std::string name) {
        return &companies_[company_to_id_[name]];
    }

    Airplane* get_plane(std::string name) {
        return &planes_[plane_to_id_[name]];
    }

    Hangar* get_hangar(std::string name) {
        return &hangars_[hangar_to_id_[name]];
    }

    ParamSet(std::string path);
};


#endif //ALGOS_PARAMSET_H
