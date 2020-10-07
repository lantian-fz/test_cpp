#define _CRT_SECURE_NO_WARNINGS 1
//合并两个有序的数组
//给出两个有序的整数数组 A和B ，请将数组B 合并到数组A 中，变成一个有序的数组
//注意：可以假设A 数组有足够的空间存放 B数组的元素， A和 B中初始的元素数目分别为m 和n

#include <iostream>
using namespace std;

void merge(int A[], int m, int B[], int n)
{
	int index = m + n - 1;
	int i = m - 1;
	int j = n - 1;
	while (i>=0 && j>=0)
		A[index--] = A[i]>B[j] ? A[i--] : B[j--];
	while (j >= 0)
		A[index--] = B[j--];
}

void main()
{
	int arr1[10] = { 1, 3, 5, 6, 9 };
	int arr2[] = { 2, 4, 5, 8, 10 };
	merge(arr1, 5, arr2, 5);
	for (auto e : arr1)
		cout << e << " ";
	cout << endl;
}