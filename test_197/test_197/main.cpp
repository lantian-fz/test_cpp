#define _CRT_SECURE_NO_WARNINGS 1
//ţ��-�滻�ո�
//��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ� % 20�������磬���ַ���ΪWe Are Happy.
//�򾭹��滻֮����ַ���ΪWe%20Are % 20Happy��
#include <iostream>
using namespace std;

void replaceSpace(char *str, int length) 
{
	if (str == nullptr)
		return;
	int len = 0;//�ַ���ʵ�ʳ���
	int spacenum = 0;//�ո����
	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (str[i] == ' ')
			++spacenum;
		++len;
	}
	int newlen = len + spacenum * 2;
	if (newlen > length)
		return;
	int p1 = len;//p1ָ��ָ��ԭ�ַ�����ĩβ
	int p2 = newlen;//p2ָ��ָ���滻���ַ���ĩβ
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
//		//PrintA();//����
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
//	cout << sizeof(A) << endl;//40��������Ϊ4ʱ�����Ϊ32
//	cout << sizeof(A.B) << endl;//24��������Ϊ4ʱ�����Ϊ20
//	cout << sizeof(C) << endl;//12��������Ϊ4ʱ�����Ϊ12
//	cout << sizeof(D) << endl;//12��������Ϊ4ʱ�����Ϊ12
//	cout << sizeof(E) << endl;//12��������Ϊ4ʱ�����Ϊ12
//	//cout << sizeof(E.B) << endl;//����
//}