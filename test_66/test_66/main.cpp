#define _CRT_SECURE_NO_WARNINGS 1
//另类加法
//请编写一个函数，将两个数字相加。不得使用 + 或其他算数运算符。
//给定两个int A和B。请返回A＋B的值
//测试样例：1, 2     返回：3
#include <iostream>
using namespace std;

int addAB(int A, int B) 
{
	if (B == 0)
		return A;
	return addAB(A^B, (A&B) << 1);
}

int main()
{
	int a = 0;
	int b = 0;
	cin >> a >> b;

	cout << addAB(a, b) << endl;

	return 0;
}