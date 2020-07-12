#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;

void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int Partition(int data[], int length, int start, int end)
{
	if (data == nullptr || length <= 0 || start < 0 || end >= length)
		return 0;
	int index = rand() % (end-start+1) + start;//生成start到end之间的随机数
	Swap(&data[index], &data[end]);
	int small = start - 1;
	for (index = start; index < end; index++)
	{
		if (data[index] < data[end])
		{
			++small;
			if (small != index)
				Swap(&data[index], &data[small]);
		}
	}
	++small;
	Swap(&data[small], &data[end]);
	return small;
}

void QuickSort(int data[], int length, int start, int end)
{
	if (start == end)
		return;
	int index = Partition(data, length, start, end);
	if (index > start)
		QuickSort(data, length, start, index - 1);
	if (index < end)
		QuickSort(data, length, index + 1, end);
}

void main()
{
	srand((unsigned int)time(NULL));

	int arr[] = { 5, 6, 3, 8, 9, 4 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	QuickSort(arr, sz, 0, sz - 1);
	for (auto e : arr)
		cout << e << " ";
	//for (int i = 0; i < 30; i++)
	//{
	//	int index = rand() % (9-3+1) + 3;
	//	cout << index << " ";
	//}
}