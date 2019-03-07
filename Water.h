//
// Created by lida on 07.03.2019.
//

#ifndef INC_3_DIM_IMPES_WATER_H
#define INC_3_DIM_IMPES_WATER_H
#include <cmath>
#include "Component.h"

class Water: public Component {
    static constexpr double atm = 101325.0;
    static constexpr double P_02 = 80 * atm;
    static constexpr double roWater_0 = 900.0;
    const double cFWater = std::pow(10.0, -4) / atm;

public:
    double countRo(double pressureWater) override {
        return roWater_0 * (1.0 + cFWater * (pressureWater - P_02));
    }

    double count_k_r(double saturationWater) override {
        return std::pow(saturationWater, 2);
    }
};
#endif //INC_3_DIM_IMPES_WATER_H
