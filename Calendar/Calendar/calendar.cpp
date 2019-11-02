#define _CRT_SECURE_NO_WARNINGS 1

#include "calendar.h"

CDateTime::CDateTime()
{
	m_date.year = 1;
	m_date.month = 1;
	m_date.day = 1;

	m_time.hour = 0;
	m_time.minute = 0;
	m_time.second = 0;
}

CDateTime::~CDateTime(){}

void CDateTime::GetCurDateTime()//��ȡ��ǰ����ʱ��
{
	time_t te;
	time(&te);

	struct tm *ptm = localtime(&te);

	m_date.year = ptm->tm_year + 1900;
	m_date.month = ptm->tm_mon + 1;
	m_date.day = ptm->tm_mday;

	m_time.hour = ptm->tm_hour;
	m_time.minute = ptm->tm_min;
	m_time.second = ptm->tm_sec;
}

void CDateTime::DateTimeShow()
{
	GetCurDateTime();
	cout << m_date.year << "�� " << m_date.month << "�� " << m_date.day << "�� " 
		<< m_time.hour << "ʱ " << m_time.minute << "�� " << m_time.second << "��" << endl;
}

void HideCursor()//���ع��
{
	HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(hd, &cursor_info);
}
void ShowCursor()//��ʾ���
{
	HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cursor_info = { 1, 1 };
	SetConsoleCursorInfo(hd, &cursor_info);
}

void CDateTime::DateTimeDShow()
{
	HideCursor();
	while (1)
	{
		if (_kbhit())
		{
			int val = _getch();
			if (val == ESC)
				break;
		}
		GetCurDateTime();
		DateTimeShow();
		Sleep(1000);
		system("cls");
	}
	ShowCursor();//�˳���̬��ʾ����ʾ���
}

void CDateTime::ShowMenology()
{
	GetCurDateTime();//�Ȼ�ȡ��ǰʱ��
	_ShowMenology(m_date.year, m_date.month);
}

void CDateTime::_ShowMenology(int year, int month)
{
	char *title[] = { "һ", "��", "��", "��", "��", "��", "��" };
	for (int i = 0; i<7; ++i)
		printf("%-6s", title[i]);
	printf("\n");

	int mdays = GetMDayByYM(year, month);//��ȡmonth���ж�����
	int week = GetWeekByYMD(year, month, 1);//��ȡ���ڼ�

	if (7 == week)
		week = 7;

	for (int i = 0; i < week - 1; i++)
		printf("%-6c", ' ');
	//printf("\n");

	for (int i = 1; i <= mdays; i++)
	{
		printf("%-6d", i);
		int w = GetWeekByYMD(year, month, i);
		if (0 == w)
			printf("\n\n");
	}
	printf("\n");	
}

bool CDateTime::IsLeap(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	return false;
}

int CDateTime::GetMDayByYM(int year, int month)
{
	int days[] = { 29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//ÿ���µ�����
	       //  days[0]�����洢����2�µ�����
	if (2 == month)
	{
		if (IsLeap(year))
			return days[0];
	}
	return days[month];
}

int CDateTime::GetWeekByYMD(int year, int month, int day)
{
	if (1 == month || 2 == month)
	{
		month += 2;
		year -= 1;
	}
	//���չ�ʽ
	return (day + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400 + 1) % 7;
}
//CDateTime CDateTime::NextDateTime(int n);

CDateTime CDateTime::NextDateTime(int n)
{
	int year = m_date.year;
	int month = m_date.month;
	int day = m_date.day;

	int mday = GetMDayByYM(year, month);//����µ�����

	while (day + n > mday)
	{
		month++;
		if (month > 12)
		{
			year++;
			month = 1;
		}
		n -= mday;
		mday = GetMDayByYM(year, month);//����µ��·ݵ�����
	}
	day += n;

	return CDateTime(year, month, day, m_time.hour, m_time.minute, m_time.second);
}