#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <fstream>
#include "TimeToInt.h"
#include "ParamSet.cpp"
#include "Distribution.h"
#include "Packing.h"

using namespace std;

struct HandledPlane {
    int x1_, y1_, x2_, y2_;
    std::string name_;
};

bool planecmp(Airplane a, Airplane b) {
    return  (a.height_ > b.height_) ||
            (a.height_ == b.height_ && a.width_ > b.width_);
}

void SortOrders(vector<pair<Order, int>>& orders) {
    // Сперва сортируем по убыванию числа обязательных самолетов
    sort(orders.begin(), orders.end(),
         [](const pair<Order, int>& a,const pair<Order, int>& b){
             return a.first.min_number_ > b.first.min_number_ ||
                    (a.first.min_number_ == b.first.min_number_ &&
                    a.first.time_ > b.first.time_);
         });
}

vector<pair<Order, int>> FormImportantQuery(vector<pair<Order, int>>& orders) {
    // Формируем вектор ордеров, обязательных к исполнению.
    vector<pair<Order, int>> required;
    for (auto& order : orders) {
        if (order.first.min_number_ > 0) {
            pair<Order, int> pushed = order;
            pushed.first.number_ = pushed.first.min_number_;
            order.first.number_ -= order.first.min_number_;
            order.first.min_number_ = 0;
            required.push_back(pushed);
        }
    }
    return required;
}

vector<pair<Order, int>> FormOtherQuery(const vector<pair<Order, int>>& orders) {
    // Формируем вектор оставшихся ордеров.
    vector<pair<Order, int>> required;
    for (const auto& order : orders) {
            required.push_back(order);
    }
    return required;
}

vector<pair<Order, int>> UnpackOrders(vector<pair<Order, int>>& orders) {
    // "Распаковываем" ордеры - теперь у нас вектор, в котором элементы - каждый отдельный самолет.
    vector<pair<Order, int>> unpacked;
    for (auto& order : orders) {
        while (order.first.number_ > 0) {
            pair<Order, int> pushed = order;
            pushed.first.number_ = 1;
            unpacked.push_back(pushed);
            --order.first.number_;
        }
    }
    return unpacked;
}

void FormPackingQuery(vector<pair<Order, int>>& orders, Hangar& hangar, ParamSet& params) {
    ofstream out;
    out.open(PATH + hangar.name_ + "_in.txt");
    out << orders.size() << " " << hangar.height_ << " " << hangar.width_  << " " << 90 << '\n';
    for (auto& order : orders) {
        Airplane* current = params.get_plane(order.first.airplane_);
        out << current->height_ << " " << current->width_ << " "
        << order.first.time_ << " " << order.second << '\n';
    }
    out.close();
}

vector<pair<Order, int>> SortForHangar(vector<pair<Order, int>>& orders, Hangar& hangar, int should_take) {
    vector<pair<Order, int>> sorted_orders;
    sort(orders.begin(), orders.end(), [hangar](pair<Order, int>& a, pair<Order, int>& b) {
        return a.first.cost_[hangar.name_] > b.first.cost_[hangar.name_];
    });
    // TODO Добавить сортировку по стоимости за м^3. Для этого надо сформировать локальный
    //  мап параметров самолетов и считать cost / (a.width_ * a.height_)
    int should_leave = ((int)orders.size() > should_take ? (int)orders.size() - should_take : 0);
    for (int i = (int)orders.size() - 1; i >= should_leave; --i) {
        sorted_orders.push_back(orders[i]);
        orders.pop_back();
    }
    reverse(sorted_orders.begin(), sorted_orders.end());
    return sorted_orders;
}

void VeryMain(ParamSet& params) {
    vector<pair<Order, int>> orders;
    for (int i = 0; i < params.orders_.size(); ++i) {
        orders.push_back({params.orders_[i], i});
    }
    SortOrders(orders);
    vector<pair<Order, int>> essential = FormImportantQuery(orders);
    essential = UnpackOrders(essential);
    unordered_map<string, double> should_take = {{"DME", 0.457},
                                                 {"SVO", 0.343},
                                                 {"VKO", 0.2}};
    int start_size = essential.size();
    for (auto& hangar : params.hangars_) {
        vector<pair<Order, int>> sorted_orders = SortForHangar(
                essential, hangar, (int)(should_take[hangar.name_] * start_size));
        FormPackingQuery(sorted_orders, hangar, params);
        Packing(hangar);
    }
    // Для каждого ангара вызываем SortForHangar, где should_take - пропорциональная часть объема,
    // и затем делаем FormPackingQuery и вызов решения.
    // Формируем файл в адекватном виде и направляем на упаковку.
    vector<pair<Order, int>> other = FormOtherQuery(orders);
    other = UnpackOrders(other);
}

int main() {
    ParamSet params("data/");
    VeryMain(params);
    return 0;
}