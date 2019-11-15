#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <assert.h>
#include <string>
using namespace std;

namespace Test
{
	class mystring
	{
		friend ostream& operator<<(ostream &out, const mystring &another);
		//friend istream& operator>>(istream &in, const mystring &another);
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
		mystring& operator=(const mystring &another)
		{
			if (this == &another)
				return *this;
			mystring tmp(another.m_str);
			MySwap(tmp);
			return *this;
		}

		char operator[](size_t i)
		{
			assert(i < this->m_size);
			return m_str[i];
		}

		mystring& operator+(const char c)
		{
			push_buck(c);
			return *this;
		}
		mystring& operator+(const char* str)
		{
			char *tmp = new char[m_size];
			strcpy(tmp, m_str);
			m_str = new char[strlen(tmp) + strlen(str) + 1];
			strcpy(m_str, tmp);
			strcat(m_str, str);
			delete[] tmp;
			m_size += strlen(str);
			if (m_size > m_capacity)
				reserve(2 * m_capacity);
			return *this;
		}
		mystring& operator+(const mystring &str)
		{
			char *tmp = new char[strlen(m_str)+1];
			strcpy(tmp, m_str);
			m_str = new char[strlen(tmp) + strlen(str.m_str) + 1];
			strcpy(m_str, tmp);
			strcat(m_str, str.m_str);
			delete[] tmp;
			m_size += strlen(str.m_str);
			if (m_size > m_capacity)
				reserve(2 * m_capacity);
			return *this;
		}



	public:
		typedef char* iterator;
		typedef const char* const_iterator;

	public:
		iterator begin()
		{
			return m_str;
		}
		iterator end()
		{
			return m_str + m_size;
		}
		const_iterator begin()const
		{
			return m_str;
		}
		const_iterator end()const
		{
			return m_str + m_size;
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

		void resize(size_t sz, char c = '\0')
		{
			if (sz > m_size)
			{
				if (sz > m_capacity)
					reserve(sz);
				memset(m_str + m_size, c, sz - m_size);
			}
			m_str[sz] = '\0';
			m_size = sz;
		}
		void reserve(size_t capacity)
		{
			if (capacity > m_capacity)
			{
				char *new_str = new char[capacity + 1];
				m_capacity = capacity;
				strcpy(new_str, m_str);
				delete[] m_str;
				m_str = new_str;
			}
		}

		void push_buck(char c)
		{
			if (m_size == m_capacity)
				reserve(2 * m_capacity);
			m_str[m_size++] = c;
			m_str[m_size] = '\0';
		}
		void pop_buck()
		{
			if (m_size > 0)
			{
				m_size--;
				m_str[m_size] = '\0';
			}
		}

		void clear()
		{
			m_size = 0;
			m_str[m_size] = '\0';
		}
		bool empty()
		{
			if (m_size == 0)
				return true;
			else
				return false;
		}

	private:
		char *m_str;
		size_t m_capacity;
		size_t m_size;
	};

	ostream& operator<<(ostream &out, const mystring &another)
	{
		out << another.m_str;
		return out;
	}

	//istream& operator>>(istream &in, mystring &another)
	//{
	//	char *str=nullptr;
	//	in >> str;
	//	mystring tmp(str);
	//	another.MySwap(tmp);

	//	return in;
	//}

}
using namespace Test;

int main()
{
	mystring s1("abcdefg");
	mystring s2 = "abc";

	//for (auto e : s1)
	//{
	//	cout << e;
	//}
	//cout << endl;
	s1.reserve(100);
	cout << s1 << endl;
	cout << "size = " << s1.getSize() << endl;
	cout << "capacity = " << s1.getCapacity() << endl;
	mystring s3(s1);
	cout << s3 << endl;
	cout << "size = " << s3.getSize() << endl;
	cout << "capacity = " << s3.getCapacity() << endl;
	cout << "----------------------" << endl;
	string s4("abcdefg");
	s4.reserve(100);
	cout << s4 << endl;
	cout << "size = " << s4.size() << endl;
	cout << "capacity = " << s4.capacity() << endl;

	string s5(s4);
	cout << s5 << endl;
	cout << "size = " << s5.size() << endl;
	cout << "capacity = " << s5.capacity() << endl;//string的拷贝构造函数不会将capacity大小也拷贝过去

	//mystring s4;
	//cout << "size = " << s1.getSize() << endl;
	//cout << "capacity = " << s1.getCapacity() << endl;
	//s1 + s2;
	//cout << s1 << endl;
	//cout << "size = " << s1.getSize() << endl;
	//cout << "capacity = " << s1.getCapacity() << endl;
	//s4 = s1;
	//cout << s4 << endl;

	//s4.pop_buck();
	//s4.pop_buck();
	//cout << s4 << endl;
	//s4.push_buck('a');
	//cout << s4 << endl;

	//mystring s5 = s2;
	//cout << s5 << endl;
	//cout << "size = " << s5.getSize() << endl;
	//cout << "capacity = " << s5.getCapacity() << endl;
	//s5 = s1 + s2;
	//cout << s5 << endl;
	//cout << "size = " << s5.getSize() << endl;
	//cout << "capacity = " << s5.getCapacity() << endl;

	//cout << s4[1] << endl;
	//s4[0] = 'c';
	//cin >> s4;
	//cout << s4 << endl;

	//mystring::iterator it = s4.begin();

	//while (it != s4.end())
	//{
	//	cout << *it ;
	//	it++;
	//}
	//cout << endl;

	//cout << "size = " << s4.getSize() << endl;
	//cout << "capacity = " << s4.getCapacity() << endl;

	//s4.resize(10);
	//cout << "size = " << s4.getSize() << endl;
	//cout << "capacity = " << s4.getCapacity() << endl;

	//s4.reserve(20);
	//cout << "size = " << s4.getSize() << endl;
	//cout << "capacity = " << s4.getCapacity() << endl;

	//s4.reserve(5);
	//cout << "size = " << s4.getSize() << endl;
	//cout << "capacity = " << s4.getCapacity() << endl;

	//s4.resize(5);
	//cout << "size = " << s4.getSize() << endl;
	//cout << "capacity = " << s4.getCapacity() << endl;

	//string s5;

	return 0;
}