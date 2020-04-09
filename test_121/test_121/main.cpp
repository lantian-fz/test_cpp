#define _CRT_SECURE_NO_WARNINGS 1
//收件人列表
//NowCoder每天要给许多客户写电子邮件。正如你所知，如果一封邮件中包含多个收件人，收件人姓名之间
//会用一个逗号和空格隔开；如果收件人姓名也包含空格或逗号，则姓名需要用双引号包含。
//现在给你一组收件人姓名，请你帮他生成相应的收件人列表。
//输入描述 :输入包含多组数据。每组数据的第一行是一个整数n(1≤n≤128)，表示后面有n个姓名。
//          紧接着n行，每一行包含一个收件人的姓名。姓名长度不超过16个字符。
//输出描述 :对应每一组输入，输出一行收件人列表。
//输入
//3
//Joe
//Quan, William
//Letendre, Bruce
//2
//Leon
//Kewell
//输出
//Joe, "Quan, William", "Letendre,Bruce"
//Leon, Kewell

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n = 0;
	int j = 0;
	while (cin >> n)
	{
		j++;
		cin.get();
		string ret;
		for (int i = 0; i < n; i++)
		{
			string s;
			getline(cin, s);
			if (s.find(",") == -1 && s.find(" ") == -1)
			{
				ret += s;
				if (i != n - 1)
					ret+=", ";//逗号后面要有空格，不然无法通过牛客全部用例
			}
			else
			{
				ret += '\"';
				ret += s;
				if (i == n - 1)
					ret += '\"';
				else
					ret += "\", ";
			}
		}
		//cout << ret << endl;
		if (j == 1)
			cout << ret;
		else
			cout << endl << ret;
	}

	return 0;
}

//void fun(vector<string> &arr)
//{
//	string ret;
//	for (size_t i = 0; i < arr.size(); i++)
//	{
//		int x = arr[i].find(",");
//		int y = arr[i].find(" ");
//		if (x == -1 && y == -1)
//		{
//			ret += arr[i];
//			if (i != arr.size()-1)
//				ret += ",";
//		}
//		else
//		{
//			ret += "\"";
//			ret += arr[i];
//			if (i == arr.size() - 1)
//				ret += "\"";
//			else
//				ret += "\",";
//		}
//	}
//	cout << ret << endl;
//}
//
//int main()
//{
//	int n = 0;
//	int j = 0;
//	while (cin >> n)
//	{
//		vector<string> arr;
//		cin.get();
//		for (int i = 0; i < n;i++)
//		{
//			string s;
//			getline(cin, s);
//			arr.push_back(s);
//		}
//		fun(arr);
//	}
//
//	return 0;
//}