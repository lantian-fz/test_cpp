#define _CRT_SECURE_NO_WARNINGS 1

//题目描述
//有一个N大小的数组, 数组里的数字在1到N之间, 有些数字出现2次, 有些数字出现1次.请找出所有出现2次的数字.
//输入描述
//每个输入包含一个测试用例。每个测试用例的包含N个整数 （1 <= N <= 100），随机生成数据，保证相同数字不会出现3次以及3次以上
//题目保证所有输入合法。
//输出描述
//输出一个序列，包括所有出现过2次的数字
//输入示例
//1 2 5 2 3 4 8 5 4
//输出示例
//2 5 4

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//将字符串转换为数组
void StrNum(string s,vector<int>& arr)
{
	auto it = s.begin();
	while (it != s.end())
	{
		string num = "";
		while (it != s.end() && (*it != ' '))
		{
			num += *it;
			it++;
		}
		int n = atoi(num.c_str());//字符串转数字
		arr.push_back(n);
		if (it != s.end())
			it++;
	}
}

//找到出现过两次的数字
vector<int> fun(vector<int> arr)
{
	vector<int> num(arr.size() + 1, 0);
	for (int i = 0; i < arr.size(); i++)
		num[arr[i]]++;
	vector<int> ret;
	for (int i = 0; i < arr.size(); i++)
	{
		if (num[arr[i]] == 2)
		{
			ret.push_back(arr[i]);
			num[arr[i]] = 0;
		}
	}
	return ret;
}

void main()
{
	string s;
	while (getline(cin, s))
	{
		vector<int> arr;
		StrNum(s, arr);

		vector<int> tmp = fun(arr);
		cout << tmp[0];
		for (int i = 1; i < tmp.size();i++)
			cout << " " << tmp[i];
		cout << endl;
	}
}