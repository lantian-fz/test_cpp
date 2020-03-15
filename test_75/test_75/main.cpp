#define _CRT_SECURE_NO_WARNINGS 1
//参数解析
//在命令行输入如下命令：xcopy /s c:\ d:\，
//各个参数如下：参数1：命令字xcopy    参数2：字符串/s     参数3：字符串c:\    参数4 : 字符串d:\
//请编写一个参数解析程序，实现将命令行各个参数解析出来。
//解析规则：1.参数分隔符为空格
//          2.对于用“”包含起来的参数，如果中间有空格，不能解析为多个参数。
//比如在命令行输入xcopy /s “C:\program files” “d:\”时，参数仍然是4个，第3个参数应该是
//字符串C : \program files，而不是C : \program，注意输出参数时，需要将“”去掉，引号不存在嵌套情况。
//		  3.参数不定长
//		  4.输入由用例保证，不会出现不符合要求的输入
//输入描述 :输入一行字符串，可以有空格
//输出描述 :输出参数个数，分解后的参数，每个参数都独占一行
//输入： xcopy / s c : \\ d:\\
//输出： 4
//       xcopy
//       /s
//       c:\\
//       d:\\

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Print(string &str)
{
	vector<string> arr;
	auto it_s = str.begin();
	while (it_s != str.end())
	{
		auto it_tmp = it_s;
		if (*it_s != '"')
		{
			while (it_s!=str.end() && *it_s != ' ')
				it_s++;
			string tmp(it_tmp, it_s);
			arr.push_back(tmp);
			if (it_s != str.end())
				it_s++;
			else
				break;
		}
		else
		{
			it_s++;
			while (/*it_s != str.end() && */*it_s != '"')
				it_s++;
			//it_s--;
			it_tmp++;
			string tmp(it_tmp, it_s);
			arr.push_back(tmp);
			it_s++;
			if (it_s != str.end())
				it_s++;
			else
				break;
		}
	}
	cout << arr.size() << endl;
	for (size_t i = 0; i<arr.size(); i++)
		cout << arr[i] << endl;
}

int main()
{
	string str;
	while (getline(cin, str))
	{
		Print(str);
	}


	return 0;
}