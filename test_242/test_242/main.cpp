#define _CRT_SECURE_NO_WARNINGS 1
//��ָoffer-ԲȦ�����ʣ�µ�����
//��Լɪ������

#include <iostream>
#include <list>
using namespace std;

//�û�������ģ��ԲȦ
int LastRemaining_Solution(int n, int m)
{
	if (n < 1 || m < 1)
		return -1;
	list<int> numbers;//��listģ�⻷������
	for (int i = 0; i < n; i++)
		numbers.push_back(i);
	list<int>::iterator it = numbers.begin();
	while (numbers.size()>1)
	{
		for (int i = 1; i < m; i++)
		{
			it++;
			if (it == numbers.end())
				it = numbers.begin();
		}
		auto tmp = ++it;
		if (tmp == numbers.end())
			tmp = numbers.begin();
		it--;
		numbers.erase(it);
		it = tmp;
	}
	return *it;
}

void main()
{
	int n = 0, m = 0;
	while (cin >> n >> m)
		cout << LastRemaining_Solution(n, m) << endl;
}