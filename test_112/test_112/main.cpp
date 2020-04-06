#define _CRT_SECURE_NO_WARNINGS 1
//��������
//���й��Ľ��ղ�ͬ�������Ľڼ���ͨ����ѡ��ĳ���µĵڼ������ڼ�������ʽ�����ÿһ��ķż����ڶ�����ͬ������������£�
//* 1��1�գ�Ԫ��
//* 1�µĵ���������һ������·�¡��������
//* 2�µĵ���������һ����ͳ��
//* 5�µ����һ������һ��������ʿ������
//* 7��4�գ���������
//* 9�µĵ�һ������һ���Ͷ���
//* 11�µĵ��ĸ������ģ��ж���
//* 12��25�գ�ʥ����
//���ڸ���һ����ݣ������æ���ɵ�����յ����ڡ�
//�������� :��������������ݣ�ÿ�����ݰ���һ��������year��2000��year��9999����
//������� :��Ӧÿһ�����ݣ��ԡ�YYYY - MM - DD����ʽ����������еĽ������ڣ�ÿ������ռһ�С�
//          ÿ������֮�����һ��������Ϊ�ָ���
//����
//2014
//2013
//���
//2014-01-01
//2014-01-20
//2014-02-17
//2014-05-26
//2014-07-04
//2014-09-01
//2014-11-27
//2014-12-25
//
//2013-01-01
//2013-01-21
//2013-02-18
//2013-05-27
//2013-07-04
//2013-09-02
//2013-11-28
//2013-12-25

#include <iostream>
#include <string>
using namespace std;

string Festival(int year, int month,int day, int num, int count, bool flag = true)
{
	if (month == 1)
	{
		month = 13;
		year--;
	}
	if (month == 2)
	{
		month = 14;
		year--;
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
			day++;
	}
	int week = 0;
	int k = 0;
	int i = 0;
	if (flag)
	{
		for (i = 1; i <= day; i++)
		{
			week = (i + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;
			if (week + 1 == count)
				k++;
			if (k == num)
				break;
		}
	}
	else
	{
		for (i = day; i >=1; i--)
		{
			week = (i + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;
			if (week + 1 == count)
				k++;
			if (k == num)
				break;
		}
	}
	string s;
	if (i < 10)
	{
		s += '0';
		s += to_string(i);//��valת����string
	}
	else
	{
		s = to_string(i);//��valת����string
	}
	return s;
}

int main()
{
	int year = 0;
	//0Ϊ����ʱ2������   1�� 2�� 3�� 4�� 5�� 6�� 7�� 8�� 9�� 10�� 11�� 12��
	int month[13] = { 29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	while (cin >> year)
	{
		cout << year << "-" << "01" << "-" << "01" << endl;
		cout << year << "-" << "01" << "-" << Festival(year, 1,month[1], 3, 1) << endl;//1�µĵ�3������һ
		cout << year << "-" << "02" << "-" << Festival(year, 2,month[2], 3, 1) << endl;//2�µĵ�3������һ
		cout << year << "-" << "05" << "-" << Festival(year, 5,month[5], 1, 1,false) << endl;//5�µ����һ������һ
		cout << year << "-" << "07" << "-" << "04" << endl;
		cout << year << "-" << "09" << "-" << Festival(year, 9,month[9], 1, 1) << endl;//9�µĵ�1������һ
		cout << year << "-" << "11" << "-" << Festival(year, 11,month[11], 4, 4) << endl;//11�µĵ�4��������
		cout << year << "-" << "12" << "-" << "25" << endl;
		cout << endl;//�������ţ��ͨ����emmm
	}

	return 0;
}