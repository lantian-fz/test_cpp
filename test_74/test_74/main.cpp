#define _CRT_SECURE_NO_WARNINGS 1
//输入一个数组和一个k，在数组中寻找k个最小的数
#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<int> ArrK(vector<int> &input, int k)
{
	multiset<int> st(input.begin(), input.end());

	auto it = st.begin();
	while (k)
	{
		it++;
		k--;
	}

	vector<int> arr(st.begin(), it);
	return arr;
}

int main()
{
	int k = 4;
	vector<int> a = { 4, 5, 1, 6, 2, 7, 3, 8 };

	vector<int> arr = ArrK(a, k);
	for (size_t i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}