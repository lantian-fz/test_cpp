#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class Test
{
public:
	Test(int d = 0) :date(d)
	{
		cout << "测试:" << this << endl;
	}

	Test(const Test &t)
	{
		cout << "拷贝构造：" << this << endl;
	}

	Test& operator=(const Test &t)
	{
		cout << "this = &t " << this<< " = " << &t << endl;
		if (this != &t)
		{
			date = t.date;
		}
		return *this;
	}

	~Test()
	{
		cout << "释放：" << this << endl;
	}

public:
	int GetDate()const
	{
		return date;
	}

private:
	int date;
};

Test fun(Test &x)
{
	int val = x.GetDate();
	return Test(val);
}
//测试:00AFFB44  t1
//测试 : 00AFFB38  无名(t2)
//释放：00AFFB38  无名(t2)
//释放：00AFFB44  t1
int main()
{
	Test t1(10);
	Test t2 = fun(t1);

	return 0;
}

//Test fun(Test x)
//{
//	int val = x.GetDate();
//	return Test(val);
//}
////测试:00FCFAD4  t1
////拷贝构造：00FCF9D0  x
////测试 : 00FCFAC8  无名(t2)
////释放：00FCF9D0  x
////释放：00FCFAC8  无名(t2)
////释放：00FCFAD4  t1
//int main()
//{
//	Test t1(10);
//	Test t2 = fun(t1);
//
//	return 0;
//}

//Test fun(Test x)
//{
//	int val = x.GetDate();
//	Test tmp(val);
//	return tmp;
//}
////测试:00CFFC68  t1
////拷贝构造：00CFFB64  x
////测试 : 00CFFB38  tmp
////拷贝构造：00CFFC5C  无名拷贝，拷贝的tmp
////释放：00CFFB38  tmp
////释放：00CFFB64  x
////释放：00CFFC5C  无名拷贝,
////释放：00CFFC68  t1
////t2一直没出现是因为直接将那个无名拷贝当成了t2
//int main()
//{
//	Test t1(10);
//	Test t2 = fun(t1);
//
//	return 0;
//}

//Test& fun(Test &x)
//{
//	return x;
//}
////测试:001AFE94  t1
////测试 : 001AFE88  t2
////this = &t 001AFE88 = 001AFE94
////10
////释放：001AFE88  t2
////释放：001AFE94  t1
//int main()
//{
//	Test t1(10);
//	Test t2;
//
//	t2 = fun(t1);
//
//	cout << t2.GetDate() << endl;
//
//	return 0;
//}

//Test& fun(Test x)
//{
//	int val = x.GetDate();
//	Test tmp(val);
//	return tmp;
//}
////测试:00D7FBF0  t1
////测试 : 00D7FBE4  t2
////拷贝构造：00D7FAEC  x
////测试 : 00D7FAC4  tmp
////释放：00D7FAC4  tmp
////释放：00D7FAEC  x
////this = &t 00D7FBE4 = 00D7FAC4  tmp已释放，这里有问题
////- 858993460  所以这里是随机值
////释放：00D7FBE4  t2
////释放：00D7FBF0  t1
//int main()
//{
//	Test t1(10);
//	Test t2;
//
//	t2 = fun(t1);
//
//	cout << t2.GetDate() << endl;
//
//	return 0;
//}

//Test fun(Test &x)
//{
//	int val = x.GetDate();
//	return Test(val);
//}
////测试:0115F81C  t1
////测试 : 0115F810  t2
////测试 : 0115F738  无名
////this = &t 0115F810 = 0115F738
////释放：0115F738  无名
////释放：0115F810  t2
////释放：0115F81C  t1
//int main()
//{
//	Test t1(10);
//	Test t2;
//
//	t2 = fun(t1);
//
//	return 0;
//}

//Test fun(Test x)
//{
//	int val = x.GetDate();
//	return Test(val);
//}
////测试:00F5F840   t1
////测试 : 00F5F834  t2
////拷贝构造：00F5F72C  x
////测试 : 00F5F75C  无名
////释放：00F5F72C  x
////this = &t 00F5F834 = 00F5F75C
////释放：00F5F75C  无名
////释放：00F5F834  t2
////释放：00F5F840  t1
//int main()
//{
//	Test t1(10);
//	Test t2;
//
//	t2 = fun(t1);
//
//	return 0;
//}

//Test fun(Test x)
//{
//	int val = x.GetDate();
//	Test tmp(val);
//	return tmp;//会产生一个默认的拷贝构造
//}
//
////测试:00A8FBEC  t1
////测试 : 00A8FBE0  t2
////拷贝构造：00A8FAD8  x
////测试 : 00A8FAAC  tmp
////拷贝构造：00A8FB08  无名的，拷贝tmp
////释放：00A8FAAC  tmp
////释放：00A8FAD8  x
////this = &t 00A8FBE0 = 00A8FB08
////释放：00A8FB08  无名的
////释放：00A8FBE0  t2
////释放：00A8FBEC  t1
//
//int main()
//{
//	Test t1(10);
//	Test t2;
//
//	t2 = fun(t1);
//
//	return 0;
//}



//void fun(Test x)
//{
//	int val = x.GetDate();
//	Test tmp(val);
//}
//
//int main()
//{
//	Test t1(10);
//	fun(t1);
//
//	return 0;
//}

//void fun(Test x)
//{
//	int val = x.GetDate();
//}
//
//int main()
//{
//	Test t1(10);
//	fun(t1);
//
//	return 0;
//}