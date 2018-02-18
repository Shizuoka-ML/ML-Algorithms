//
// Created by tonouchi on 2018/02/13.
//

#ifndef ML_ALGORITHMS_FUNCTION_H
#define ML_ALGORITHMS_FUNCTION_H

#include <Math.h>
#include <iostream>
#include "Eigen/Core"
#include "Eigen/Geometry"
#include "Eigen/LU"

using namespace Eigen;

/********************* 1変数多項式 *********************/
/**
 * @example a(n)*x^(n) + a(n-1)*x^(n-1) + ... + a(1)*x + a(0)
 * @param n : 項数
 * @param a : 係数ベクトル
 * @def f(x) : 入力を受け取り，関数値を返却
 * @def df(n, x) : 微分結果のベクトルを返却(導関数の定義による導出)
 * @def d2f(n, x) : 2階微分の結果を返却(2階導関数の定義)
 */
class Polynomial {
public:
    int n;
    VectorXd a;
    double dx = 1e-5;

public:
    explicit Polynomial(VectorXd b);
    double f(double x);
    double df(double x);
    double d2f(double x);
};


/********************* 1次形式 *********************/
/**
 * @example a1*x1 + a2*x2 + a3*x3 + ... + an*xn
 * @param n : 項数
 * @param A : 係数ベクトル
 * @def f(x) : ベクトルを受け取り，関数値を返却
 * @def rdf(n, x) : 偏微分結果のベクトルを返却
 * @def rd2f(n, x) : 2階偏微分の結果を返却
 */
class LinearForm {
public:
    int n;
    VectorXd A;

public:
    explicit LinearForm(VectorXd b);
    double f(VectorXd x);
    VectorXd rdf(VectorXd x);
    VectorXd rd2f(VectorXd x);
};


/********************* 2次形式 *********************/
/**
 * @example a*x^2 + (b+c)x*y + d*y^2
 * @param n : 行列の縦
 * @param A : 係数行列
 * @def f(x) : ベクトルを受け取り，関数値を返却
 * @def rdf(n, x) : 偏微分結果のベクトルを返却
 * @def rd2f(n, x) : 2階偏微分の結果を返却
 * @def isPositive() : 2次形式が正定値かどうかを返却(0:正定値でない, 1:正定値, 2:半正定値)
 * @def isNegative() : 2次形式が負定値かどうかを返却(0:負定値でない, 1:負定値, 2:半負定値)
 */
class QuadraticForm {
public:
    int n;
    MatrixXd A;

public:
    explicit QuadraticForm(MatrixXd b);
    double f(VectorXd x);
    VectorXd rdf(VectorXd x);
    MatrixXd rd2f(VectorXd x);
    int isPositive();
    int isNegative();
};

#endif //ML_ALGORITHMS_FUNCTION_H



