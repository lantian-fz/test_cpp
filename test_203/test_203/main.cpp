#define _CRT_SECURE_NO_WARNINGS 1
//ţ��-��ֵ�������η�-��ָoffer-11
//����һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η���
//��֤base��exponent��ͬʱΪ0������ʹ�ÿ⺯����ͬʱ����Ҫ���Ǵ�������

#include <iostream>
using namespace std;

//��ָoffer�𰸣���δͨ��ţ��
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
void main()
{
	double num = 3.14f;
	cout << Power(num, 2) << endl;
}