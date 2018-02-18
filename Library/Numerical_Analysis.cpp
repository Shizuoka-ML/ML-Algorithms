//
// Created by tonouchi on 2018/02/13.
//

#include "Numerical_Analysis.h"

Numerical_Analysis::Numerical_Analysis() {
    std::cout << "Create NumericalAnalysis" << std::endl;
}

double Numerical_Analysis::Newtons_Method(Polynomial poly){
    std::cout << "Do Newtons_Method" << std::endl;
    double dx = 1;
    double x = init;
    double newX;

    int i = 0;
    while (dx > epsilon) {
        std::cout << "step-" << i << ": dx = " << dx << std::endl;
        newX = x - poly.df(x) / poly.d2f(x);
        dx = abs(newX - x);
        x = newX;
        i++;
    }
    std::cout << "step-" << i << ": dx = " << dx << std::endl;
    return x;
}

double Numerical_Analysis::Gradient_Method(Polynomial poly) {
    std::cout << "Do Gradient_Method" << std::endl;
    double h = 1e-2;
    double x = init;
    double X1, X2, df = 1;
    int sgn;

    int i = 0;
    while(df > epsilon) {
        df = poly.df(x);
        std::cout << "step-" << i++ << ": df = " << df << std::endl;
        sgn = (df>0)-(df<0);
        h = sgn * abs(h);
        X1 = x, X2 = x+h;
        if(poly.f(X1) < poly.f(X2)) {
            while(poly.f(X1) < poly.f(X2)) {
                h = h*2, X1 = X2, X2 = X1+h;
            }
            x = X1, h = h/2;
        } else {
            while(poly.f(X1) > poly.f(X2)) {
                h = h/2, X2 = X2-h;
            }
            x = X2, h = h*2;
        }
        df = abs(poly.df(x));
    }
    std::cout << "step-" << i << ": df = " << df << std::endl;
    return x;
}
