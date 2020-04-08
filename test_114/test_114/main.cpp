#define _CRT_SECURE_NO_WARNINGS 1
//�Ա�����
//NowCoder���Ա��Ͽ���һ�����ꡣ���������·�Ϊ������ʱ�򣬵���ÿ����׬1Ԫ������ÿ����׬2Ԫ��
//���ڸ���һ��ʱ�����䣬������������������ж��١�
//�������� :��������������ݡ�
//          ÿ�����ݰ�����������from��to(2000 - 01 - 01 �� from �� to �� 2999 - 12 - 31)��
//          ������������������ʾ���ÿո������year month day��
//������� :��Ӧÿһ�����ݣ�����ڸ��������ڷ�Χ��������ʼ�ͽ������ڣ�����׬����Ǯ��
//����
//2000 1 1 2000 1 31
//2000 2 1 2000 2 29
//���
//62
//29

#include <iostream>
using namespace std;

bool Year(int year)
{
	return ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0));
}

int NumDay(int year1, int month1, int day1,
	int year2, int month2, int day2)
{
	int ret = 0;
	int month[13] = { 29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (year1 == year2&&month1 == month2)
	{
		if (month1 == 2 || month1 == 3 || month1 == 5 || month1 == 7 || month1 == 11)
			ret += (day2 - day1 + 1);
		else
			ret += (day2 - day1 + 1) * 2;
		return ret;
	}
	if (year1 < year2)//����ͬһ������
	{
		//������һ�굽��ĩ�Ƕ���Ǯ
		if (month1 == 2 || month1 == 3 || month1 == 5 || month1 == 7 || month1 == 11)
			ret += (month[month1]-day1 + 1);//�·�Ϊ����ʱÿ��׬һԪ
		else
			ret += (month[month1]-day1 + 1) * 2;//����ÿ��׬��Ԫ
		for (int i = month1 + 1; i <= 12; i++)
		{
			if (i == 2 || i == 3 || i == 5 || i == 7 || i == 11)
				ret += month[i];//�·�Ϊ����ʱÿ��׬һԪ
			else
				ret += month[i] * 2;//����ÿ��׬��Ԫ
		}
		if (Year(year1)&& month1<=2 )//�����һ���������ټ�1ԪǮ
			ret += 1;

		//�ټ���ÿ��׬����Ǯ
		for (int i = year1+1; i < year2; i++)
		{
			ret += (28 + 31 + 31 + 31 + 30);
			ret += (31 + 30 + 30 + 31 + 30 + 31 + 31)*2;
			if (Year(i))
				ret += 1;
		}

		//������year2�����ָ������׬����Ǯ
		for (int i = 1; i < month2; i++)
		{
			if (i == 2 || i == 3 || i == 5 || i == 7 || i == 11)
				ret += month[i];//�·�Ϊ����ʱÿ��׬һԪ
			else
				ret += month[i] * 2;//����ÿ��׬��Ԫ
			if (Year(year2) && i == 2)
				ret += 1;
		}
		if (month2 == 2 || month2 == 3 || month2 == 5 || month2 == 7 || month2 == 11)
			ret += day2;//�·�Ϊ����ʱÿ��׬һԪ
		else
			ret += day2 * 2;//����ÿ��׬��Ԫ
	}
	else
	{
		//���㵱����׬����Ǯ
		if (month1 == 2 || month1 == 3 || month1 == 5 || month1 == 7 || month1 == 11)
			ret += (month[month1] - day1 + 1);//�·�Ϊ����ʱÿ��׬һԪ
		else
			ret += (month[month1] - day1 + 1) * 2;//����ÿ��׬��Ԫ
		
		//�����м�����·�
		for (int i = month1 + 1; i < month2; i++)
		{
			if (i == 2 || i == 3 || i == 5 || i == 7 || i == 11)
				ret += month[i];//�·�Ϊ����ʱÿ��׬һԪ
			else
				ret += month[i] * 2;//����ÿ��׬��Ԫ
		}

		//�����ָ���·���׬����Ǯ
		if (month2 == 1 || month2 == 3 || month2 == 5 || month2 == 7 || month2 == 11)
			ret += day2;//�·�Ϊ����ʱÿ��׬һԪ
		else
			ret += day2 * 2;//����ÿ��׬��Ԫ
		if (Year(year1) && month1 <= 2)
			ret += 1;
	}
	return ret;
}

int main()
{
	int year1 = 0, month1 = 0, day1 = 0;
	int year2 = 0, month2 = 0, day2 = 0;
	while (cin >> year1 >> month1 >> day1
		>> year2 >> month2 >> day2)
	{
		cout << NumDay(year1, month1, day1, year2, month2, day2) << endl;
	}

	return 0;
}