/*
author: DCM
date :  2022/07/17
*/
/*
 定义一个矩阵类，完成基本的矩阵运算，
 如矩阵加法，矩阵减法，矩阵乘法，数乘，
 矩阵转置，并给出实例演示。
 */
 
#ifndef __MATRIX_CLL_H__
#define __MATRIX_CCL_H__
#include <cmath>
#include <iostream>
#include <stdlib.h>
 
class Matrix {
private:
	int rows_num, cols_num;
	double **p;
	void initialize();   //初始化矩阵,定为私有函数
 
public:
	Matrix(int, int);
	Matrix(int, int, double);  //预配分空间
	virtual ~Matrix();  //析构函数应当是虚函数，因为Matrix类会用作基类
	Matrix& operator=(const Matrix&);  //矩阵的复制
	Matrix& operator=(double *);       //将数组的值传给矩阵
	Matrix& operator+=(const Matrix&);  //矩阵加法
	Matrix& operator-=(const Matrix&);  //矩阵减法
	Matrix& operator*=(const Matrix&);  //矩阵乘法
	Matrix operator*(const Matrix & m)const;
	int row() const;
	int col() const;
	static Matrix T(const Matrix & m);//矩阵转置的实现,且不改变矩阵
	void Show() const; 
	friend std::istream& operator>>(std::istream&, Matrix&);  //实现矩阵的输入
};
 
 
#endif