#define _CRT_SECURE_NO_WARNINGS 1
//牛客-重建二叉树
//链接：https ://www.nowcoder.com/questionTerminal/8a19cbe657394eeaac2f6ea9b0f6fcf6
//来源：牛客网
//输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
//例如输入前序遍历序列{ 1, 2, 4, 7, 3, 5, 6, 8 }和中序遍历序列{ 4, 7, 2, 1, 5, 3, 8, 6 }，则重建二叉树并返回。
#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* Construct(vector<int>& pre, vector<int>& vin, int p1, int p2, int v1, int v2)
{
	TreeNode* root = new TreeNode(pre[p1]);

	//只有一个节点
	if (p1 == p2)
		return root;

	//在中序遍历中找根节点，即先序遍历的第一个节点
	int index = 0;
	for (index = v1; index <= v2; ++index)
	{
		if (vin[index] == pre[p1])
			break;
	}
	
	//计算中序遍历序列中根节点两边的集合长度
	int leftlen = index - v1;
	int rightlen = v2 - index;
	if (leftlen > 0)
		root->left = Construct(pre, vin, p1 + 1, p1 + leftlen, v1, index - 1);
	if (rightlen > 0)
		root->right = Construct(pre, vin, p1 + 1 + leftlen, p2, index + 1, v2);
	return root;
}

TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin)
{
	if (pre.size() != vin.size() || pre.size() == 0)
		return nullptr;
	int p1 = 0, p2 = pre.size() - 1;
	int v1 = 0, v2 = vin.size() - 1;

	return Construct(pre,vin,p1,p2,v1,v2);
}
void main()
{
	vector<int> pre = { 1, 2, 4, 7, 3, 5, 6, 8 };
	vector<int> vin = { 4, 7, 2, 1, 5, 3, 8, 6 };
	TreeNode* root = reConstructBinaryTree(pre, vin);
}

//class A
//{
//private:
//	static int k;
//	int h;
//public:
//	class B
//	{
//	public:
//		void foo(const A& a)
//		{
//			cout << k << endl;//OK
//			cout << a.h << endl;//OK
//		}
//	};
//};
//int A::k = 1;
//void main()
//{
//	A::B b;
//	b.foo(A());
//}
//class B
//{
//public:
//	B(int b = 0)
//		:_b(b)
//	{}
//	int _b;
//};
//class A
//{
//public:
//	void Print()
//	{
//		cout << a << endl;
//		cout << b._b << endl;
//		cout << p << endl;
//	}
//private:
//	// 非静态成员变量，可以在成员声明时给缺省值。
//	int a = 10;
//	B b = 20;
//	int* p = (int*)malloc(4);
//	static int n;
//};
//int A::n = 10;
//int main()
//{
//	A a;
//	a.Print();
//	return 0;
//}
//class A
//{
//public:
//	A() :_a(0){}
//	A(int a) :_a(a){}
//
//public:
//	static void show();
//
//	void print()
//	{
//		show();
//	}
//
//private:
//	int _a;
//	static int _b;
//};
//
//int A::_b = 3;
//
//void A::show()
//{
//	cout << "show" << endl;
//}
//
//void main()
//{
//	A a;
//	a.print();
//}
//class Fraction{
//public:
//	Fraction(int numerator, int denominator = 1) : m_numerator(numerator), m_denominator(denominator){}
//	operator double() const
//	{
//		return (double)m_numerator / m_denominator;
//	}
//private:
//	int m_numerator;
//	int m_denominator;
//};
//
//void main()
//{
//	Fraction fraction(3, 5);
//	double d = 3.5 + fraction;
//	cout << d << endl;
//}

//#include <iostream>
//using namespace std;
//class A
//{
//public:
//	A(int a):_a(a){}
//private:
//	int _a;
//};
//class B
//{
//public:
//	B(int a, int ref):_aobj(a), _ref(ref), _n(10){}
//private:
//	A _aobj; // 没有默认构造函数
//	int& _ref; // 引用
//	const int _n; // const
//};
//void main()
//{
//	char* a = new char[3];
//	//a = nullptr;
//	delete[] a;
//}