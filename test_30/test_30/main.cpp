#define _CRT_SECURE_NO_WARNINGS 1#

#include <iostream>
using namespace std;

template<typename T>
class Person
{
	//template<typename T>
	friend ostream& operator<< <T>(ostream& out, Person<T>& p);
public:
	Person(T age, T id);
	void Show();
private:
	T m_age;
	T m_id;
};

template<typename T>
Person<T>::Person(T age, T id)
{
	this->m_age = age;
	this->m_id = id;
}

template<typename T>
void Person<T>::Show()
{
	cout << "age = " << m_age << ",id = " << m_id << endl;
}

template<typename T>
ostream& operator<<(ostream& out, Person<T>& p)
{
	out << "age = " << p.m_age << ",id = " << p.m_id;
	return out;
}

void test1()
{
	Person<int> p1(10, 20);
	p1.Show();
	cout << p1 << endl;
}

int main()
{
	test1();
	
	return 0;
}