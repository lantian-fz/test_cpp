#define _CRT_SECURE_NO_WARNINGS 1
//数组中出现次数超过一半的数字
//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{ 1, 2, 3, 2, 2, 2, 5, 4, 2 }。
//由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int MoreThanHalfNum_Solution(vector<int> numbers) 
{
	size_t ret = 1;
	sort(numbers.begin(), numbers.end());
	for (size_t i = 1; i < numbers.size(); i++)
	{
		if (numbers[i] == numbers[i - 1])
		{
			ret++;
			if (ret>numbers.size() / 2)
				return numbers[i];
		}
		else
			ret = 1;
	}
	return 0;
}

int main()
{
	vector<int> arr = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	cout << MoreThanHalfNum_Solution(arr) << endl;

	return 0;
}