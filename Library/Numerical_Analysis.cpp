//
// Created by tonouchi on 2018/02/13.
//

#include "Numerical_Analysis.h"

Numerical_Analysis::Numerical_Analysis() {
    std::cout << "Create NumericalAnalysis" << std::endl;
}

double Numerical_Analysis::newtons_method(double init, Function func){
    double dx = 1;
    double x = init;
    double newX;

    std::cout << "Done newtons_method" << std::endl;

    int i = 1;
    while (dx > epsilon) {
        newX = x - func.df(x) / func.d2f(x);
        dx = abs(newX - x);
        x = newX;
        std::cout << "step-" << i << ": dx = " << dx << std::endl;
        i++;
    }

    return x;
}
