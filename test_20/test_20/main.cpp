#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include "MyArray.h"
using namespace std;

int main()
{
	MyArray arr1(10);

	for (int i = 0; i < arr1.getLen(); i++)
		arr1.setData(i, i + 10);

	for (int i = 0; i < arr1.getLen(); i++)
		cout << arr1.getData(i) << " ";
	cout << endl;

	MyArray arr2(arr1);
	for (int i = 0; i < arr2.getLen(); i++)
		cout << arr2.getData(i) << " ";
	cout << endl;

	MyArray arr3;
	arr3 = arr1;
	for (int i = 0; i < arr3.getLen(); i++)
		cout << arr3.getData(i) << " ";
	cout << endl;

	return 0;
}
