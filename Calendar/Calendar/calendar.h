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
	~CDateTime();

public:
	void GetCurDateTime();//获取当前日期时间
	void DateTimeShow();//显示当前日期时间
	void DateTimeDShow();//动态显示当前日期时间
	//void ShowMenology();

protected:
	//bool IsLeap(int year);

private:
	Date m_date;
	Time m_time;
};

#endif 