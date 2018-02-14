#include <iostream>
#include "Library/Function.h"
#include "Library/Numerical_Analysis.h"

using namespace Eigen;

int main() {
    /*** Functionの動作確認 ***/
    VectorXd a(3); // 係数ベクトル
    a << 4, -4, 1;
    Polynomial poly(a);
    double x = 2;
    double y = poly.f(x);
    double dy = poly.df(x);
    double d2y = poly.d2f(x);
    std::cout << "Function-y: " << y << std::endl;
    std::cout << "Function-dy: " << dy << std::endl;
    std::cout << "Function-d2y: " << d2y << "\n" << std::endl;

    /*** 1変数ニュートン法の動作確認 ***/
    Numerical_Analysis na;
    x = na.Newtons_Method(7, poly);
    std::cout << "newtons method(Function) resX: " << x << std::endl;
    std::cout << "newtons method(Function) resY: " << poly.f(x) << "\n" << std::endl;

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
    m << 1, 1,
            2, 2;
    VectorXd X2(2);
    X2 << 2, 3;
    QuadraticForm qf(m);
    f = qf.f(X2);
    rdf = qf.rdf(X2);
    rd2f = qf.rd2f(X2);
    std::cout << "QuadraticForm-f: " << f << std::endl;
    std::cout << "QuadraticForm-rdf:\n" << rdf << std::endl;
    std::cout << "QuadraticForm-rd2f:\n" << rd2f << std::endl;


    return 0;
}



