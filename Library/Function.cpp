//
// Created by tonouchi on 2018/02/13.
//

#include "Function.h"

/*** 1変数多項式 ***/
Polynomial::Polynomial(VectorXd b){
    std::cout << "Create Polynomial" << std::endl;
    n = b.size();
    a = b;
}

/*** 関数の値を出力する ***/
double Polynomial::f(double x) {
    double y = 0;
    for(int i = 0; i < n; i++) {
        y += a[i] * pow(x, i);
    }
    return y;
}

double Polynomial::df(double x) {
    return (f(x+dx) - f(x)) / dx;
}

double Polynomial::d2f(double x) {
    return (df(x+dx) -df(x)) / dx;
}


/*** 1次形式 ***/
LinearForm::LinearForm(VectorXd b) {
    std::cout << "Create LinearForm" << std::endl;
    n = b.size();
    A = b;
}

double LinearForm::f(VectorXd x) {
    return A.transpose() * x;
}

VectorXd LinearForm::rdf(VectorXd x) {
    return A;
}

VectorXd LinearForm::rd2f(VectorXd x) {
    return VectorXd::Zero(n);
}


/*** 2次形式 ***/
QuadraticForm::QuadraticForm(MatrixXd b) {
    std::cout << "Create QuadraticForm" << std::endl;
    n = b.rows();
    A = b;
}

double QuadraticForm::f(VectorXd x) {
    return x.transpose() * A * x;
}

VectorXd QuadraticForm::rdf(VectorXd x) {
    return 2 * A * x;
}

MatrixXd QuadraticForm::rd2f(VectorXd x) {
    return 2 * A;
}

/*** シルベスターの定理による導出 ***/
int QuadraticForm::isPositive() {
    MatrixXd tmp;
    double d;
    int res = 1;
    int i = 0;
    while(i < n) {
        tmp = A.block(0, 0, i+1, i+1);
        d = tmp.determinant();
        if(d < 0) {
            res = 0;
            break;
        } else if(d == 0) {
            res = 2;
        }
        i++;
    }
    return res;
}

/*** シルベスターの定理による導出 ***/
int QuadraticForm::isNegative() {
    MatrixXd tmp;
    double d;
    int res = 1, sign = -1;
    int i = 0;
    while(i < n) {
        tmp = A.block(0, 0, i+1, i+1);
        d = tmp.determinant() * pow(sign, i+1);
        if(d < 0) {
            res = 0;
            break;
        } else if(d == 0) {
            res = 2;
        }
        i++;
    }
    return res;
}


