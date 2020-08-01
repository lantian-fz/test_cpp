#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

class MyString
{
	friend MyString& operator+(const MyString &s1, const MyString &s2);
public:
	MyString(const char* str = "")
	{
		this->m_size = strlen(str);
		this->m_capacity = this->m_size;
		this->m_str = new char[this->m_capacity + 1];
		strcpy(this->m_str, str);
	}

	MyString(const MyString &s) :m_str(nullptr), m_size(0), m_capacity(0)
	{
		MyString tmp(s.m_str);
		MySwap(tmp);
	}

	~MyString()
	{
		if (this->m_str)
		{
			delete[] this->m_str;
			this->m_str = nullptr;
			this->m_size = 0;
			this->m_capacity = 0;
		}
	}

public:
	MyString& operator=(const MyString &s)
	{
		if (this == &s)
			return *this;
		MyString tmp(s.m_str);
		MySwap(tmp);
		return *this;
	}

	//MyString& operator+(const MyString &s)
	//{
	//	reserve(this->m_capacity + s.m_capacity + 1);
	//	strcat(this->m_str, s.m_str);
	//	this->m_size = strlen(this->m_str);
	//	return *this;
	//}

	MyString& operator+=(const MyString &s)
	{
		//	MyString tmp = *this + s;
		//	MySwap(tmp);
		*this + s;
		return *this;
	}

	char operator[](size_t i)
	{
		assert(i < this->m_size);
		return this->m_str[i];
	}

public:
	typedef char* iterator;
	typedef const char* const_iterator;

public:
	iterator begin(){ return this->m_str; }
	iterator end(){ return this->m_str + this->m_size; }
	const_iterator begin()const{ return this->m_str; }
	const_iterator end()const{ return this->m_str + this->m_size; }
	void push_back(char c)
	{
		if (this->m_size == this->m_capacity)
			this->reserve(2 * this->m_size);
		this->m_str[this->m_size++] = c;
		this->m_str[this->m_size] = '\0';
	}
public:
	void MySwap(MyString &s)
	{
		swap(this->m_str, s.m_str);
		swap(this->m_size, s.m_size);
		swap(this->m_capacity, s.m_capacity);
	}
	size_t size(){ return this->m_size; }
	size_t capacity(){ return this->m_capacity; }
	void reserve(size_t capacity)
	{
		if (capacity > this->m_capacity)
		{
			char* new_str = new char[capacity + 1];
			m_capacity = capacity;
			strcpy(new_str, this->m_str);
			this->m_str = new_str;
		}
	}
	void resize(size_t sz, char c = '\0')
	{
		if (sz > this->m_size)
		{
			if (sz > this->m_capacity)
				reserve(sz);
			memset(this->m_str + this->m_size, c, sz - this->m_size);
		}
		this->m_str[sz] = '\0';
		this->m_size = sz;
	}


private:
	char* m_str;
	size_t m_size;
	size_t m_capacity;
};

MyString& operator+(const MyString &s1, const MyString &s2)
{
	MyString tmp;
	tmp.reserve(s1.m_capacity + s2.m_capacity + 1);
	tmp.m_str = s1.m_str;
	strcat(tmp.m_str, s2.m_str);
	tmp.m_size = strlen(tmp.m_str);
	return tmp;
}


void main()
{
	MyString s1 = "abc", s2 = "def";
	MyString s3 = s1 + s2;
}