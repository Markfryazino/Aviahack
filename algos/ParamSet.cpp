//
// Created by data_sapiens on 09.05.2020.
//

#include <vector>
#include "ParamSet.h"
#include "TimeToInt.h"
#include <iostream>

ParamSet::ParamSet(std::string path) {
    std::ifstream fin_hangar(path + "hangars.txt");
    std::string name;
    int width, height;
    while (fin_hangar >> name >> width >> height) {
        this->hangars_.push_back({name, static_cast<double>(width), static_cast<double>(height)});
        this->hangar_to_id_[name] = this->hangars_.size() - 1;
    }

    std::ifstream fin_planes(path + "airplanes.txt");
    while (fin_planes >> name >> width >> height) {
        this->planes_.push_back({name, static_cast<double>(width), static_cast<double>(height)});
        this->plane_to_id_[name] = this->planes_.size() - 1;
    }

    std::ifstream fin_companies(path + "companies.txt");
    std::string start, end;
    double fine;
    while (fin_companies >> name >> start >> end >> fine) {
        int istart = StrToInt(start), iend = StrToInt(end);
        this->companies_.push_back({name, istart, iend, fine});
        this->company_to_id_[name] = this->companies_.size() - 1;
    }

    std::ifstream fin_types(path + "types.txt");
    std::string type_name, plane_name;
    double cost_dme, cost_svo, cost_vko;
    while (fin_types >> type_name >> plane_name >> cost_dme >> cost_svo >> cost_vko) {
        this->get_hangar("DME")->costs_[{type_name, plane_name}] = cost_dme;
        this->get_hangar("SVO")->costs_[{type_name, plane_name}] = cost_svo;
        this->get_hangar("VKO")->costs_[{type_name, plane_name}] = cost_vko;
    }

    std::ifstream fin_orders(path + "orders.txt");
    std::string comp_name;
    double number, time, min;
    while (fin_orders >> comp_name >> plane_name >> type_name >> number >> time >> min) {
        std::map<std::string, double> costs;
        for (auto& hangar : this->hangars_) {
            double cost = hangar.costs_[{type_name, plane_name}];
            if (cost == -1)
                costs[hangar.name_] = -1;
            else costs[hangar.name_] = time * cost;
        }
        this->orders_.push_back({comp_name, plane_name, type_name,
                                 static_cast<int>(number), static_cast<int>(time), static_cast<int>(min), costs});
    }
}