#define _CRT_SECURE_NO_WARNINGS 1
//iNOC��Ʒ��--��ȫ������
//��ȫ����Perfect number�����ֳ����������걸������һЩ�������Ȼ����
//�����е������ӣ����������������Լ�����ĺͣ������Ӻ�������ǡ�õ���������
//���磺28������Լ��1��2��4��7��14��28����ȥ������28�⣬����5������ӣ�1 + 2 + 4 + 7 + 14 = 28��
//��������count(int n), ���ڼ���n����(��n)��ȫ���ĸ��������㷶Χ, 0 < n <= 500000
//����n������ȫ���ĸ����� �쳣������� - 1
//
//��������:����һ������
//������� :�����ȫ���ĸ���
//����: 1000
//���: 3
#include <iostream>
using namespace std;

bool Num(int x)
{
	int num = 0;
	for (int i = x - 1; i>0; i--)
	{
		if (x%i == 0)
			num += i;
	}
	if (num == x)
		return true;
	return false;
}

int count(int n)
{
	if (n<1 || n>500000)
		return -1;
	int ret = 0;
	for (int i = 1; i <= n; i++)
	{
		if (Num(i))
			ret++;
	}
	return ret;
}
int main()
{
	int n = 0;
	while (cin >> n)
		cout << count(n) << endl;
	return 0;
}
