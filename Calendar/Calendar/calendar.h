#ifndef _CALENDAR_H_
#define _CALENDAR_H_

#include <iostream>
#include <time.h>
#include <windows.h>
#include <conio.h>
using namespace std;

#define ESC 0x1B

struct Date
{
	int year;
	int month;
	int day;
};

struct Time
{
	int hour;
	int minute;
	int second;
};

class CDateTime
{
public:
	CDateTime();
	CDateTime(int year, int month, int day, int hour, int minute, int second);
	~CDateTime();

public:
	void GetCurDateTime();//��ȡ��ǰ����ʱ��
	void DateTimeShow();//��ʾ��ǰ����ʱ��
	void DateTimeDShow();//��̬��ʾ��ǰ����ʱ��
	void ShowMenology();//��ʾ����

public:
	void _ShowMenology(int year, int month);//�������
	int GetWeekByYMD(int year, int month, int day);//������ڼ�
public:
	CDateTime NextDateTime(int n);//n��������
	//CDateTime PrevDateTime(int n);//n��ǰ������

protected:
	bool IsLeap(int year);//�ж��Ƿ�Ϊ����
	int GetMDayByYM(int year, int month);//�ж��ǵڼ���

private:
	Date m_date;
	Time m_time;
};

#endif 