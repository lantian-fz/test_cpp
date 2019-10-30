#define _CRT_SECURE_NO_WARNINGS 1

#include "calendar.h"

void Menu()
{
	cout << "         选项" << endl;
	cout << "*    1.显示日期时间    2.动态显示    *" << endl;
	cout << "*    3.显示月历        4.前一天      *" << endl;
	cout << "*    5.下一天          6.N天后       *" << endl;
	cout << "*    7.N天前           0.退出        *" << endl;
}

int main()
{
	int input = 0;
	CDateTime dt;
	
	do
	{
		Menu();
		cout << "请选择：";
		cin >> input;
		switch (input)
		{
		case 1:
			dt.DateTimeShow();
			break;
		case 2:
			dt.DateTimeDShow();
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 0:
			break;
		default:
			cout << "没有这个选项！" << endl;
		}

	} while (input);
	
	return 0;
}