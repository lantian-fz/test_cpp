#define _CRT_SECURE_NO_WARNINGS 1
//删除重复字符
//链接：https://www.nowcoder.com/questionTerminal/c4ea1f2263434861aef111aa44a5b064
//来源：牛客网
//牛牛有一个由小写字母组成的字符串s,在s中可能有一些字母重复出现。比如在"banana"中,字母'a'和字母'n'分别出现了三次和两次。
//但是牛牛不喜欢重复。对于同一个字母,他只想保留第一次出现并删除掉后面出现的字母。请帮助牛牛完成对s的操作。
//输入描述:输入包括一个字符串s,s的长度length(1 ≤ length ≤ 1000),s中的每个字符都是小写的英文字母('a' - 'z')
//输出描述:输出一个字符串,表示满足牛牛要求的字符串
//
//输入：banana
//输出：ban

#include <iostream>
#include <string>
#include <map>
using namespace std;

void DeDuplication_1(string s)
{
	string ret = "";
	map<char, int> book;
	for (int i = 0; i < s.size(); i++)
	{
		if (!book.count(s[i]))
		{
			ret += s[i];
			book[s[i]] = 1;
		}
	}
	cout << ret;
}

void DeDuplication_2(string s)
{
	int arr[26] = { 0 };
	for (auto e : s)
	{
		if (arr[e - 'a'] == 0)
			cout << e;
		arr[e - 'a']++;
	}
}

int main()
{
	string s;
	while (cin >> s)
		DeDuplication_2(s);
}

//链接：https://www.nowcoder.com/questionTerminal/c4ea1f2263434861aef111aa44a5b064
//来源：牛客网
//
//#include<iostream>
//#include<string>
//#include<map>
//using namespace std;
//int main(){
//	string x, res = "";
//	map<char, int> book;
//	int i;
//	for (cin >> x, i = 0; i<x.length(); i++)
//	if (!book.count(x[i])) res += x[i], book[x[i]] = 1;
//	cout << res;
//}