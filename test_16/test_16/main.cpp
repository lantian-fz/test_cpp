#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
//#include <vector>
using namespace std;

class Box
{
public:
	Box(int l, int w)
	{
		len = l;
		width = w;
	}

public:
	int volume()
	{
		int v = len*width*hight;
		cout << "高度 = " << hight << endl;
		cout << "体积 = " << v << endl;
		return v;
	}

public:
	static int hight;

private:
	int len;
	int width;
};

int Box::hight = 100;

int main()
{
	Box b1(10, 20);
	Box b2(100, 200);

	b1.volume();
	b2.volume();

	Box::hight = 10;
	
	b1.volume();
	b2.volume();

	cout << "Box = " << sizeof(b1) << endl;//8
	//只有对象中的成员变量占据空间，并且静态成员变量不占用空间

	return 0;
}

//class Test
//{
//public:
//	Test(int a, int b)
//	{
//		m_a = a;
//		m_b = b;
//	}
//
//public:
//	int getC()
//	{
//		m_c++;
//		return m_c;
//	}
//
//	static int getCC()
//	{
//		return m_c;
//	}
//
//public:
//	//static int m_c;
//
//private:
//	int m_a;
//	int m_b;
//	static int m_c;
//};
////静态成员变量的初始化，一定要写在类的外面
//int Test::m_c = 0;
//
//int main()
//{
//	Test t1(10, 20);
//	t1.getC();
//
//	return 0;
//}

//int main()
//{
//	vector<int> arr1(10);
//
//	for (int i = 0; i < 10; i++)
//	{
//		arr1[i] = i;
//	}
//
//	for (int i = 0; i < 10; i++)
//	{
//		cout << arr1[i] << " ";
//	}
//	cout << endl;
//
//	swap(arr1.begin(), arr1.end());
//
//	for (int i = 0; i < 10; i++)
//	{
//		cout << arr1[i] << " ";
//	}
//	cout << endl;
//
//	return 0;
//}