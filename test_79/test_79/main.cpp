#define _CRT_SECURE_NO_WARNINGS 1
//��������������������1�ĸ���
//��ʵ�����½ӿ�
//public   static   int  findNumberOf1(int num)
//{
//	return  0;
//} Ʃ�磺����5 ��5�Ķ�����Ϊ101�����2
//�������� :����һ������
//������� :����������������1�ĸ���
//����: 5
//���: 2
#include <iostream>
using namespace std;

int findNumberOf1(int num)
{
	int ret = 0;
	if (num < 0)
	{
		num = -num;
		ret++;
	}
	for (int i = 0; i<32; i++)
	{
		if (((num >> i) & 1) == 1)
			ret++;
	}
	return ret; 
}

int main()
{
	int n = 0;
	while (cin >> n)
		cout << findNumberOf1(n) << endl;

	return 0;
}