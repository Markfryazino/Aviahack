#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <unordered_map>
#include "TimeToInt.h"
#include "Distribution.h"

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

vector<Order> HandleOrders(ParamSet& params, Hangar& hangar, int required=0) {
    // Здесь мы выбираем required лучших самолетов для данного ангара и отправляем ему на съедение.
    required = (required == 0 ? hangar.width_ * hangar.height_ / 1800 : required);
    vector<Order> subset;
    for (int i = 0; i < required; ++i) {
        int best_price = 0, id = 0, best_id = -1;
        Order best_order = {};
        for (auto order : params.orders_) {
            if (used[id] < order.min_number_ && best_price < order.cost_[hangar.name_]) {
                best_id = id;
                best_price = order.cost_[hangar.name_];
            }
            ++id;
        }
        if (best_id > -1) {
            ++used[best_id];
            subset.push_back(best_order);
        }
    }
    return subset;
}

bool Greedy(ParamSet& params, Hangar& hangar)   {
    vector<Order> orders = HandleOrders(params, hangar, 2);
    vector<Airplane> planes;
    // unpacking orders
    for (const auto& order : orders) {
        for (int j = 0; j < order.min_number_; ++j) {
            Airplane *plane = params.get_plane(order.airplane_);
            planes.push_back({plane->name_, plane->height_, plane->width_});

        }
    }

    sort(planes.begin(), planes.end(), planecmp);
    vector <Coords> result;
    double last_x = 0, last_y = 0, cur_x = 0, cur_y = 0;

    vector<bool> taken(planes.size());

    bool any_taken = false;
    int moved = 0;
    while (moved < 2) {
        for (int i = 0; i < planes.size(); ++i) {
            if (last_x + planes[i].width_ <= hangar.width_ &&
                cur_y + planes[i].height_ <= hangar.height_) {
                result.push_back({hangar.name_, cur_x, cur_y});
                last_y = max(last_y, cur_y + planes[i].height_);
                last_x += planes[i].width_;
                any_taken = true;
                moved = 0;
            }
        }
        if (!any_taken) {
            cur_y = last_y;
            cur_x = 0;
            last_x = 0;
            ++moved;
        }
        any_taken = false;
    }

}

void VeryMain(ParamSet& params) {
    SortOrders(params);

}

int main() {
//    cout << "Ha-ha hackathons go brr";

    return 0;
}