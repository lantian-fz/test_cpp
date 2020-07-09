#define _CRT_SECURE_NO_WARNINGS 1
//牛客-替换空格
//请实现一个函数，将一个字符串中的每个空格替换成“ % 20”。例如，当字符串为We Are Happy.
//则经过替换之后的字符串为We%20Are % 20Happy。
#include <iostream>
using namespace std;

void replaceSpace(char *str, int length) 
{
	if (str == nullptr)
		return;
	int len = 0;//字符串实际长度
	int spacenum = 0;//空格个数
	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (str[i] == ' ')
			++spacenum;
		++len;
	}
	int newlen = len + spacenum * 2;
	if (newlen > length)
		return;
	int p1 = len;//p1指针指向原字符串的末尾
	int p2 = newlen;//p2指针指向替换后字符串末尾
	while (p1 >= 0 && p2 > p1)
	{
		if (str[p1] == ' ')
		{
			str[p2--] = '0';
			str[p2--] = '2';
			str[p2--] = '%';
		}
		else
			str[p2--] = str[p1];
		--p1;
	}
}

void main()
{
	char str[30] = "We are happy.";
	
	replaceSpace(str, sizeof(str)/sizeof(str[0]));
}

//class A
//{
//public:
//	A(){_a = 0;}
//	A(int a){_a = a;}
//
//	void PrintA()
//	{
//		cout << _a << endl;
//	}
//	void Show()const
//	{
//		cout << "show" << endl;
//		//PrintA();//报错
//	}
//private:
//	int _a;
//};
//void main()
//{
//	A a;
//	a.PrintA();
//}
//struct A
//{
//	char a;
//	int b;
//	int c;
//	struct B
//	{
//		char a;
//		double b;
//		double c;
//	}B;
//}A;
//
//struct E
//{
//	char a;
//	int b;
//	int c;
//	struct B
//	{
//		char a;
//		double b;
//		double c;
//	};
//}E;
//
//struct C
//{
//	char a;
//	int b;
//	int d;
//}C;
//struct D
//{
//	char a;
//	int b;
//	int d;
//};
//void main()
//{
//	cout << sizeof(A) << endl;//40，对齐数为4时，结果为32
//	cout << sizeof(A.B) << endl;//24，对齐数为4时，结果为20
//	cout << sizeof(C) << endl;//12，对齐数为4时，结果为12
//	cout << sizeof(D) << endl;//12，对齐数为4时，结果为12
//	cout << sizeof(E) << endl;//12，对齐数为4时，结果为12
//	//cout << sizeof(E.B) << endl;//报错
//}