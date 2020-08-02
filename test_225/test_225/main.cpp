#define _CRT_SECURE_NO_WARNINGS 1
//牛客-寻找字符串
//我们知道比较两个字符串是否相等可以用函数strcmp，如果两个字符串相等则返回0，否则返回其他值。
//那么，如何寻找一个字符串是否在另一个字符串中出现过，并且出现过多少次呢？
//例如：两个字符串分别为：abababa和aba, 那么aba在abababa中出现的次数为3。
//
//输入描述 :输入包含两行，第二行为要在第一行查找的字符串。字符串可能包含字母、数字、符号以及空格。
//输出描述 :输出为一个数字，表示第二行字符串在第一行出现的次数。
//输入
//i miss you!
//you
//输出
//1
//
//输入
//ababcababca
//ababca
//输出
//2

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	string s1,s2;
	while (getline(cin, s1), getline(cin, s2))
	{
		int count = 0;
		int pos = 0, index = 0;

		while (1)
		{
			index = s1.find(s2,pos);
			if (index == s1.npos)
				break;
			count++;
			pos = index;
			pos++;
		}
		cout << count << endl;
	}
}