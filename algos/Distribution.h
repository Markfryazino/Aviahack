//
// Created by data_sapiens on 09.05.2020.
//

#include <vector>
#include <string>
#include "structs.h"
#include "ParamSet.h"

#ifndef ALGOS_DISTRIBUTION_H
#define ALGOS_DISTRIBUTION_H

struct Coords {
    std::string hangar_;
    double x_, y_;
};

struct HandledOrder {
    Order order_;
    int taken_number_;
    // Для каждого самолета, который мы берем чинить, содержит вектор с разными его расположениями.
    // Двумерность нужна для того, чтобы перемещать самолеты внутри ангара.
    std::vector<std::vector<std::pair<Coords, int>>> planes_;
};

struct HandledHangar {
    Hangar hangar_;
    std::vector<std::vector<std::pair<Airplane, Coords>>> planes_;
};

class Distribution {
public:
    double score_;
    ParamSet params_;
    std::vector<HandledOrder> orders_;
};


#endif //ALGOS_DISTRIBUTION_H
