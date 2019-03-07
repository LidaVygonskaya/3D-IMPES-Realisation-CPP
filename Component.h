//
// Created by lida on 07.03.2019.
//

#ifndef INC_3_DIM_IMPES_COMPONENT_H
#define INC_3_DIM_IMPES_COMPONENT_H
class Component {
    virtual double countRo(double pressureWater) = 0;
    virtual double count_k_r(double saturationWater) = 0;
};
#endif //INC_3_DIM_IMPES_COMPONENT_H
