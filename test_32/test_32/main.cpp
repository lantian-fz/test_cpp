#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
//#include <string>
#include "Person.h"

using namespace std;

int main()
{
	Person<int> p1(10);
	p1.Show();
	return 0;
}