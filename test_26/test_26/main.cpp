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

class Child1 :public Parent  //���м̳�
{
public:
	void fun()
	{
		cout << pub << endl;//pub�Ǹ����public��Ա����public�̳� ��� �ڲ� �� �ⲿ  �����Է���

		cout << pro << endl;//pro�Ǹ����protected��Ա����public�̳� ��� �ڲ� ���Է���
		//pro����������������ʹ��
		//cout << pri << endl;//pri�Ǹ����private��Ա����public�̳� ��� �ڲ� �� �ⲿ  �������Է���
	}
};

//����
class SubChild1 :public Child1
{
public:
	void fun()
	{
		cout << pro << endl;
	}
};

class Child2 :protected Parent  //�����̳�
{
public:
	void fun()
	{
		pub;//pubͨ��protected�̳� �ܹ�������ڲ����ʣ���������ⲿ�����Է���
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

class Child3 :private Parent  //˽�м̳�
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
		//pub;//���̳в���
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

	Parent p1 = c1;//����������ֱ�Ӹ�ֵ���������

	//Child1 c3 = p1;//����������д

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