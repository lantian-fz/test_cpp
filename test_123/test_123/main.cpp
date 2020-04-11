#define _CRT_SECURE_NO_WARNINGS 1
//抄送列表
//NowCoder每天要处理许多邮件，但他并不是在收件人列表中，有时候只是被抄送。他认为这些抄送的邮件
//重要性比自己在收件人列表里的邮件低，因此他要过滤掉这些次要的邮件，优先处理重要的邮件。
//现在给你一串抄送列表，请你判断目标用户是否在抄送列表中。
//输入描述 :输入有多组数据，每组数据有两行。
//第一行抄送列表，姓名之间用一个逗号隔开。如果姓名中包含空格或逗号，则姓名包含在双引号里。总长度不超过512个字符。
//第二行只包含一个姓名，是待查找的用户的名字（姓名要完全匹配）。长度不超过16个字符。
//输出描述 :
//如果第二行的名字出现在收件人列表中，则输出“Ignore”，表示这封邮件不重要；否则，输出“Important!”，表示这封邮件需要被优先处理。
//输入
//Joe, Kewell, Leon
//Joe
//"Letendre, Bruce", Joe, "Quan, William"
//William
//输出
//Ignore
//Important!

#include <iostream>
#include <string>
using namespace std;

bool fun(string s1, string s2)
{
	auto ita = s1.begin();
	auto itb = ita;

	while (ita != s1.end())
	{
		if (*itb == '\"')
		{
			itb++;
			ita++;
			while (itb != s1.end() && *itb != '\"')
				itb++;
			string tmp(ita, itb);
			if (tmp == s2)
				return true;
			itb++;
		}
		else 
		{
			while (itb != s1.end() && *itb != ',')
				itb++;
			string tmp(ita, itb);
			if (tmp == s2)
				return true;
		}
		if (*itb == ',')
		{
			ita++;
			itb++;
		}
		ita = itb;
	}

	return false;
}

int main()
{
	string s1, s2;
	while (getline(cin, s1), getline(cin, s2))
	{
		if (fun(s1, s2))
			cout << "Ignore" << endl;
		else
			cout << "Important!" << endl;
	}

	return 0;
}


//int main()
//{
//	string s, res;
//	while (getline(cin, s))
//	{
//		getline(cin, res);
//		bool sta = false;
//		for (int i = 0; i < s.length(); i++)
//		{
//			string t;
//			if (s[i] == '"')
//			{
//				i++;
//				while (i<s.length() && s[i] != '"')
//				{
//					t += s[i];
//					i++;
//				}
//				if (t == res)
//				{
//					sta = true;
//					break;
//				}
//			}
//			else if (s[i] != ',')
//			{
//				while (i<s.length() && s[i] != ',')
//				{
//					t += s[i];
//					i++;
//				}
//				if (t == res)
//				{
//					sta = true;
//					break;
//				}
//			}
//		}
//		if (sta == true)
//			cout << "Ignore" << endl;
//		else
//			cout << "Important!" << endl;
//	}
//	return 0;
//}