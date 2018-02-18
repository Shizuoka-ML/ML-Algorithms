//
// Created by tonouchi on 2018/02/13.
//

#ifndef ML_ALGORITHMS_NUMERICAL_ANALYSIS_H
#define ML_ALGORITHMS_NUMERICAL_ANALYSIS_H

#include <iostream>
#include <Math.h>
#include "Function.h"

class Numerical_Analysis {
public:
    double epsilon = 1e-4;
    double init = 7;

    Numerical_Analysis();

    /*** 1変数のニュートン法 ***/
    double Newtons_Method(Polynomial poly);
    /*** 1変数の勾配法 ***/
    double Gradient_Method(Polynomial poly);

};

#endif //ML_ALGORITHMS_NUMERICAL_ANALYSIS_H
