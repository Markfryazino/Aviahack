#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <fstream>
#include "ParamSet.h"
#include "structs.h"
#include "Distribution.h"

using namespace std;

const string PATH = "/home/ivan/Prog/Cpp/Aviahack/data/";

struct plane {
    double height_, width_;
    int idx, time_, order_idx, ok_period_st, ok_period_end;
};

struct hangar {
    int idx, order_idx;
    double x, y, z;
};

bool cmp0(plane a, plane b) {
    return a.width_ > b.width_ || (a.width_ == b.width_ && a.time_ > b.time_) ||
           (a.height_ > b.height_ && a.width_ == b.width_ && a.time_ == b.time_);
}

bool cmp1(plane a, plane b) {
    return a.height_ > b.height_ || (a.height_ == b.height_ && a.time_ > b.time_) ||
           (a.width_ > b.width_ && a.height_ == b.height_ && a.time_ == b.time_);
}

bool cmp2(plane a, plane b) {
    return a.time_ > b.time_ || (a.height_ > b.height_ && a.time_ == b.time_) ||
           (a.width_ > b.width_ && a.height_ == b.height_ && a.time_ == b.time_);
}

bool cmp3(plane a, plane b) {
    return a.time_ > b.time_ || (a.time_ == b.time_ && a.width_ > b.width_) ||
           (a.height_ > b.height_ && a.width_ == b.width_ && a.time_ == b.time_);
}

bool cmp4(plane a, plane b) {
    return a.height_ + a.width_ + a.time_ > b.height_ + b.width_ + b.time_;
}

bool cmp5(plane a, plane b) {
    return (a.height_ + a.width_ + a.time_) / a.width_ > (b.height_ + b.width_ + b.time_) / b.width_;
}

bool cmp6(plane a, plane b) {
    return (a.height_ + a.width_ * a.time_) / a.height_ > (b.height_ + b.width_ * b.time_) / b.height_;
}

bool cmp7(plane a, plane b) {
    return (a.height_ * a.width_ + a.time_) / a.time_ > (b.height_ * b.width_ + b.time_) / b.time_;
}

bool cmp8(plane a, plane b) {
    return a.height_ * a.width_ * a.time_ / (a.height_ + a.width_ + a.time_) >
           b.height_ * b.width_ * b.time_ / (b.height_ + b.width_ + b.time_);
}


vector<vector<hangar>> container;

void output(vector<vector<hangar>>& ans, int cur_cont, Hangar& hang) {
    ofstream out;
    out.open(PATH + hang.name_ + "_out.txt");
    for (int i = 0; i < cur_cont; ++i) {
        out << ans[i].size() << '\n';
        for (auto& el : ans[i]) {
            out << el.order_idx << " " << el.x << " " << el.y << " " << el.z << '\n';
        }
    }
    out.close();
}

pair<int, int> solve(vector<plane>& boxes, int n, double l, double w, double time) {
    vector<bool> used(n);
    int cur_cont = 0;
    while (true) {
        double cur_w = w, cur_l = l, cur_time = time;
        bool flag1 = false, flag2 = true;
        int cnt = 0;
        double max_cur_time = time;
        while (flag2) {
            flag2 = false;
            double max_cur_l = l;

            for (int i = 0; i < n; ++i) {
                if (!used[boxes[i].idx]) {
                    flag1 = true;
                }
                if (!used[boxes[i].idx] && boxes[i].width_ <= cur_w &&
                    boxes[i].height_ <= cur_l && boxes[i].time_ <= cur_time) {
                    container[cur_cont].push_back({
                        boxes[i].idx, boxes[i].order_idx,
                        l - cur_l, w - cur_w, time - cur_time
                                                  });
                    cur_w -= boxes[i].width_;
                    max_cur_l = min(-boxes[i].height_ + cur_l, max_cur_l);
                    max_cur_time = min(-boxes[i].time_ + cur_time, max_cur_time);
                    used[boxes[i].idx] = true;
                    flag2 = true;
                }
            }
            cur_l = max_cur_l;
            cur_w = w;
            if (cur_time == max_cur_time) {
                ++cnt;
            } else if (!flag2) {
                cur_time = max_cur_time;
                cnt = 0;
                flag2 = true;
            }
            if (cnt >= 2) {
                break;
            }
        }
        ++cur_cont;
        if (!flag1 || cur_cont == 2) {
            break;
        }
    }
    return {cur_cont, container[cur_cont - 1].size()};
}

int Packing(Hangar& hang) {
    int n, l, w, time;
    ifstream in;
    in.open(PATH + hang.name_ + "_in.txt");
    in >> n >> l >> w >> time;
    vector<plane> boxes(n);
    for (int i = 0; i < n; ++i) {
        in >> boxes[i].height_ >> boxes[i].width_ >> boxes[i].time_ >> boxes[i].order_idx;
        boxes[i].idx = i;
    }
    container.resize(n);
    pair<int, int> best_score = solve(boxes, n, l, w, time);
    typedef bool (*comparator) (plane, plane);
    vector<vector<hangar>> ans = container;
    vector<comparator> cmp = {cmp0, cmp1, cmp2, cmp3, cmp4,
                              cmp5, cmp6, cmp7, cmp8};
    for (auto comp : cmp) {
        sort(boxes.begin(), boxes.end(), comp);
        for (auto& v : container) {
            v.clear();
        }
        pair<int, int> score = solve(boxes, n, l, w, time);
        if (score.second > best_score.second) {
            best_score = score;
            ans = container;
        }
        cout << score.second << '\n';
        sort(boxes.rbegin(), boxes.rend(), comp);
        for (auto& v : container) {
            v.clear();
        }
        score = solve(boxes, n, l, w, time);
        if (score.second > best_score.second) {
            best_score = score;
            ans = container;
        }
    }
    output(ans, best_score.first - 1, hang);
    return 0;
}
