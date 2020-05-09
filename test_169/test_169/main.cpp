#define _CRT_SECURE_NO_WARNINGS 1
//力扣-38.外观数列
//「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。前五项如下：
//1.     1
//2.     11         1 被读作  "one 1"  ("一个一"), 即 11。
//3.     21         11 被读作 "two 1s" ("两个一"）, 即 21。
//4.     1211       21 被读作 "one 2", "one 1" （"一个二", "一个一"), 即 1211。
//5.     111221
//给定一个正整数 n（1 ≤ n ≤ 30），输出外观数列的第 n 项。注意：整数序列中的每一项将表示为一个字符串。
//示例 1:输入: 1            输出: "1"        
//
//示例 2:
//输入: 4
//输出: "1211"
//解释：当 n = 3 时，序列是 "21"，其中我们有 "2" 和 "1" 两组，"2" 可以读作 "12"，也就是出现频次 = 1 而 值 = 2；
//类似 "1" 可以读作 "11"。所以答案是 "12" 和 "11" 组合在一起，也就是 "1211"。

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string countAndSay(int n) 
{
	if (n == 1)
		return "1";
	string s = "1";
	//string tmp = s;
	for (int i = 1; i < n; i++)
	{
		string tmp;

		for (size_t j = 0; j < s.size(); j++)
		{
			int count = 0;
			int x = j;
			char t = s[j];
			while (s[j] == t)
			{
				count++;
				j++;
			}
			tmp += to_string(count) + t;
			if (j <= s.size() - 1)
				j = x + 1;
		}
		s = tmp;
	}


	return s;
}

int main()
{
	int n = 0;
	while (cin >> n)
		cout << countAndSay(n) << endl;

	return 0;
}