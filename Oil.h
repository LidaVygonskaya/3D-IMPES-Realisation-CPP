//
// Created by lida on 07.03.2019.
//

#ifndef INC_3_DIM_IMPES_OIL_H
#define INC_3_DIM_IMPES_OIL_H
#include <cmath>
#include "Component.h"

class Oil:public Component {
    static constexpr double atm = 101325.0;
    static constexpr double P_02 = 80 * atm;
    static constexpr double roOil_0 = 900.0;
    const double cFOil = std::pow(10.0, -4) / atm;

public:
    double countRo(double pressureOil) override {
        return roOil_0 * (1.0 + cFOil * (pressureOil - P_02));
    }

    double count_k_r(double saturationOil) override {
        return std::pow(saturationOil, 2);
    }
};
#endif //INC_3_DIM_IMPES_OIL_H
