#define _CRT_SECURE_NO_WARNINGS 1

#include "MyArray.h"

MyArray::MyArray()
{
	this->len = 0;
	this->space = nullptr;
}

MyArray::MyArray(int len)
{
	if (len <= 0)
		return;
	this->len = len;
	this->space = new int[this->len];
}

MyArray::~MyArray()
{
	if (this->space != nullptr)
	{
		delete[] this->space;
		this->space = nullptr;
		this->len = 0;
	}
}

void MyArray::setData(int index, int data)
{
	if (this->space != nullptr)
	{
		if (index >= 0 && index < this->len)
			this->space[index] = data;
	}
}

int MyArray::getData(int index)
{
	return this->space[index];
}

int MyArray::getLen()
{
	return this->len;
}

MyArray::MyArray(const MyArray &another)
{
	if (another.len <= 0)
		return;
	this->len = another.len;
	this->space = new int[another.len];
	for (int i = 0; i < another.len; i++)
	{
		this->space[i] = another.space[i];
	}
}

void MyArray::operator=(const MyArray &another)
{
	if (this != &another)
	{
		if (another.len <= 0)
			return;
		this->len = another.len;
		this->space = new int[another.len];
		for (int i = 0; i < another.len; i++)
		{
			this->space[i] = another.space[i];
		}
	}
}
