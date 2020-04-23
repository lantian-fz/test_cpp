#define _CRT_SECURE_NO_WARNINGS 1
//�����г��ִ�������һ�������
//��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡���������һ������Ϊ9������{ 1, 2, 3, 2, 2, 2, 5, 4, 2 }��
//��������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

//���������������������������ڣ���һ���������м��Ǹ���
int MoreThanHalfNum_Solution_1(vector<int> numbers) 
{
	size_t ret = 0;
	sort(numbers.begin(), numbers.end());
	for (size_t i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == numbers[numbers.size() / 2])
			ret++;
		if (ret>numbers.size() / 2)
			return numbers[numbers.size() / 2];
	}
	return 0;
}

int MoreThanHalfNum_Solution_2(vector<int> numbers)
{
	size_t ret = 1;
	if (numbers.size() == 1)
		return numbers[0];
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

//ʱ�临�Ӷ���СΪO(n)
//˼·������з������������֣��������ֵĴ����������������ֳ��ֵĴ����ͻ�Ҫ�ࡣ�ڱ�������ʱ��������ֵ��
//һ��������һ�����֣�һ�Ǵ�����������һ������ʱ��������֮ǰ�����������ͬ���������1�����������1��
//������Ϊ0���򱣴���һ�����֣�����������Ϊ1����������������������ּ�Ϊ����Ȼ�����ж����Ƿ�����������ɡ�
int MoreThanHalfNum_Solution_3(vector<int> numbers)
{
	int n = numbers[0];
	int count = 1;
	for (size_t i = 1; i < numbers.size(); i++)
	{
		if (numbers[i] == n)
			count++;
		else
			count--;
		if (count == 0)
		{
			n = numbers[i];
			count = 1;
		}
	}
	count = 0;
	for (size_t i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == n)
			count++;
	}
	
	return count * 2 > numbers.size() ? n : 0;//numbers.size()/2����ƫ��
}
//���У�����[1,2,2,3,3,4,4,5,5]
//int MoreThanHalfNum_Solution_4(vector<int> numbers)
//{
//	int ret = 0;
//	set<int> st(numbers.begin(), numbers.end());
//	sort(numbers.begin(), numbers.end());
//	if ((st.size() - 1) * 2 < numbers.size())//ȥ�����г��ȿ��ܳ���һ����Ǹ���
//		return numbers[numbers.size() / 2];
//	else
//		return 0;
//}

int main()
{
	vector<int> arr = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	cout << MoreThanHalfNum_Solution_1(arr) << endl;
	cout << MoreThanHalfNum_Solution_2(arr) << endl;
	cout << MoreThanHalfNum_Solution_3(arr) << endl;

	return 0;
}