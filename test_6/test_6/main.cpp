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
		Show();//非const函数内部可以调用其他的const成员函数
	}

	void PS()const
	{
		cout << "Show: Print---------------" << endl;
		//Print();//const函数内部不可以调用其他的非const成员函数
		Show();
	}

	~Test()
	{
		cout << "我是析构函数" << endl;
	}

private:
	int a;
	int b;
	int c;
};

int main()
{
	const Test tmp1;
	//tmp1.Print();//const对象不可以调用非const成员函数
	Test tmp2;
	tmp2.Show();//非const对象可以调用const成员函数
	tmp2.Print();
	tmp2.PS();

	return 0;
}