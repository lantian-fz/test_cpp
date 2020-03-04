#define _CRT_SECURE_NO_WARNINGS 1
//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
//例如输入一个长度为9的数组{ 1, 2, 3, 2, 2, 2, 5, 4, 2 }。
//由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int MoreThanHalfNum_Solution(vector<int> numbers) 
{
	string s(numbers.begin(), numbers.end());
	int arr[10] = { 0 };
	for (size_t i = 0; i < s.size(); i++)
		arr[s[i]]++;
	for (int i = 0; i < 10; i++)
	{
		if (arr[i]>numbers.size() / 2)
			return i;
	}
	return 0;
}

int main()
{
	int n = 0;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; i++)
	{
		int tmp = 0;
		cin >> tmp;
		arr.push_back(tmp);
	}
	
	cout << MoreThanHalfNum_Solution(arr) << endl;
	
	return 0;
}