#define _CRT_SECURE_NO_WARNINGS 1
//΢�ź��
//�����ڼ�С��ʹ��΢���յ��ܶ��������ǳ����ġ��ڲ鿴��ȡ�����¼ʱ���֣�ĳ����������ֵĴ���
//�����˺��������һ�롣���С���ҵ��ú����д�������㷨˼·�ʹ���ʵ�֣�Ҫ���㷨�����ܸ�Ч��
//����һ������Ľ������gifts�����Ĵ�Сn���뷵���������Ľ�
//��û�н���������һ�룬����0��
//����������[1, 2, 3, 2, 2], 5
//���أ�2

#include <iostream>
#include <vector>
using namespace std;

int getValue(vector<int> gifts, int n) 
{
	int tmp = 0;
	for (int i = 0; i < n; i++)
	{
		int count = 0;

		tmp = gifts[i];
		for (int j = i; j < n; j++)
		{
			if (tmp == gifts[j])
				count++;
		}
		if (count>n / 2)
			return gifts[i];
	}
	return 0;
}

int main()
{
	vector<int> arr;
	int n = 0;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			int tmp = 0;
			cin >> tmp;
			arr.push_back(tmp);
		}
		cout << getValue(arr, n) << endl;
	}

	return 0;
}