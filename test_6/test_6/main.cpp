#include <iostream>
using namespace std;

class Test
{
public:
	Test() :a(0), b(0), c(0)
	{}

	void Show()const
	{
		cout << "Show: " << a << "," << b << "," << c << endl;
	}

	void Print()
	{
		cout << "Print: " << a << "," << b << "," << c << endl;
		Show();//��const�����ڲ����Ե���������const��Ա����
	}

	void PS()const
	{
		cout << "Show: Print---------------" << endl;
		//Print();//const�����ڲ������Ե��������ķ�const��Ա����
		Show();
	}

	~Test()
	{
		cout << "������������" << endl;
	}

private:
	int a;
	int b;
	int c;
};

int main()
{
	const Test tmp1;
	//tmp1.Print();//const���󲻿��Ե��÷�const��Ա����
	Test tmp2;
	tmp2.Show();//��const������Ե���const��Ա����
	tmp2.Print();
	tmp2.PS();

	return 0;
}