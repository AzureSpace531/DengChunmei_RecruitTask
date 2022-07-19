/*
author: DCM
date : 2022/07/17
对头文件matrix.h的相关函数进行定义
*/
#include "matrix.h"
using std::endl;
using std::cout;
using std::istream;
const double EPS = 1e-10;


void Matrix::initialize() //初始化矩阵大小  动态分配内存
{   
	p = new double*[rows_num];  
	for (int i = 0; i < rows_num; ++i) {
		p[i] = new double[cols_num];  
	}
}


Matrix::Matrix(int rows, int cols)  //声明一个全0矩阵
{
	rows_num = rows;
	cols_num = cols;
	initialize();
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			p[i][j] = 0;
		}
	}
}


Matrix::Matrix(int rows, int cols, double value)  //声明一个值全部为value的矩阵
{
	rows_num = rows;
	cols_num = cols;
	initialize();
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			p[i][j] = value;
		}
	}
}

 
Matrix::~Matrix()  //定义虚构函数
{
 for (int i = 0; i < rows_num; ++i) {
			delete[] p[i];
		}
		delete[] p;
}

Matrix& Matrix::operator=(const Matrix& m)  //实现矩阵的复制
{
	if (this == &m) {
		return *this;
	}
 
	if (rows_num != m.rows_num || cols_num != m.cols_num) {
		for (int i = 0; i < rows_num; ++i) {
			delete[] p[i];
		}
		delete[] p;
		rows_num = m.rows_num;
		cols_num = m.cols_num;
		initialize();
	}
 
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			p[i][j] = m.p[i][j];
		}
	}
	return *this;
}

Matrix& Matrix::operator=(double *a)  //将数组的值传递给矩阵，此时矩阵大小已声明
{
	for(int i=0;i<rows_num;i++){
		for(int j=0;j<cols_num;j++){
			p[i][j]= *(a+i*cols_num+j);
		}
	}
	return *this;
}

Matrix& Matrix::operator+=(const Matrix& m)  //+=
{
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			p[i][j] += m.p[i][j];
		}
	}
	return *this;
}

Matrix& Matrix::operator-=(const Matrix& m)  //-=
{
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			p[i][j] -= m.p[i][j];
		}
	}
	return *this;
}

Matrix& Matrix::operator*=(const Matrix& m)  //*=  注意矩阵之间相乘的性质
{
	Matrix temp(rows_num, m.cols_num);
	for (int i = 0; i < temp.rows_num; i++) {
		for (int j = 0; j < temp.cols_num; j++) {
			for (int k = 0; k < cols_num; k++) {
				temp.p[i][j] += (p[i][k] * m.p[k][j]);
			}
		}
	}
	*this = temp;
	return *this;
}

Matrix Matrix::operator*(const Matrix & m)const  
{
	Matrix ba_M(rows_num,m.cols_num,0.0);
	for(int i=0;i<rows_num;i++){
		for(int j=0;j<m.cols_num;j++){
			for(int k=0;k<cols_num;k++){
				ba_M.p[i][j]+=(p[i][k]*m.p[k][j]);
			}
		}
	}
	return ba_M;
}

 
void Matrix::Show() const  //表示矩阵
{
	cout << rows_num <<" "<<cols_num<< endl;//显示矩阵的行数和列数
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			cout << p[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}


//读取矩阵行列数
int Matrix::row() const{
	return rows_num;
}
int Matrix::col() const{
	return cols_num;
}
//实现矩阵的转置
Matrix Matrix::T(const Matrix & m)
{	int col_size=m.col();
	int row_size=m.row();
	Matrix mt(col_size, row_size);
	for (int i = 0; i <row_size; i++) {
		for (int j = 0; j <col_size; j++) {
			mt.p[j][i] = m.p[i][j];
		}
	}
	return mt;
}


istream& operator>>(istream& is, Matrix& m)  //重载流提取运算符
{
	for (int i = 0; i < m.rows_num; i++) {
		for (int j = 0; j < m.cols_num; j++) {
			is >> m.p[i][j];
		}
	}
	return is;
}
 