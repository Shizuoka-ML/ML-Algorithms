#include <iostream>
#include "Library/Function.h"
#include "Library/Numerical_Analysis.h"

using namespace Eigen;

int main() {
    /*** Functionの動作確認 ***/
    VectorXd a(3); // 係数ベクトル
    a << -4, 4, -1;
    Polynomial poly(a);
    double x = 2;
    double y = poly.f(x);
    double dy = poly.df(x);
    double d2y = poly.d2f(x);
    std::cout << "Function-y: " << y << std::endl;
    std::cout << "Function-dy: " << dy << std::endl;
    std::cout << "Function-d2y: " << d2y << "\n" << std::endl;

    /*** 1変数のニュートン法の動作確認 ***/
    Numerical_Analysis na;
    x = na.Newtons_Method(poly);
    std::cout << "Newton's Method(Polynomial) resX: " << x << std::endl;
    std::cout << "Newton's Method(Polynomial) resY: " << poly.f(x) << "\n" << std::endl;

    /*** 1変数の勾配法の動作確認 ***/
    x = na.Gradient_Method(poly);
    std::cout << "Gradient Method(Polynomial) resX: " << x << std::endl;
    std::cout << "Gradient Method(Polynomial) resY: " << poly.f(x) << "\n" << std::endl;


    /*** 1次形式の動作確認 ***/
    VectorXd b(3);
    b << 1, 1, 1;
    LinearForm lf(b);
    VectorXd X(3);
    X << 2, 3, 4;
    double f = lf.f(X);
    VectorXd rdf = lf.rdf(X);
    VectorXd rd2f = lf.rd2f(X);
    std::cout << "LinearForm-f: " << f << std::endl;
    std::cout << "LinearForm-rdf:\n" << rdf << std::endl;
    std::cout << "LinearForm-r2df:\n" << rd2f << "\n" << std::endl;

    /*** 2次形式の動作確認 ***/
    MatrixXd m(2, 2);
    m << 3, 1,
            1, 2;
    VectorXd X2(2);
    X2 << 2, 3;
    QuadraticForm qf(m);
    double quad_f = qf.f(X2);
    VectorXd quad_rdf = qf.rdf(X2);
    MatrixXd quad_rd2f = qf.rd2f(X2);
    std::cout << "QuadraticForm-f: " << quad_f << std::endl;
    std::cout << "QuadraticForm-rdf:\n" << quad_rdf << std::endl;
    std::cout << "QuadraticForm-rd2f:\n" << quad_rd2f << std::endl;
    int pos = qf.isPositive();
    int neg = qf.isNegative();
    if (pos == 0 && neg == 0)
        std::cout << "Indefinite" << std::endl;
    else if(pos == 1)
        std::cout << "Positive-definite" << std::endl;
    else if(pos == 2)
        std::cout << "Positive-semidefinite" << std::endl;
    else if(neg == 1)
        std::cout << "Negative-definite" << std::endl;
    else if(neg == 2)
        std::cout << "Negative-semidefinite" << std::endl;

    std::cout << "\nEND" << std::endl;


    return 0;
}



