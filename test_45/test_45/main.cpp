#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Person
{
public:
	Person(int age, int id) :age(age), id(id)
	{
		cout << "age = " << age << ",id = " << id << endl;
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

void main()
{
	test1();
}