#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//C++�е�����ת��
void test1()
{
	int a = 65;
	char c = static_cast<char>(a);
	cout << c << endl;
	//static_cast ����ת�����õ��������ͣ����о��м̳й�ϵ��ָ�������
	//�ȿ��Ը���ת���࣬Ҳ��������ת����


	//dynamic_cast ת�����м̳й�ϵ��ָ������ã���ת��ǰ��������ͼ�飬
	//������ָ�����ת��Ϊ����ָ�룬����ָ�벻����ת��Ϊ����ָ�루����ȫ��
	//����ת��������������

	//const_cast   //��Ҫ���const��ת��

	//reinterpret_cast //ǿ������ת��
}

int divide(int x, int y)
{
	if (y == 0)
	{
		throw y;//���쳣
	}
	return x / y;
}

void test2()
{
	try //����ȥ�����쳣
	{
		divide(10, 0);
	}
	catch (int e)  //�쳣ʱ�������ͽ���ƥ��
	{
		cout << "����Ϊ" << e << endl;
	}
}

void Div(int x, int y)
{
	divide(x, y);
}

void test3()//�쳣�����ϲ㺯�����쳣������쳣�׵���㻹û�д�������ͻ�ҵ�
{
	try
	{
		Div(10, 0);
	}
	catch (int e)
	{
		cout << "����Ϊ" << e << endl;
	}
	catch (...)//����ƥ�������쳣����������
	{

	}
}

void main()
{
	//test1();
	//test2();
	test3();
}