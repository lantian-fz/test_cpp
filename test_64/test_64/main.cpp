#define _CRT_SECURE_NO_WARNINGS 1
//两种排序方法
//考拉有n个字符串字符串，任意两个字符串长度都是不同的。考拉最近学习到有两种字符串的排序方法： 
//1.根据字符串的字典序排序。 例如："car" < "carriage" < "cats" < "doggies < "koala"
//2.根据字符串的长度排序。   例如："car" < "cats" < "koala" < "doggies" < "carriage"
//考拉想知道自己的这些字符串排列顺序是否满足这两种排序方法，考拉要忙着吃树叶，所以需要你来帮忙验证。
//输入描述 :输入第一行为字符串个数n(n ≤ 100),接下来的n行, 每行一个字符串, 字符串长度均小于100，均由小写字母组成
//输出描述 :如果这些字符串是根据字典序排列而不是根据长度排列输出"lexicographically",
//如果根据长度排列而不是字典序排列输出"lengths",如果两种方式都符合输出"both"，否则输出"none"
//输入: 3
//      a
//      aa
//      bbb
//输出: both
#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

string StrSort(vector<string> &arr)
{
	int abc = 1;
	int len = 0;

	size_t i = 0;
	for (i = arr.size() - 1; i > 0; i--)
	{
		if (arr[i].size() < arr[i - 1].size())
			break;
	}
	if (i == 0)
		len = 1;

	for (i = 0; i<arr.size() - 1; i++)
	{
		if (strcmp(arr[i].c_str(), arr[i + 1].c_str())>0)
		{
			abc = 0;	
			break;
		}
	}

	if (abc == 0 && len == 0)
		return "none";
	else if (abc == 1 && len == 0)
		return "lexicographically";
	else if (abc == 0 && len == 1)
		return "lengths";
	else
		return "both";
}

int main()
{
	int n = 0;
	cin >> n;
	vector<string> arr;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		arr.push_back(s);
	}

	cout << StrSort(arr) << endl;

	return 0;
}