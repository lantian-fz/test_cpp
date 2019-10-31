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
			int val = getch();
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

	int mdays = GetMDayByYM(year, month);//��ȡ�ǵڼ�����
	int week = GetWeekByYMD(year, month, 1);//��ȡ���ڼ�

	if (7 == week)
		week = 7;

	for (int i = 0; i < week - 1; i++)
		printf("%-6c", ' ');


}