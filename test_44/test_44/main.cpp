#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void test1()
{
	char s;
	while ((s = cin.get()) != EOF)
	{
		cout << s << endl;
	}
}

void test2()
{
	cout.put('a').put('b').put('c') << endl;
	//cout << endl;
}

void test3()
{
	cout << "hello world";
	cout.flush();
}

void test4()//��ʽ�����
{
	//��Ա��������ʽ
	int num = 20;
	cout << "ʮ���������" << num << endl;
	cout.unsetf(ios::dec);//ж�ص�ǰĬ�ϵ�ʮ���������ʽ
	cout.setf(ios::oct);//���óɰ˽������
	cout << "�˽��������" << num << endl;
	cout.setf(ios::showbase);//�ڰ˽������ǰ��0  ��ʮ���������ǰ��0x
	cout << "�˽��������" << num << endl;
	cout.unsetf(ios::oct);
	cout.setf(ios::hex);//���ó�ʮ���������
	cout << "ʮ�����������" << num << endl;
}

void test5()//ͨ�����Ʒ�
{
	int num = 12;
	cout << hex << num << endl;
	cout << hex
		<< setiosflags(ios::showbase)
		<< setw(10)//���ÿ��Ϊ10
		<< setfill('*')//����Ŀ������Ϊĳ���ַ�
		<< setiosflags(ios::left)//���ö��뷽ʽ
		<< num
		<< endl;
}

void test6()
{
	char* str = "test.txt";
	ifstream ism(str, ios::in);//ֻ����ʽ���ļ�
	ofstream osm("test1.txt", ios::out); 
	//ofstream osm("test1.txt", ios::out | ios::app);//׷��

	if (!ism)
	{
		cout << "���ļ�ʧ�ܣ�"<<endl;
		return;
	}
	char ch;
	while (ism.get(ch))//��ȡ�ļ��е��ַ�
	{
		cout << ch;
		osm.put(ch);	
	}
	cout << endl;

	ism.close();
	osm.close();
}

void main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	test6();
}