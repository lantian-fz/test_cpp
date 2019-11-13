#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

namespace Test
{
	class mystring
	{
	public:
		mystring(const char *str = "")
		{
			this->m_size = strlen(str);
			this->m_capacity = this->m_size;
			this->m_str = new char[this->m_capacity + 1];
			strcpy(this->m_str, str);
		}

		mystring(const mystring &s) :m_str(nullptr), m_size(0), m_capacity(0)
		{
			mystring tmp(s.m_str);
			MySwap(tmp);
		}

		~mystring()
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
		void MySwap(mystring &s)
		{
			swap(this->m_str, s.m_str);
			swap(this->m_size, s.m_size);
			swap(this->m_capacity, s.m_capacity);
		}

		size_t getSize()
		{
			return this->m_size;
		}

		size_t getCapacity()
		{
			return this->m_capacity;
		}

	private:
		char *m_str;
		size_t m_capacity;
		size_t m_size;
	};

}
using namespace Test;

int main()
{
	mystring s1("dd");
	mystring s2 = "abc";
	mystring s3(s1);

	return 0;
}