#define _CRT_SECURE_NO_WARNINGS 1
//有一个非空的乱序数组，其中有若干个0.请将所有的0，移动到数组末尾
//#include <stdio.h>
//#include <inttypes.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int> FunArr(vector<int>& arr)
{
	if (arr.size() == 0 || arr.size() == 1)
		return arr;
	int i = 0;
	int j = arr.size() - 1;
	while (i < j)
	{
		int tmp = 0;
		if (arr[i] == 0 && arr[j] != 0)
		{
			tmp = arr[i];
			arr[i++] = arr[j];
			arr[j--] = tmp;
		}
		else if (arr[i] != 0 && arr[j] == 0)
		{
			i++;
			j--;
		}
		else if (arr[i] != 0 && arr[j] != 0)
			i++;
		else
			j--;
	}
	return arr;
}

void main()
{
	vector<int> arr = { 2, 3, 1, 0, 3, 0, 0, 9, 4, 0 };
	vector<int> arr2 = FunArr(arr);
	for (auto e : arr2)
		cout << e << " ";
	cout << endl;
}

//void main()
//{
//	map<int, string> c = { { 1, "张三" }, { 2, "李四" } };
//	cout << c[1] << endl;
//}
//
//void main()
//{
//	int arr[] = { 5, 1, 2, 4, 7, 2, 1, 3, 6, 9, 4, 5, 8 };
//	set<int> st(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	map<int, int> a;
//	a.insert(pair<int, int>(3, 4));
//	map<int, int> b(a.begin(), a.end());
//	cout << st.size() << endl;
//	map<int, string> c = { { 1, "张三" }, { 2, "李四" } };
//	for (auto& e : st)
//		cout << e << " ";
//	cout << endl;
//
//	for (auto it = st.rbegin(); it != st.rend(); ++it)
//		cout << *it << " ";
//	cout << endl;
//	cout << st.count(2) << endl;
//}
//void main()
//{
//	int i = 0;
//	++i;
//	cout << i << endl;
//	i++;
//	cout << i << endl;
//	i--;
//	cout << i << endl;
//}

//union X
//{
//	int32_t a;
//	struct
//	{
//		int16_t b;
//		int16_t c;
//	};
//};
//
//int main()
//{
//	union X x;
//	x.a = 0x20200810;
//	printf("%x,%x", x.c, x.b);
//}

//class Base
//{
//public:
//	virtual ~Base(){}
//	virtual void Print(){ cout << "Base::Print()" << endl; }
//	void Hello()
//	{
//		cout << "Base::Hello()" << endl;
//		Print();
//	}
//};
//
//class Derivl :public Base
//{
//public:
//	void Print(){ cout << "Derivl::Print()" << endl; }
//	void Hello()
//	{
//		cout << "Derivl::Hello()" << endl;
//		Print();
//	}
//};
//
//class Deriv2 :public Derivl
//{
//public:
//	void Print(){ cout << "Deriv2::Print()" << endl; }
//	void Hello()
//	{
//		cout << "Deriv2::Hello()" << endl;
//		Print();
//	}
//};
//
//void main()
//{
//	Base* p1 = new Base();
//	Base* p2 = new Derivl();
//	Base* p3 = new Deriv2();
//
//	p1->Print();
//	p1->Hello();
//	p2->Print();
//	p2->Hello();
//	p3->Print();
//	p3->Hello();
//}

//class Parent {
//public:
//	int iparent;
//	Parent() :iparent(10) {}
//	virtual void f() { cout << " Parent::f()" << endl; }
//	virtual void g() { cout << " Parent::g()" << endl; }
//	virtual void h() { cout << " Parent::h()" << endl; }
//};
//class Child : public Parent {
//public:
//	int ichild;
//	Child() :ichild(100) {}
//	virtual void f() { cout << "Child::f()" << endl; }
//	virtual void g_child() { cout << "Child::g_child()" << endl; }
//	virtual void h_child() { cout << "Child::h_child()" << endl; }
//};
//class GrandChild : public Child{
//public:
//	int igrandchild;
//	GrandChild() :igrandchild(1000) {}
//	virtual void f() { cout << "GrandChild::f()" << endl; }
//	virtual void g_child() { cout << "GrandChild::g_child()" << endl; }
//	virtual void h_grandchild() { cout << "GrandChild::h_grandchild()" << endl; }
//};
//
//void main()
//{
//	Parent a;
//	Child b;
//	GrandChild c;
//}
//#include <stdio.h>
//struct A
//{
//	int _a : 2;
//	int _b : 5;
//	int _c : 10;
//	int _d : 30;
//};
//
//void main()
//{
//	//cout << sizeof(A) << endl;
//	struct A aa;
//	
//	printf("%d\n", sizeof(aa));
//}