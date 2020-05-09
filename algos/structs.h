//
// Created by data_sapiens on 09.05.2020.
//

#include <string>
#include <map>

#ifndef ALGOS_STRUCTS_H
#define ALGOS_STRUCTS_H

struct Company {
    std::string name_;
    int start_period_, end_period_;
    double fine_;
};

struct Airplane {
    std::string name_;
    double width_, height_;
};

struct Hangar {
    std::string name_;
    double width_, height_;
    // сколько стоит выполнение того или иного ТО на том или ином самолете.
    // -1, если не выполняется.
    std::map<std::pair<std::string, std::string>, double> costs;
};

struct Order {
    std::string company_, airplane_, type_;
    int number_, time_, min_number_;
};

#endif //ALGOS_STRUCTS_H
