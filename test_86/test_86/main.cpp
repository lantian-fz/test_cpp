#define _CRT_SECURE_NO_WARNINGS 1
//字符串通配符
//问题描述：在计算机中，通配符一种特殊语法，广泛应用于文件搜索、数据库、正则表达式等领域。现要求各位实现字符串通配符的算法。
//要求：实现如下2个通配符：
//      *：匹配0个或以上的字符（字符由英文字母和数字0 - 9组成，不区分大小写。下同）
//      ？：匹配1个字符
//输入描述 :先输入一个带有通配符的字符串，再输入一个需要匹配的字符串
//输出描述 :返回匹配的结果，正确输出true，错误输出false
//输入: te?t*.*
//      txt12.xls
//输出: false
#include <iostream>
#include <string>
using namespace std;
//牛客通过了全部测试用例
//不知道是测试用例不够完整还是我理解的有问题，*可以匹配 0个字符，但我的用我的代码运行用例：
//abcde*ef
//abcdeef
//运行结果为：false
//不应该是true吗？

bool fun(string &s1, string &s2)
{
	int i = 0;//通配符字符串下标
	int j = 0;//匹配字符串下标
	while (s1[i] != '\0' && s2[j] != '\0')
	{
		if (s1[i] == s2[j] || s1[i]=='?')
		{
			i++;
			j++;
			continue;
		}
		else if (s1[i] == '*')
		{
			i++;
			if (s1[i] == '\0')
				return true;
			while (s1[i] == '?')
				i++;
			int index = s2.find(s1[i], j+1);//有bug，*匹配0个字符时abcde*ef abcdeef
			if (index == -1)
				return false;
			else
				j = index;
		}
		else
			return false;
	}
	return true;
}

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		if (fun(s1, s2))
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}