#define _CRT_SECURE_NO_WARNINGS 1
//������
//һֻ���������ÿ���ܲ���һ̥���ӡ�ÿֻС���ӵĳ�������һ�졣 ĳ��������һֻС���ӣ����ʵ�N���Ժ�������õ�����ֻ���ӡ�
//�������� :�������ݰ������飬ÿ��һ�У�Ϊ����n(1��n��90)��
//������� :��Ӧ�����n���м�ֻ����(����û��������������)��
//����
//1
//2
//���
//1
//2

#include <iostream>
using namespace std;

long long fun(int n)
{
	long long a = 1;
	long long b = 1;
	long long c = 1;
	while (n > 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}

int main()
{
	int n = 0;
	while (cin >> n)
		cout << fun(n+1) << endl;

	return 0;
}