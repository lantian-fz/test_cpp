#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class Test
{
public:
	Test(int a, int b, int c)
	{
		_a = a;
		_b = b;
		_c = c;
	}

	Test(int a, int b)
	{
		_a = a;
		_b = b;
		Test(a, b, 100);//会产生一个匿名的对象，产生完立即析构
	}//在构造函数中调用构造函数非常危险

	~Test()
	{
		cout << "Test析构 " << this << endl;
	}

public:
	int getC()
	{
		return _c;
	}

	void setC(int val)
	{
		_c = val;
	}


private:
	int _a;
	int _b;
	int _c;
};

int main()
{
	Test t1(1, 2);
	cout <<"t1.getC() c = "<< t1.getC() << endl;

	return 0;

	//Test析构 00EFFA5C
	//t1.getC() c = -858993460
	//Test析构 00EFFC28
}