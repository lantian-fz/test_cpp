#define _CRT_SECURE_NO_WARNINGS 1
//查找输入整数二进制中1的个数
//请实现如下接口
//public   static   int  findNumberOf1(int num)
//{
//	return  0;
//} 譬如：输入5 ，5的二进制为101，输出2
//输入描述 :输入一个整数
//输出描述 :计算整数二进制中1的个数
//输入: 5
//输出: 2
#include <iostream>
using namespace std;

int findNumberOf1(int num)
{
	int ret = 0;
	if (num < 0)
	{
		num = -num;
		ret++;
	}
	for (int i = 0; i<32; i++)
	{
		if (((num >> i) & 1) == 1)
			ret++;
	}
	return ret; 
}

int main()
{
	int n = 0;
	while (cin >> n)
		cout << findNumberOf1(n) << endl;

	return 0;
}