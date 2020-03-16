#define _CRT_SECURE_NO_WARNINGS 1
//�������ڵ�����ת��
//������������ڣ���������һ��ĵڼ��졣��
//��ϸ����������ĳ��ĳ��ĳ�գ��ж���һ������һ��ĵڼ��죿��
//��������:�������У��ֱ����꣬�£���
//������� :�ɹ� : ����outDay��������ĵڼ���;       ʧ��:���� - 1
//����: 2012
//	    12
//      31
//���: 366
#include <iostream>
using namespace std;

int getOutDay(int year,int month,int day)
{
	//0Ϊ����ʱ2������  1�� 2�� 3�� 4�� 5�� 6�� 7�� 8�� 9�� 10�� 11�� 12��
	int arr[13] = { 29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31,  30,  31 };
	int flag = 0;
	//���ж������Ƿ��׼
	if (month<1 || month>12)
		return -1;
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		flag = 1;
		if (month == 2)
		{
			if (day > arr[0])
				return -1;
		}
		else if (day > arr[month])
			return -1;
	}
	else if (day > arr[month])
		return -1;
	int num = 0;
	for (int i = 1; i < month; i++)
		num += arr[i];
	num += day;
	if (flag == 1 && month>2)
		return num + 1;
	else
		return num;
}

int main()
{
	int year = 0, month = 0, day = 0;
	while (cin >> year >> month >> day)
		cout << getOutDay(year, month, day) << endl;
	return 0;
}