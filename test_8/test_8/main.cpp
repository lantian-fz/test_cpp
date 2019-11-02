#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class Test
{
public:
	Test(int d = 0) :date(d)
	{
		cout << "����:" << this << endl;
	}

	Test(const Test &t)
	{
		cout << "�������죺" << this << endl;
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
		cout << "�ͷţ�" << this << endl;
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
//����:00AFFB44  t1
//���� : 00AFFB38  ����(t2)
//�ͷţ�00AFFB38  ����(t2)
//�ͷţ�00AFFB44  t1
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
////����:00FCFAD4  t1
////�������죺00FCF9D0  x
////���� : 00FCFAC8  ����(t2)
////�ͷţ�00FCF9D0  x
////�ͷţ�00FCFAC8  ����(t2)
////�ͷţ�00FCFAD4  t1
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
////����:00CFFC68  t1
////�������죺00CFFB64  x
////���� : 00CFFB38  tmp
////�������죺00CFFC5C  ����������������tmp
////�ͷţ�00CFFB38  tmp
////�ͷţ�00CFFB64  x
////�ͷţ�00CFFC5C  ��������,
////�ͷţ�00CFFC68  t1
////t2һֱû��������Ϊֱ�ӽ��Ǹ���������������t2
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
////����:001AFE94  t1
////���� : 001AFE88  t2
////this = &t 001AFE88 = 001AFE94
////10
////�ͷţ�001AFE88  t2
////�ͷţ�001AFE94  t1
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
////����:00D7FBF0  t1
////���� : 00D7FBE4  t2
////�������죺00D7FAEC  x
////���� : 00D7FAC4  tmp
////�ͷţ�00D7FAC4  tmp
////�ͷţ�00D7FAEC  x
////this = &t 00D7FBE4 = 00D7FAC4  tmp���ͷţ�����������
////- 858993460  �������������ֵ
////�ͷţ�00D7FBE4  t2
////�ͷţ�00D7FBF0  t1
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
////����:0115F81C  t1
////���� : 0115F810  t2
////���� : 0115F738  ����
////this = &t 0115F810 = 0115F738
////�ͷţ�0115F738  ����
////�ͷţ�0115F810  t2
////�ͷţ�0115F81C  t1
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
////����:00F5F840   t1
////���� : 00F5F834  t2
////�������죺00F5F72C  x
////���� : 00F5F75C  ����
////�ͷţ�00F5F72C  x
////this = &t 00F5F834 = 00F5F75C
////�ͷţ�00F5F75C  ����
////�ͷţ�00F5F834  t2
////�ͷţ�00F5F840  t1
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
//	return tmp;//�����һ��Ĭ�ϵĿ�������
//}
//
////����:00A8FBEC  t1
////���� : 00A8FBE0  t2
////�������죺00A8FAD8  x
////���� : 00A8FAAC  tmp
////�������죺00A8FB08  �����ģ�����tmp
////�ͷţ�00A8FAAC  tmp
////�ͷţ�00A8FAD8  x
////this = &t 00A8FBE0 = 00A8FB08
////�ͷţ�00A8FB08  ������
////�ͷţ�00A8FBE0  t2
////�ͷţ�00A8FBEC  t1
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