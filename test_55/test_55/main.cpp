#define _CRT_SECURE_NO_WARNINGS 1
//��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
//��������һ������Ϊ9������{ 1, 2, 3, 2, 2, 2, 5, 4, 2 }��
//��������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int MoreThanHalfNum_Solution(vector<int> numbers) 
{
	string s(numbers.begin(), numbers.end());
	int arr[10] = { 0 };
	for (size_t i = 0; i < s.size(); i++)
		arr[s[i]]++;
	for (int i = 0; i < 10; i++)
	{
		if (arr[i]>numbers.size() / 2)
			return i;
	}
	return 0;
}

int main()
{
	int n = 0;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; i++)
	{
		int tmp = 0;
		cin >> tmp;
		arr.push_back(tmp);
	}
	
	cout << MoreThanHalfNum_Solution(arr) << endl;
	
	return 0;
}