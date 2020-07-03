#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int& Add(int a, int b)
{
	int c = a + b;
	return c;
}
int main()
{
	int& ret = Add(1, 2);
	Add(3, 4);
	cout << "Add(1, 2) is :" << ret << endl;
	return 0;
}

//void show(int a, int b = 3)
//{
//	cout << a << " " << b << endl;
//}
//
//void show(int a, int b)
//{
//	cout << a << "*" << b << endl;
//}
//
//int main()
//{
//	show(3, 4);
//
//	return 0;
//}


//namespace A
//{
//	int a;
//	void show(){cout << "aaaaaa" << endl;}
//}
//
//namespace B
//{
//	int b;
//	void show(){cout << "bbbbbb" << endl;}
//	namespace C
//	{
//		int c;
//		void show(){cout << "ccccccc" << endl;}
//	}
//}
//
//namespace A
//{
//	void showA(){cout << "AAAAAAA" << endl;}
//}
//
//using A::a;
//using namespace B;
//
//int main()
//{
//	a = 3;
//	b = 1;
//	show();
//	
//	A::showA();
//
//	return 0;
//}