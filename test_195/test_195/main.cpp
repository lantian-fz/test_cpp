#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

namespace A
{
	int a;
	void show(){cout << "aaaaaa" << endl;}
}

namespace B
{
	int b;
	void show(){cout << "bbbbbb" << endl;}
	namespace C
	{
		int c;
		void show(){cout << "ccccccc" << endl;}
	}
}

namespace A
{
	void showA(){cout << "AAAAAAA" << endl;}
}

using A::a;
using namespace B;

int main()
{
	a = 3;
	b = 1;
	show();
	
	A::showA();

	return 0;
}