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

vector<int> used;

struct HandledPlane {
    int x1_, y1_, x2_, y2_;
    std::string name_;
};

bool planecmp(Airplane a, Airplane b) {
    return  (a.height_ > b.height_) ||
            (a.height_ == b.height_ && a.width_ > b.width_);
}

void SortOrders(ParamSet& params) {
    // Сперва сортируем по убыванию числа обязательных самолетов
    sort(params.orders_.begin(),
         params.orders_.end(),
         [](const Order& a,const Order& b){
             return a.min_number_ > b.min_number_ ||
                    (a.min_number_ == b.min_number_ && a.time_ > b.time_);
         });
    used.clear();
    used.resize(params.orders_.size());
}

vector<Order> FormImportantQuery(vector<Order>& orders) {
    // Формируем вектор ордеров, обязательных к исполнению.
    vector<Order> required;
    for (auto& order : orders) {
        if (order.min_number_ > 0) {
            Order pushed = order;
            pushed.number_ = pushed.min_number_;
            order.number_ -= order.min_number_;
            order.min_number_ = 0;
            required.push_back(pushed);
        }
    }
    return required;
}

vector<Order> FormOtherQuery(const vector<Order>& orders) {
    // Формируем вектор оставшихся ордеров.
    vector<Order> required;
    for (const auto& order : orders) {
            required.push_back(order);
    }
    return required;
}

vector<Order> UnpackOrders(vector<Order>& orders) {
    // "Распаковываем" ордеры - теперь у нас вектор, в котором элементы - каждый отдельный самолет.
    vector<Order> unpacked;
    for (auto& order : orders) {
        while (order.number_ > 0) {
            Order pushed = order;
            pushed.number_ = 1;
            unpacked.push_back(pushed);
            --order.number_;
        }
    }
    return unpacked;
}

void FormPackingQuery(vector<Order>& orders, Hangar& hangar, ParamSet& params) {
    ofstream out;
    out.open(hangar.name_ + "_in.txt");
    out << orders.size() << " " << hangar.height_ << " " << hangar.width_ << '\n';
    for (auto& order : orders) {
        Airplane* current = params.get_plane(order.airplane_);
        out << current->height_ << " " << current->width_ << " " << order.time_ << '\n';
    }
    out.close();
}

vector<Order> SortForHangar(vector<Order>& orders, Hangar& hangar, int should_take) {
    vector<Order> sorted_orders;
    sort(orders.begin(), orders.end(), [hangar](Order& a, Order& b) {
        return a.cost_[hangar.name_] < b.cost_[hangar.name_];
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
    SortOrders(params);
    vector<Order> orders = params.orders_;

    vector<Order> essential = FormImportantQuery(orders);
    essential = UnpackOrders(essential);
    unordered_map<string, double> should_take = {{"DME", 0.457},
                                                 {"SVO", 0.343},
                                                 {"VKO", 0.2}};
    int start_size = essential.size();
    for (auto& hangar : params.hangars_) {
        vector<Order> sorted_orders = SortForHangar(
                essential, hangar, (int)(should_take[hangar.name_] * start_size));
        FormPackingQuery(sorted_orders, hangar, params);
        Packing(hangar);
    }
    // Для каждого ангара вызываем SortForHangar, где should_take - пропорциональная часть объема,
    // и затем делаем FormPackingQuery и вызов решения.
    // Формируем файл в адекватном виде и направляем на упаковку.
    vector<Order> other = FormOtherQuery(orders);
    other = UnpackOrders(other);
}

vector<Order> Input() {
    vector<Order> orders;
    ifstream in;
    in.open("~/data/orders.txt");
    for (int i = 0; i < 73; ++i) {
        string company, name, type;
        int number, duration;
        double obligatory;
        in >> company >> name >> type >> number >> duration >> obligatory;
        orders.push_back({company, name, type, number, duration, (int)obligatory});
    }
}

int main() {
    ParamSet params("/home/ivan/Prog/Cpp/Aviahack/data/");
//    cout << "Ha-ha hackathons go brr";
    VeryMain(params);
    return 0;
}