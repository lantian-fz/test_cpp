#define _CRT_SECURE_NO_WARNINGS 1
//�������һ��ż����ӽ�����������
//����һ��ż��������2����������2��������ɣ����ż����2�������кܶ������������ĿҪ��������ָ��ż��������������ֵ��С��������
//�������� :����һ��ż��
//������� :�����������
//����: 20
//���: 7
//      13
#include <iostream>
using namespace std;

bool PrimeNum(int x)//�ж�����
{
	for (int i = 2; i < x; i++)
	{
		if (x%i == 0)
			return false;
	}
	return true;
}

void Print(int n)
{
	if (n % 2 == 1 || n <= 2)
		return;
	int half = n / 2;//����������һ����n/2������
	while (half)
	{
		if (PrimeNum(half))
		{
			if (PrimeNum(n - half))
			{
				cout << n - half << endl;
				cout << half << endl;
				break;
			}
		}
		half++;
	}
}

int main()
{
	int n = 0;
	while (cin >> n)
		Print(n);

	return 0;
}