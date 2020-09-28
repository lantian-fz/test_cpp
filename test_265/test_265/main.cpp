#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

int main()
{
	int n = 6, m = 11;
	int x = m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
			cout << " ";
		for (int j = x; j>0; j--)
			cout << "*";
		cout << endl;
		x -= 2;
	}
	x = 1;
	for (int i = n - 1; i > 0; i--)
	{
		for (int j = i-1; j > 0; j--)
			cout << " ";
		for (int j = 0; j < 2 * x + 1; j++)
			cout << "*";
		cout << endl;
		x++;
	}
	return 0;
}
