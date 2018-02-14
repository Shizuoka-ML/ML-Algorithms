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
    /*** 1変数ニュートン法 ***/
    double Newtons_Method(double init, Polynomial poly);
};

#endif //ML_ALGORITHMS_NUMERICAL_ANALYSIS_H
