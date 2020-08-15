#define _CRT_SECURE_NO_WARNINGS 1
//剑指offer-和为S的连续正数序列
//输入一个正数S，打印出所有和为S的连续正数序列(至少含有两个数)，
//例如：输入15，1+2+3+4+5=4+5+6=7+8=15，序列就为1到5,4到6,7到8

#include<iostream>
#include<vector>
using namespace std;

void FindContinuousSequence(vector<vector<int>>&arr, int left, int right)
{
	vector<int> tmp;
	for (int i = left; i <= right; i++)
		tmp.push_back(i);
	arr.push_back(tmp);
}
//双指针
vector<vector<int>> FindContinuousSequence(int sum)
{
	vector<vector<int>> arr;
	if (sum < 3)
		return arr;
	int left = 1;
	int right = 2;
	int mid = (sum + 1) / 2;
	int cursum = left + right;
	while (left < mid)
	{
		if (cursum == sum)
			FindContinuousSequence(arr, left, right);
		while (cursum>sum&&left < mid)
		{
			cursum -= left;
			left++;
			if (cursum == sum)
				FindContinuousSequence(arr, left, right);
		}
		right++;
		cursum += right;
	}
	return arr;
}

void main()
{
	int n = 0;
	while (cin >> n)
	{
		vector<vector<int>> arr = FindContinuousSequence(n);
		for (auto e : arr)
		{
			for (auto i : e)
				cout << i << " ";
			cout << endl;
		}
	}
}