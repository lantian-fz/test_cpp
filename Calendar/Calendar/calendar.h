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
	void GetCurDateTime();//获取当前日期时间
	void DateTimeShow();//显示当前日期时间
	void DateTimeDShow();//动态显示当前日期时间
	void ShowMenology();//显示月历

public:
	void _ShowMenology(int year, int month);//获得月历
	int GetWeekByYMD(int year, int month, int day);//获得星期几
public:
	CDateTime NextDateTime(int n);//n天后的月历
	//CDateTime PrevDateTime(int n);//n天前的月历

protected:
	bool IsLeap(int year);//判断是否为闰年
	int GetMDayByYM(int year, int month);//判断是第几月

private:
	Date m_date;
	Time m_time;
};

#endif 