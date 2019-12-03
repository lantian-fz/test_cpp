#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

class A
{
public:
	A(string str)
	{
		this->str = str;
	}
	virtual void Print()
	{
		cout << "����1111" << "����" << this->str << endl;
	}
//private:
	string str;
};

class B:public A
{
public:
	B(string str) :A(str)
	{

	}
	void Print()
	{
		cout << "����2222" << "����" << this->str << endl;
	}

};

void test(A *t)
{
	cout << "������test" << endl;
	t->Print();
}
//1.û�ڸ���Print()ǰ���virtual
//������test
//����1111����AAAAAA
//������test
//����1111����BBBBBB   ��Ӧ���ǣ�����2222����BBBBBB��������û�е�������ķ���

//2.�ڸ���Print()ǰ���virtual
//������test
//����1111����AAAAAA
//������test
//����2222����BBBBBB
int main()
{
	A *a = new A("AAAAAA");
	//a->Print();
	//delete a;

	B *b = new B("BBBBBB");
	//b->Print();
	//delete b;
	test(a);
	test(b);

	return 0;
}