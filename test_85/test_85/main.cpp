#define _CRT_SECURE_NO_WARNINGS 1
//ͳ��ÿ�������ӵ�����
//��һֻ���ӣ��ӳ������3������ÿ���¶���һֻ���ӣ�С���ӳ����������º�ÿ��������һֻ���ӣ�
//�������Ӷ���������ÿ���µ���������Ϊ���٣�
//public static int getTotalCount(int monthCount)
//{
//	return 0;
//}
//��������:����int�ͱ�ʾmonth
//������� :�����������int��
//����: 9
//���: 34
#include <iostream>
using namespace std;
//����쳲���������
int getTotalCount(int month)
{
	if (month == 1 || month == 2)
		return 1;
	else
		return getTotalCount(month - 1) + getTotalCount(month - 2);
}

int getTotalCount2(int month)
{
	int a = 1;
	int b = 1;
	int c = 0;
	if (month == 1 || month == 2)
		return 1;
	while (month > 2)
	{
		c = a + b;
		a = b;
		b = c;
		month--;
	}
	return c;
}

int main()
{
	int n = 0;
	while (cin >> n)
		cout << getTotalCount2(n) << endl;
	return 0;
}