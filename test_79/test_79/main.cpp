#define _CRT_SECURE_NO_WARNINGS 1
//牛客-二进制中1的个数-剑指offer-10
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
//右移要判断的数
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

//左移1，不用判断正负
int findNumberOfl_2(int num)
{
	size_t i = 1;
	int ret = 0;
	while (i)
	{
		if (num&i)
			++ret;
		i <<= 1;
	}
	return ret;
}

//把整数和它减1做位与运算，相当于把它最右边的1变成0，那么这个整数的二进制中有多少个1，就可以进行多少次这样的运算
int findNumberOfl_3(int num)
{
	int ret = 0;
	while (num)
	{
		++ret;
		num = (num - 1)&num;
	}
	return ret;
}

int main()
{
	int n = 0;
	while (cin >> n)
		cout << findNumberOfl_3(n) << endl;

	return 0;
}