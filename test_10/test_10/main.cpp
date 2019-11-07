#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class Test
{
public:
	static Test* Instance()
	{
		if (m_instance == nullptr)
		{
			m_instance = new Test;
		}
		return m_instance;
	}

private:
	Test(int d = 0)
	{
		data = d;
	}

private:
	int data;
	static Test * m_instance;
};

Test* Test::m_instance = nullptr;

void main()
{
	Test *pt1 = Test::Instance();
	Test *pt2 = Test::Instance();
	Test *pt3 = Test::Instance();
	
}

//class Test
//{
//public:
//	Test(int d = 0)
//	{
//		data = d;
//	}
//private:
//	void* operator new(size_t);
//private:
//	int data;
//};
//
//int main()
//{
//	Test t1(10);
//	Test *pt = new Test(3);
//
//	return 0;
//}

//class Test
//{
//	//friend Test* CreateObject(int data);
//public:
//	static Test* CreateObject(int data)
//	{
//		return new Test(data);
//	}
//
//private:
//	Test(int d = 0)
//	{
//		data = d;
//	}
//
//protected:
//	Test(const Test &);
//	Test& operator=(const Test &);
//
//private:
//	int data;
//};
//
////Test* CreateObject(int data)
////{
////	return new Test(data);
////}
//
//int main()
//{
//	Test *pt = Test::CreateObject(1);
//
//	//Test *pt = CreateObject(1);
//
//	return 0;
//}