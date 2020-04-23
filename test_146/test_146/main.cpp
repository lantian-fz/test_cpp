#define _CRT_SECURE_NO_WARNINGS 1
//�����г��ִ�������һ�������
//��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡���������һ������Ϊ9������{ 1, 2, 3, 2, 2, 2, 5, 4, 2 }��
//��������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��

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