#define _CRT_SECURE_NO_WARNINGS 1
//�ظ�N�ε�Ԫ��
//�ڴ�СΪ 2N ������ A ���� N + 1 ����ͬ��Ԫ�أ�������һ��Ԫ���ظ��� N �Ρ�
//�����ظ��� N �ε��Ǹ�Ԫ�ء�
//���룺[1, 2, 3, 3]              �����3
//���룺[2, 1, 2, 5, 3, 2]        �����2
//���룺[5, 1, 5, 2, 5, 3, 5, 4]  �����5
//
//��ʾ��
//4 <= A.length <= 10000
//0 <= A[i] < 10000
//A.length Ϊż��

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