#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

void f(int){ cout << "f(int)" << endl; }
void f(int*){ cout << "f(int*)" << endl; }
void main()
{
	f(0);
	f(NULL);
	f((int*)NULL);
}

//void TestFor(int array[])
//{
//	for (auto& e : array)
//		cout << e << endl;
//}
//
//void main()
//{
//	int arr[] = { 5, 2, 8, 1, 0 };
//	for (auto x : arr)
//		cout << x << " ";
//}

//int main()
//{
//	int x = 20;
//	auto a = &x;//这里auto推导出的类型为int*
//	auto* b = &x;//而这里推导出的为int型，*已经有了
//	auto& c = x;//这里相当于 int& c = x;
//
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//
//	*a = 3;
//	*b = 5;
//	c = 9;
//
//	return 0;
//}

//int& Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//int main()
//{
//	int& ret = Add(1, 2);
//	Add(3, 4);
//	cout << "Add(1, 2) is :" << ret << endl;
//	return 0;
//}

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