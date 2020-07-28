#define _CRT_SECURE_NO_WARNINGS 1
//剑指offer-字符串的排列
//输入一个字符串, 按字典序打印出该字符串中字符的所有排列。例如输入字符串abc, 
//则按字典序打印出由字符a, b, c所能排列出来的所有字符串abc, acb, bac, bca, cab和cba。
//输入一个字符串, 长度不超过9(可能有字符重复), 字符只包括大小写字母。

#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

void swap(char& a, char& b)
{
	char tmp = a;
	a = b;
	b = tmp;
}

void Permutation(string str, set<string>& st, int begin)
{
	if (begin == str.size() - 1)
		st.insert(str);
	else
	{
		for (int i = begin; i < str.size(); i++)
		{
			swap(str[begin], str[i]);
			Permutation(str, st, begin + 1);
			swap(str[begin], str[i]);
		}
	}
}

vector<string> Permutation(string str) 
{
	set<string> st;
	vector<string> arr;
	if (str.empty())
		return arr;
	Permutation(str, st, 0);

	vector<string> s(st.begin(), st.end());
	return s;
}

void main()
{
	string s = "aabc";
	vector<string>& arr = Permutation(s);
	for (auto e : arr)
		cout << e << endl;
}

//// 专门处理int的加法函数
//int Add(int left, int right){return left + right;}
//
//// 通用加法函数
//template<class T>
//T Add(T left, T right){return left + right;}
//
//void main()
//{
//	Add(1, 2); // 与非模板函数匹配，编译器不需要特化
//	cout<<Add<int>(1, 2)<<endl; // 调用编译器特化的Add版本
//}

//template<typename T>
//T Add(const T& a, const T& b){return a + b;}
//
//void main()
//{
//	int a1 = 1, a2 = 2;
//	double b1 = 10.0, b2 = 20.0;
//	Add(a1, a2);
//	Add(b1, b2);
//
//	//Add(a1, b1);//不能通过编译，类型不同
//
//	//一种方法就是用户进行强制转换
//	Add(a1, (int)b1);
//	
//	//另一种方法就是使用显示实例化
//	Add<int>(a1, b1);
//}