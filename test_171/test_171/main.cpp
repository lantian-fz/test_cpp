#define _CRT_SECURE_NO_WARNINGS 1
//ţ��-�ַ������ҳ�����������ִ�
//����һ���ַ���str������ַ���str�е�����������ִ�
//�������� :�����������1������������һ���ַ���str�����Ȳ�����255��
//������� :��һ�������str��������������ִ���
//���룺abcd12345ed125ss123456789
//�����123456789

#include <iostream>
#include <string>
using namespace std;

string LongNumChar(string &s)
{
	int index = 0;
	int maxs = 0;

	for (size_t i = 0; i < s.size(); i++)
	{
		int count = 0;
		int j = i;
		while (s[j] >= '0'&&s[j] <= '9')
		{
			count++;
			j++;
		}
		if (maxs < count)
		{
			index = i;
			maxs = count;
		}
		i = j;
	}
	string ret(s.begin() + index, s.begin() + index + maxs);
	return ret;
}

int main()
{
	string s;
	while (getline(cin,s))
		cout << LongNumChar(s) << endl;

	return 0;
}

//#include <iostream>
//#include <cstdio>
//#include <cstdlib>
//using namespace std;
//
//void main()
//{
//	int b = 2;
//	int d = 3;
//	const int *a = &b;
//	int *const c = &b;
//	a = &d;
//	*c = 20;
//}

//int func()
//{
//	int i, j, k = 0;
//	for (i = 0, j = -1; j = 0; i++, j++)
//	{
//		k++;
//	}
//	return k;
//} 
//void main()
//{
//	cout << (func());
//}

//struct A
//{
//	unsigned a : 19;
//	unsigned b : 11;
//	unsigned c : 4;
//	unsigned d : 29;
//	char index;
//};
//void main()
//{
//	cout << sizeof(struct A) << endl;
//}
//class A
//{
//public:
//	static int a;
//	void fun()
//	{
//		cout << a << endl;
//	}
//};
//
//int A::a = 10;

//int main()
//{
//	char acX[] = "abc";
//	char acY[] = { 'a', 'b', 'c' };
//	char *szX = "abc";
//	char *szY = "abc";
//
//	cout << strlen(acX) << " " << strlen(acY) << endl;
//
//	return 0;
//}