#define _CRT_SECURE_NO_WARNINGS 1
//��ָoffer-��������������
//����һ���������飨�����������͸������������������������飨������һ��Ԫ�أ������͡�
//Ҫ��ʱ�临�Ӷ�ΪO(n)��
//�������� :��һ��Ϊ����ĳ���N��N >= 1��������N�У�ÿ��һ���������������N��Ԫ��
//������� :���͵Ľ��

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n = 0;
	while (cin >> n)
	{
		int max_num = 0;
		int sum = 0;
		vector<int> arr(n, 0);
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			if (i == 0)
				max_num = arr[0];
			if (sum <= 0)
				sum = arr[i];
			else
				sum += arr[i];
			if (sum>max_num)
				max_num = sum;
		}
		cout << max_num << endl;
	}

	return 0;
}