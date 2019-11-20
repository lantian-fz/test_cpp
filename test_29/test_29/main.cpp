#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
using namespace std;
//给定一个字符串和一个整数 k，你需要对从字符串开头算起的每个 2k 个字符的前k个字符进行反转。
//如果剩余少于 k 个字符，则将剩余的所有全部反转。如果有小于 2k 但大于或等于 k 个字符，
//则反转前 k 个字符，并将剩余的字符保持原样。
//示例 :
//
//输入 : s = "abcdefg", k = 2
//输出 : "bacdfeg"
//要求 :
//	该字符串只包含小写的英文字母。
//	给定字符串的长度和 k 在[1, 10000]范围内。

void reverse(string &s,int k)
{
	int i, j;
	for (i = 0, j = k-1; i < j; i++, j--)
	{
		swap(s[i], s[j]);
	}
}
string reverseStr(string s, int k) 
{
	int sz = s.size();
	if (k>sz)
		return s;
	int i = 0;
	string tmp;
	tmp.resize(10000);
	while (i <= sz)
	{
		if (sz - i < k)
		{
			//剩下的全部反转

			int x = i;
			for (int j = 0; i < sz; i++, j++)
			{
				tmp[j] = s[i];
			}
			reverse(tmp,k);
			for (int j = 0; tmp[j] != '\0'; j++)
			{
				s[x++] = tmp[j];
			}
		}
		else
		{
			//每2k个字符的前k个字符反转

			int x = i;
			for (int j = 0; j < k; j++, i++)
			{
				tmp[j] = s[i];
			}
			reverse(tmp,k);
			for (int j = 0; j < k; j++)
			{
				s[x++] = tmp[j];
				i++;
			}
		}
	}
	return s;
}

int main()
{
	string s = "abcdefg";
	string s2 = reverseStr(s, 2);
	cout << s2 << endl;

	return 0;
}