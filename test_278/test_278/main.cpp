#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <map>
using namespace std;

int findLostCard(int* p, int pLen) 
{
	map<int, int> mp;
	for (int i = 0; i < pLen; i++)
		mp[p[i]]++;
	for (auto e : mp)
	{
		if (e.second < 4)
			return e.first;
	}
	return -1;
}

int main()
{
	int arr[] = { 1, 2, 1, 2, 3, 1, 1, 2, 2, 3, 3, 3, 4, 4, 5, 5, 4, 4, 5, 5, 6, 6, 7, 7, 6, 6, 7, 7, 8, 8, 9, 9, 8, 8, 10, 10, 11, 11, 10, 10, 11, 11, 13, 13, 12, 12, 12, 12, 13, 13, 9 };
	int len = sizeof(arr) / sizeof(arr[0]);
	cout << findLostCard(arr, len) << endl;
	return 0;
}