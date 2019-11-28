#pragma once

template<typename T>
class Person
{
public:
	Person(T age);
	
public:
	void Show();
private:
	T age;
};

template<typename T>
Person<T>::Person(T age)
{
	this->age = age;
}

template<typename T>
void Person<T>::Show()
{
	cout << "age = " << this->age << endl;
}