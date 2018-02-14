//
// Created by tonouchi on 2018/02/13.
//

#include "Numerical_Analysis.h"

Numerical_Analysis::Numerical_Analysis() {
    std::cout << "Create NumericalAnalysis" << std::endl;
}

double Numerical_Analysis::Newtons_Method(double init, Polynomial poly){
    std::cout << "Done newtons_method" << std::endl;
    double dx = 1;
    double x = init;
    double newX;

    int i = 1;
    while (dx > epsilon) {
        newX = x - poly.df(x) / poly.d2f(x);
        dx = abs(newX - x);
        x = newX;
        std::cout << "step-" << i << ": dx = " << dx << std::endl;
        i++;
    }
    return x;
}
