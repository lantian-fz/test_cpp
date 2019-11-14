#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class Test
{
public:
	Test() 
	{
		m_id = 0;
		m_name = nullptr;
	}

	Test(int id, char* name)
	{
		m_id = id;
		m_name = new char[strlen(name) + 1];
		strcpy(m_name, name);
	}

	Test(const Test &another)
	{
		m_id = another.m_id;
		m_name = new char[strlen(another.m_name) + 1];
		strcpy(m_name, another.m_name);
	}

	~Test()
	{
		m_id = -1;
		if (this->m_name != nullptr)
		{
			delete[] this->m_name;
			this->m_name = nullptr;
		}
	}

	Test& operator=(const Test &another)
	{
		if (this != &another)
		{
			this->m_id = another.m_id;
			if (this->m_name != nullptr)
			{
				delete[] this->m_name;
				this->m_name = nullptr;
			}
			m_name = new char[strlen(another.m_name) + 1];
			strcpy(m_name, another.m_name);
		}
		return *this;
	}

public:
	void Print()
	{
		cout << "id = " << m_id << ",name = " << m_name << endl;
	}

private:
	int m_id;
	char* m_name;
};

int main()
{
	//Test t1;
	//t1.Print();

	Test t2(10, "abc");
	t2.Print();

	Test t3(20, "def");
	t3.Print();

	t3 = t2;
	t3.Print();


	return 0;
}