#define _CRT_SECURE_NO_WARNINGS 1
//牛客-把字符串转换成整数
//将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0
//输入描述 :输入一个字符串, 包括数字字母符号, 可以为空
//输出描述 :如果是合法的数值表达则返回该数字，否则返回0
//输入
//+ 2147483647
//1a33
//输出
//2147483647
//0

#include <iostream>
#include <string>
using namespace std;
//未通过牛客所有测试
//输入：-2147483649
//输出：-2147483649
//但返回值是int型，返回了2147483647，不符合条件
int StrToInt(string str) 
{
	if (str.size() == 0)
		return 0;
	int i = 0;
	int flag = 1;//正数flag=1，负数flag=-1
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag = -1;
		i++;
	}
	while (str[i] == ' ')
		i++;
	long long ret = 0;
	for (; str[i] != '\0'; i++)
	{
		if (str[i] >= '0'&&str[i] <= '9')
			ret = ret * 10 + str[i] - '0';
		else
			return 0;
	}
	return (int)ret*flag;
}

int main()
{
	string s;
	while (getline(cin, s))
		cout << StrToInt(s) << endl;

	return 0;
}