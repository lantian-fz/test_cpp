#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
using namespace std;

class Parent
{
public:
	int pub;
protected:
	int pro;
private:
	int pri;
};

class Child1 :public Parent  //公有继承
{
public:
	void fun()
	{
		cout << pub << endl;//pub是父类的public成员，在public继承 类的 内部 和 外部  都可以访问

		cout << pro << endl;//pro是父类的protected成员，在public继承 类的 内部 可以访问
		//pro可以在孙子类里面使用
		//cout << pri << endl;//pri是父类的private成员，在public继承 类的 内部 和 外部  都不可以访问
	}
};

//孙子
class SubChild1 :public Child1
{
public:
	void fun()
	{
		cout << pro << endl;
	}
};

class Child2 :protected Parent  //保护继承
{
public:
	void fun()
	{
		pub;//pub通过protected继承 能够在类的内部访问，但在类的外部不可以访问
		pro;
		//pri;
	}
};

class SubChild2 :public Child2
{
public:
	void fun()
	{
		pub;
		pro;
		//pri;
	}
};

class Child3 :private Parent  //私有继承
{
public:
	void fun()
	{
		pub;
		pro;
		//pri;
	}
};

class SubChild3 :public Child3
{
public:
	void fun()
	{
		//pub;//都继承不了
		//pro;
		//pri;
	}
};

int main()
{
	Child1 c1;
	c1.pub;

	Child2 c2;
	//c2.pub;

	Parent p1 = c1;//子类对象可以直接赋值给父类对象

	//Child1 c3 = p1;//不可以这样写

	return 0;
}

//class Student
//{
//public:
//	Student(int id, string name)
//	{
//		this->id = id;
//		this->name = name;
//	}
//
//
//public:
//	void Print1()
//	{
//		cout << "id = " << this->id << ",name = " << this->name << endl;
//	}
//private:
//	int id;
//	string name;
//};
//
//class Stuend2 :public Student
//{
//public:
//	Stuend2(int id, string name, int score) :Student(id, name)
//	{
//		this->score = score;
//	}
//
//public:
//	void Print2()
//	{
//		Student::Print1();
//		cout << "score = " << this->score << endl;
//	}
//
//private:
//	int score;
//};
//
//int main()
//{
//	Stuend2 s1(101, "zhangsan", 95);
//	s1.Print2();
//
//	return 0;
//}