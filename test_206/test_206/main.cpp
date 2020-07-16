#define _CRT_SECURE_NO_WARNINGS 1
//剑指offer-调整数组顺序使奇数位于偶数前面
//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
//所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

#include <iostream>
#include <vector>
using namespace std;

//未通过牛客，数的相对位置发生了变化
void reOrderArray_1(vector<int> &array) 
{
	int left = 0;
	int right = array.size() - 1;
	while (left < right)
	{
		//指针往后移到偶数位置
		while (left < right && (array[left] & 1) == 1)
			left++;
		//指针往前移到奇数位置
		while (left < right && (array[right] & 1) == 0)
			right--;
		if (left < right)
		{
			int tmp = array[left];
			array[left] = array[right];
			array[right] = tmp;
		}
	}
}

//新建一个数组，空间换时间
void reOrderArray_2(vector<int> &array)
{
	vector<int> arr;
	for (auto e : array)
	{
		if ((e & 1) != 0)
			arr.push_back(e);
	}
	for (auto e : array)
	{
		if ((e & 1) == 0)
			arr.push_back(e);
	}
	array = arr;
}

void main()
{
	vector<int> arr = { 1, 2, 3, 4, 5, 6, 7 };
	reOrderArray_2(arr);
	for (auto e : arr)
		cout << e << " ";
}