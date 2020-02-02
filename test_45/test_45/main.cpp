#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>//算法头文件
using namespace std;

class Person
{
public:
	Person(int age, int id) :age(age), id(id)
	{
		//cout << "age = " << age << ",id = " << id << endl;
	}

public:
	int age;
	int id;
};

void test1()
{
	Person p1(10, 20);
	Person p2(30, 40);
	char* str = "test1.txt";
	ofstream osm(str, ios::out | ios::binary);//二进制方式的读写
	osm.write((char*)&p1, sizeof(Person));
	osm.write((char*)&p2, sizeof(Person));
	osm.close();
}

void PrintVector(int v)
{
	cout << v << " ";
}

void test2()
{
	vector<int> v1;
	v1.push_back(3);
	v1.push_back(9);
	v1.push_back(5);
	v1.push_back(8);

	vector<int>::iterator br = v1.begin();//定义迭代器
	vector<int>::iterator er = v1.end();

	for_each(br, er, PrintVector);
	cout << endl;
}

void test3()
{
	vector<Person> v2;
	Person p1(3, 5);
	Person p2(8, 9);
	v2.push_back(p1);
	v2.push_back(p2);
	vector<Person>::iterator it = v2.begin();
	for (; it != v2.end(); it++)
	{
		cout << "age = " << (*it).age << ",id = " << (*it).id << endl;
	}
}

void test4()
{
	vector<int> v3;
	for (int i = 0; i < 100; i++)
	{
		v3.push_back(i);
	}
	cout << "size = " << v3.size() << ",capacity = " << v3.capacity() << endl;
	v3.resize(10);
	cout << "size = " << v3.size() << ",capacity = " << v3.capacity() << endl;

	vector<int>(v3).swap(v3);//巧用swap收缩空间
	//会产生匿名对象，用匿名对象和v3交换后，匿名对象销毁
	cout << "size = " << v3.size() << ",capacity = " << v3.capacity() << endl;

}

void main()
{
	//test1();
	//test2();
	//test3();
	test4();
}