#define _CRT_SECURE_NO_WARNINGS 1

#include "calendar.h"

void Menu()
{
	cout << "         ѡ��" << endl;
	cout << "*    1.��ʾ����ʱ��    2.��̬��ʾ    *" << endl;
	cout << "*    3.��ʾ����        4.ǰһ��      *" << endl;
	cout << "*    5.��һ��          6.N���       *" << endl;
	cout << "*    7.N��ǰ           0.�˳�        *" << endl;
}

int main()
{
	int input = 0;
	CDateTime dt;
	
	do
	{
		Menu();
		cout << "��ѡ��";
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
			cout << "û�����ѡ�" << endl;
		}

	} while (input);
	
	return 0;
}