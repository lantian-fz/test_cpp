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

void test4()//格式化输出
{
	//成员方法的形式
	int num = 20;
	cout << "十进制输出：" << num << endl;
	cout.unsetf(ios::dec);//卸载当前默认的十进制输出形式
	cout.setf(ios::oct);//设置成八进制输出
	cout << "八进制输出：" << num << endl;
	cout.setf(ios::showbase);//在八进制输出前加0  在十六进制输出前加0x
	cout << "八进制输出：" << num << endl;
	cout.unsetf(ios::oct);
	cout.setf(ios::hex);//设置成十六进制输出
	cout << "十六进制输出：" << num << endl;
}

void test5()//通过控制符
{
	int num = 12;
	cout << hex << num << endl;
	cout << hex
		<< setiosflags(ios::showbase)
		<< setw(10)//设置宽度为10
		<< setfill('*')//多余的宽度设置为某个字符
		<< setiosflags(ios::left)//设置对齐方式
		<< num
		<< endl;
}

void test6()
{
	char* str = "test.txt";
	ifstream ism(str, ios::in);//只读方式打开文件
	ofstream osm("test1.txt", ios::out); 
	//ofstream osm("test1.txt", ios::out | ios::app);//追加

	if (!ism)
	{
		cout << "打开文件失败！"<<endl;
		return;
	}
	char ch;
	while (ism.get(ch))//获取文件中的字符
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