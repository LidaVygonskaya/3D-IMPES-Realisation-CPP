#include <string>
#include <vector>
#include <cmath>
#include <fstream>
#include <map>
#include <iostream>
#include "Water.h"
#include "Oil.h"

//
// Created by lida on 07.03.2019.
//
class Layer {
    static constexpr float atm = 101325.0;
    double g = 9.80665;

    unsigned int componentsCount = 2;
    unsigned int dim = 3;

    // Начальное приближение
    static constexpr double delta_0 = 1000.0;

    // Количество ячеек
    static constexpr unsigned int N_x = 200;
    static constexpr unsigned int N_y = 200;
    static constexpr unsigned int N_z = 200;

    // Координаты
    static constexpr double x_0 = 0.0;
    static constexpr double x_N = 500.0;
    static constexpr double y_N = 500.0;
    static constexpr double z_N = 20.0;

    // Шаги по пространству
    static constexpr double h_x = (x_N - x_0) / (N_x - 1);
    static constexpr double h_y = (y_N - x_0) / (N_y - 1);
    static constexpr double h_z = (z_N - x_0) / (N_z - 1);
    std::vector<double> hArray {h_x, h_y, h_z};
    static constexpr double cellVolume = h_x * h_y * h_z;

    //==================Насыщенность=====================
    static constexpr double saturationWaterInit = 0.1;
    static constexpr double saturationOilInit = 1.0 - saturationWaterInit;

    //=================Давление==========================
    static constexpr double pressureWaterInit = 80.0 * atm;
    static constexpr double pressureOilInit = 80.0 * atm;

    //==================Параметры пласта=================
    static constexpr double fi_0 = 0.2;
    const double c_r = std::pow(10.0, -5) / atm;

    static constexpr double k = 1;
    static constexpr double k_x = k;
    static constexpr double k_y = k;
    static constexpr double k_z = k;
    std::vector<double> kArray {k_x, k_y, k_z};

    const double muOil = 10.0 * std::pow(10.0, -3);
    const double muWater = 10.0 * std::pow(10.0, -3);
    std::vector<double> muOilWater {muOil, muWater};

    Oil oil{};
    Water water{};
    std::vector<Component*> components {&oil, &water};

    //==================Скважинка==========================
    static constexpr double P_well_delivery = 130 * atm;  // injection
    static constexpr double P_well_extractive = 30 * atm; // production
    static constexpr double r_well = 0.108;
    static constexpr double s_well_water = 1.0;
    static constexpr double s_well_oil = 1.0 - s_well_water;

    # k, i, j
    wells = [(0, k, 100) for k in range(45, 56)]

    static constexpr bool productive = False
    static constexpr bool horizontal = True


    std::string folderName = "blabla";
    std::string pressureCapFilename = "Pcap(Sw).txt";

    double getH(const std::string &direction);
    std::map<double, double> getPressureCapGraph();
    double countPressureCap(double saturationWater);
    double countPressureCapGraphDer(double saturationWater);
    double countFi(double pressureOil);
};

double Layer::getH(const std::string &direction) {
    if (direction == "x")
        return h_x;
    if (direction == "y")
        return h_y;
    if (direction == "z")
        return h_z;
    return 0;
}

std::map<double, double> Layer::getPressureCapGraph() {
    // TODO: parse string by tabs here
    std::map<double, double> pressureCapGraph;
    std::ifstream file;
    std::string line;
    std::string partial;
    std::vector<std::string> tokens;
    file.open(pressureCapFilename);
    while (std::getline(file, line)) {
    }

    return pressureCapGraph;
}

double Layer::countPressureCap(double saturationWater) {
    return 0;
}

double Layer::countFi(double pressureOil) {
    return 0;
}

double Layer::countPressureCapGraphDer(double saturationWater) {
    return 0;
}
