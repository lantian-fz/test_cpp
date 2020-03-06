#define _CRT_SECURE_NO_WARNINGS 1
//把字符串转换成整数
//将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，但是string不符合数字要求时返回0)，
//要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0。
//输入描述 :输入一个字符串, 包括数字字母符号, 可以为空
//输出描述 :如果是合法的数值表达则返回该数字，否则返回0
//输入： +2147483647
//       1a33
//输出： 2147483647
//       0
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int StrToInt(string str) 
{
	int ret = 0;
	int i = 0;
	bool flag = true;
	if (str[0] == '-')
	{
		flag = false;
		str.erase(0, 1);
	}
	else if (str[0] == '+')
		str.erase(0, 1);
	if (str.size() == 0)
		return 0;
	while (str.size())
	{
		if (str[str.size() - 1]<'0' || str[str.size() - 1]>'9')
			return 0;
		int num = (int)pow(10, i);
		ret += (str[str.size() - 1] - '0') * num;
		str.erase(str.size() - 1, 1);
		i++;
	}
	if (flag == false)
		ret = -ret;

	return ret;
}

int main()
{
	string str;
	cin >> str;

	cout << StrToInt(str) << endl;

	return 0;
}