#define _CRT_SECURE_NO_WARNINGS 1
//����С������
//������A��������B ����С��������ָ �ܱ�A��B��������С��������ֵ�����һ���㷨��������A��B����С��������
//�������� :��������������A��B��
//������� :���A��B����С��������
//����: 5 7
//���: 35
#include <iostream>
using namespace std;

int main()
{
	size_t a = 0;
	size_t b = 0;
	cin >> a >> b;
	int i = a;
	while (i)
	{
		if (i%a == 0 && i%b == 0)
			break;
		i++;
	}
	cout << i << endl;

	return 0;
}