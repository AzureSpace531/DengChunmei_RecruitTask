 
 /*
 定义一个矩阵类，完成基本的矩阵运算，
 如矩阵加法，矩阵减法，矩阵乘法，数乘，
 矩阵转置，并给出实例演示。
 */
#include "matrix.h"
using namespace std;
 
int main()
{
	Matrix A = Matrix(3, 3);
	cout<<"请输入矩阵元素：";
	cin >> A;
	Matrix B = Matrix(3, 3);
	cin >> B;
	A += B;
	A.Show();
	return 0;
}
 