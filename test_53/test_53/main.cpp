#define _CRT_SECURE_NO_WARNINGS 1
//将一句话的单词进行倒置，标点不倒置。比如 I like beijing.经过函数后变为：beijing. like I
//输入描述 :每个测试输入包含1个测试用例： I like beijing.输入用例长度不超过100
//输出描述 :依次输出倒置之后的字符串, 以空格分割
//输入: I like beijing.
//输出: beijing. like I

//#include <iostream>
//#include <string>
//using namespace std;
//// cin读取string时自动会被空格分隔开，用另一个字符串存储进行逆序输出
//int main()
//{
//	string s1, s2;
//	cin >> s2;
//	while (cin >> s1)
//		s2 = s1 + " " + s2;
//	cout << s2 << endl;
//	return 0;
//}
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string& Reverse(string &s)
{
	reverse(s.begin(), s.end());
	string::iterator it1 = s.begin();
	string::iterator it2 = s.begin();
	int n = 0;
	while (it1 != s.end())
	{
		if (*it1 == ' ')
		{
			reverse(it2, it2 + n);
			it2 += n+1;
			n = 0;
			it1++;
			continue;
		}
		if (it1 + 1 == s.end())
		{
			reverse(it2, s.end());
			break;
		}
		it1++;
		n++;
	}

	return s;
}

int main()
{
	string s;
	getline(cin, s);
	cout << Reverse(s) << endl;

	return 0;
}