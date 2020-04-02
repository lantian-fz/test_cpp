#define _CRT_SECURE_NO_WARNINGS 1
//奇数位上都是奇数或者偶数位上都是偶数
//给定一个长度不小于2的数组arr。 写一个函数调整arr，使arr中要么所有的偶数位上都是偶数，
//要么所有的奇数位上都是奇数上。 要求：如果数组长度为N，时间复杂度请达到O(N)，额外空间
//复杂度请达到O(1),下标0,2,4,6...算作偶数位,下标1,3,5,7...算作奇数位，例如[1,2,3,4]调整为[2,1,4,3]即可
#include <iostream>
#include <vector>
using namespace std;

void oddInOddEvenInEven(vector<int>& arr, int len) 
{
	int i = 0;
	int j = 1;
	while (i < len && j < len)
	{
		if (arr[len - 1] % 2 == 0)
		{
			swap(arr[len - 1], arr[i]);
			i += 2;
		}
		else
		{
			swap(arr[len - 1], arr[j]);
			j += 2;
		}
	}
}

int main()
{
	int n = 0;
	vector<int> arr;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			int tmp = 0;
			cin >> tmp;
			arr.push_back(tmp);
		}
		oddInOddEvenInEven(arr, n);
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
		cout << endl;
	}

	return 0;
}