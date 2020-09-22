#define _CRT_SECURE_NO_WARNINGS 1
//重复N次的元素
//在大小为 2N 的数组 A 中有 N + 1 个不同的元素，其中有一个元素重复了 N 次。
//返回重复了 N 次的那个元素。
//输入：[1, 2, 3, 3]              输出：3
//输入：[2, 1, 2, 5, 3, 2]        输出：2
//输入：[5, 1, 5, 2, 5, 3, 5, 4]  输出：5
//
//提示：
//4 <= A.length <= 10000
//0 <= A[i] < 10000
//A.length 为偶数

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int repeatedNTimes(vector<int>& A) 
{
	int N = A.size() / 2;
	unordered_map<int, int> mp;
	for (auto e : A)
		mp[e]++;
	for (auto e : mp)
	{
		if (e.second == N)
			return e.first;
	}
	return -1;
}

void main()
{
	vector<int> arr = { 5, 1, 5, 2, 5, 3, 5, 4 };
	cout << repeatedNTimes(arr) << endl;
}