#define _CRT_SECURE_NO_WARNINGS 1
//问题描述：给出4个1 - 10的数字，通过加减乘除，得到数字为24就算胜利
//输入：4个1 - 10的数字。[数字允许重复，但每个数字仅允许使用一次，测试用例保证无异常数字]
//输出：true or false
//输入4个int整数
//输出描述 :
//返回能否得到24点，能输出true，不能输出false
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool Twenty_four(vector<int>& arr)
{
}

int main()
{
	vector<int> arr;
	for (int i = 0; i < 4; i++)
	{
		int tmp = 0;
		cin >> tmp;

		arr.push_back(tmp);
	}

	cout << Twenty_four(arr) << endl;

	return 0;
}


//#include <iostream>
//#include <vector>
//using namespace std;
//
//int MAX_Arry(vector<int>& arr)
//{
//	int MAX = arr[0];
//	int sum = arr[0];
//	int i = 1;
//	if (arr.size() <= 1)
//		return 0;
//	for (i = 1; i < arr.size(); i++)
//	{
//		if (sum < 0)  //如果前一个子数组和小于0，则从这里开始新的子数组
//			sum = arr[i];
//		else
//		{
//			sum += arr[i];//子数组和
//		}
//		if (sum > MAX)//记录下每次子数组中和最大时的值
//			MAX = sum;
//	}
//	return MAX;
//}
//
//void main()
//{
//	vector<int> arr;
//	int n = 0;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		int x = 0;
//		cin >> x;
//		arr.push_back(x);
//	}
//	cout << MAX_Arry(arr) << endl;
//}

//void KnockoutChar(string& str1, string& str2)
//{
//	int i = 0;
//	int j = 0;
//	int k = 0;
//
//	for (i = 0; str1[i] != '\0'; i++)
//	{
//		for (j = 0; str2[j] != '\0'; j++)
//		{
//			if (str1[i] == str2[j])
//			{
//				for (k = i; str1[k] != '\0'; k++)
//					str1[k] = str1[k + 1];
//			}
//		}
//
//	}
//}
//
//int main()
//{
//	string str1;
//	string str2;
//	//gets();
//	//gets();
//	str1.resize(1024);
//	//str2.size(1024);
//	cin.getline(str1);
//	
//
//	KnockoutChar(str1, str2);
//	cout << str1;
//	return 0;
//}