//
// Created by data_sapiens on 09.05.2020.
//

#include "Distribution.h"
#include <string>
#include <vector>
#include <map>
#include <fstream>

int INF = 1e9;

std::pair<double, std::string> Distribution::evaluate() {
    double cost = 0;
    // компания: сколько всего, сколько выполнили
    std::map<std::string, std::pair<int, int>> company_done;
    for (auto &order : this->orders_) {
        std::string company = order.order_.company_, type = order.order_.type_,
                plane = order.order_.airplane_;
        if (company_done.find(company) == company_done.end())
            company_done[company] = {1, 0};
        else ++company_done[company].first;

        if (order.taken_number_ >= order.order_.min_number_)
            ++company_done[company].second;
        else {
            int lost = order.order_.min_number_ - order.taken_number_;
            double minus = lost * this->params_.get_company(company)->fine_;
            double max_cost = 0;
            for (auto &hangar : this->params_.hangars_)
                max_cost = std::max(max_cost, hangar.costs_[{type, plane}]);
            if (max_cost == 0)
                throw "Тут беда с ангарами - никто такое не выполняет!";
            cost -= minus * max_cost;
        }

        for (auto &plane : order.planes_) {
            std::string hangar_name = plane[0].first.hangar_;
            double day_cost = this->params_.get_hangar(hangar_name)->costs_[{type, hangar_name}];
            cost += day_cost * order.order_.time_;
        }
    }

    for (auto &p : company_done)
        if (p.second.first * 0.7 > p.second.second)
            return {-INF, "Недостаточно заказов для " + p.first};

    return {cost, "OK"};
}
