#define _CRT_SECURE_NO_WARNINGS 1
//ţ��-��ֵ�������η�-��ָoffer-11
//����һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η���
//��֤base��exponent��ͬʱΪ0������ʹ�ÿ⺯����ͬʱ����Ҫ���Ǵ�������

#include <iostream>
using namespace std;

//��ָoffer�𰸣���δͨ��ţ��,û�п���exponentΪ���������
double Power(double base, int exponent) 
{
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;
	double ret = Power(base, exponent >> 1);//>>�൱�ڳ�2����Ч�ʸ���
	ret *= ret;
	if ((exponent & 1) == 1)//�ж���ż����ȡģ�ٶȸ���
		ret *= base;
	return ret;
}

double Power_2(double base, int exponent)
{
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;
	bool flag = false;
	if (exponent < 0)
	{
		exponent = -exponent;
		flag = true;
	}
	double ret = 1.0f;
	for (int i = 0; i < exponent; i++)
		ret *= base;
	if (flag)
		ret = 1 / ret;
	return ret;
}
void main()
{
	double num = 3.14f;
	cout << Power_2(num, -2) << endl;
}