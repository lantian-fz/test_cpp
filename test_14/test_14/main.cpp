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
		Test(a, b, 100);//�����һ�������Ķ��󣬲�������������
	}//�ڹ��캯���е��ù��캯���ǳ�Σ��

	~Test()
	{
		cout << "Test���� " << this << endl;
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

	//Test���� 00EFFA5C
	//t1.getC() c = -858993460
	//Test���� 00EFFC28
}