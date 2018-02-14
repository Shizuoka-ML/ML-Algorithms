//
// Created by tonouchi on 2018/02/13.
//

#ifndef ML_ALGORITHMS_NUMERICAL_ANALYSIS_H
#define ML_ALGORITHMS_NUMERICAL_ANALYSIS_H

#include <iostream>
#include "Function.h"

class Numerical_Analysis {
public:
    double epsilon = 1e-4;

    Numerical_Analysis();
    double newtons_method(double init, Function func);
};

#endif //ML_ALGORITHMS_NUMERICAL_ANALYSIS_H
