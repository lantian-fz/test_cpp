#define _CRT_SECURE_NO_WARNINGS 1
//���������bit��
//����: ��һ��byte���ֶ�Ӧ�Ķ�����������1�����������������3�Ķ�����Ϊ00000011���������2��1
//��������:����һ��byte����
//�������:���ת�ɶ�����֮������1�ĸ���
//����: 3
//���: 2
#include <iostream>
using namespace std;

int By(int byte)
{
	int max = 0;
	int tmp = 0;
	//int byt = byte - '0';
	for (int i = 0; i < 8; i++)
	{
		if (((byte >> i) & 1) == 1)
			tmp++;
		else
			tmp = 0;

		if (max < tmp)
			max = tmp;
	}
	return max;
}

int main()
{
	int byte = 0;
	while (cin >> byte)
		cout << By(byte) << endl;

	return 0;
}