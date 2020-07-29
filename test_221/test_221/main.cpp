#define _CRT_SECURE_NO_WARNINGS 1
//力扣-反转字符串2
//给定一个字符串 s 和一个整数 k，你需要对从字符串开头算起的每隔 2k 个字符的前 k 个字符进行反转。
//如果剩余字符少于 k 个，则将剩余字符全部反转。
//如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
//
//输入 : s = "abcdefg", k = 2     输出 : "bacdfeg"

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string reverseStr(string s, int k)
{
	if (s.empty() || k == 1)
		return s;
	int len = s.size();
	for (int i = 0; i < len; i += 2 * k)
	{
		if (len - i < 2 * k)//当剩余字符少于2*k个时，
		{
			if (len - i < k)//剩余字符全部反转
				reverse(s.begin() + i, s.end());
			else
				reverse(s.begin() + i, s.begin() + i + k);//反转前k个字符
			return s;
		}
		else
			reverse(s.begin() + i, s.begin() + i + k);
	}
	return s;
}
void main()
{
	string s = "abcdefg";
	cout << reverseStr(s, 2) << endl;
}