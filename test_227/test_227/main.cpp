#define _CRT_SECURE_NO_WARNINGS 1
//剑指offer-最小的k个数
//输入n个整数，找出其中最小的K个数。
//例如输入4, 5, 1, 6, 2, 7, 3, 8这8个数字，则最小的4个数字是1, 2, 3, 4。

#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

int Partition(vector<int>& arr, int start, int end)
{
	int index = rand() % (end - start + 1) + start;
	swap(arr[index], arr[end]);

	int small = start - 1;
	for (index = start; index < end; index++)
	{
		if (arr[index] < arr[end])
		{
			small++;
			if (small != index)
				swap(arr[index], arr[small]);
		}
	}
	small++;
	swap(arr[small], arr[end]);
	return small;
}

void GetLeastNumbers(vector<int> &input, vector<int> &arr, int k)
{
	int start = 0;
	int end = input.size() - 1;
	int index = Partition(input, start, end);
	while (index != k - 1)
	{
		if (index > k - 1)
		{
			end = index - 1;
			index = Partition(input, start, end);
		}
		else
		{
			start = index + 1;
			index = Partition(input, start, end);
		}
	}
	for (int i = 0; i < k; i++)
		arr[i] = input[i];
}

vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
{
	if (input.empty() || input.size() < k)
		return input;
	vector<int> arr(k, 0);
	GetLeastNumbers(input, arr, k);
	return arr;
}

vector<int> GetLeastNumbers_Solution_2(vector<int> input, int k)
{
	vector<int> ret;
	if (input.empty() || input.size() == k)
		return input;
	if (input.size()<k)
		return ret;
	sort(input.begin(), input.end());
	vector<int> arr(input.begin(), input.begin() + k);
	return arr;
}

void main()
{
	srand((unsigned int)time(NULL));

	vector<int> arr = { 4, 5, 1, 6, 2, 7, 3, 8 };
	vector<int>& ret = GetLeastNumbers_Solution_2(arr, 4);

	for (auto e : ret)
		cout << e << " ";
	cout << endl;
}

//class A
//{
//public:
//	A(){ cout << "aaaaaaaaaaaa" << endl; }
//	virtual ~A(){cout << "A的析构" << endl;}
//};
//
//class B :public A
//{
//public:
//	B(){ cout << "bbbbbbbbb" << endl; }
//	~B(){ cout << "BBBBBBB的析构" << endl; }
//};
//
//void main()
//{
//	A *a = new A();
//	A *aa = new B();
//	B *b = new B();
//	delete a;
//	delete aa;
//	delete b;
//
//}