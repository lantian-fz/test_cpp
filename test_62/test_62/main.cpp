#define _CRT_SECURE_NO_WARNINGS 1
//Fibonacci����
//Fibonacci��������������ģ�F[0] = 0; F[1] = 1; for each i �� 2: F[i] = F[i - 1] + F[i - 2]
//��ˣ�Fibonacci���о����磺0, 1, 1, 2, 3, 5, 8, 13, ...����Fibonacci�����е������ǳ�ΪFibonacci����
//����һ��N�����������Ϊһ��Fibonacci����ÿһ������԰ѵ�ǰ����X��ΪX-1����X+1�����ڸ���һ����N��������Ҫ���ٲ����Ա�ΪFibonacci����
//��������:����Ϊһ��������N(1 �� N �� 1,000,000)
//�������:���һ����С�Ĳ�����ΪFibonacci��"
//����: 15
//���: 2
#include <iostream>
using namespace std;

int Fi(int n)//�����ķ���
{
	int a = 0;
	int b = 1;
	//aΪn��ǰһ��Fibonacci����bΪ��һ��
	while (b <= n)
	{
		int c = a + b;
		a = b;
		b = c;
	}
	if (n - a > b - n)
		return b - n;
	else
		return n - a;
}

int main()
{
	int n = 0;
	cin >> n;

	cout << Fi(n) << endl;

	return 0;
}