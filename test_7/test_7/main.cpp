#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

/////////////////////////////////////////
//length()
//operator[]
//operator+
//operator+=
//operator > < >= <= == !=
/////////////////////////////////////////
class String
{
	friend ostream& operator << (ostream &out, const String &s);
public:
	String(char *str = "")
	{
		m_data = new char[strlen(str) + 1];
		strcpy(m_data, str);
	}
	String(const String &s)
	{
		m_data = new char[strlen(s.m_data) + 1];
		strcpy(m_data, s.m_data);
	}
	String& operator=(const String &s)
	{
		if (this != &s)
		{
			free(m_data);
			m_data = new char[strlen(s.m_data) + 1];
			strcpy(m_data, s.m_data);
		}
		return *this;
	}

	char& operator[](int i)
	{
		return m_data[i];
	}

	String& operator+(const String &s)
	{
		char *tmp = new char[strlen(m_data)];
		strcpy(tmp, m_data);
		m_data = new char[strlen(m_data) + strlen(s.m_data) + 1];
		strcpy(m_data, tmp);
		strcat(m_data, s.m_data);
		return *this;
	}

	String& operator+=(const String &s)
	{
		char *tmp = new char[strlen(m_data)];
		strcpy(tmp, m_data);
		m_data = new char[strlen(m_data) + strlen(s.m_data) + 1];
		strcpy(m_data, tmp);
		strcat(m_data, s.m_data);
		return *this;
	}

	bool operator==(String &s)
	{
		if (lenght() != s.lenght())
			return false;
		for (int i = 0; i < lenght(); i++)
		{
			if (m_data[i] != s.m_data[i])
				return false;
		}
		return true;
	}

	bool operator!=(String &s)
	{
		return !(*this == s);
	}

	bool operator>(const String &s)
	{
		if (strcmp(m_data, s.m_data) > 0)
			return true;
		else
			return false;
	}

	bool operator<(const String &s)
	{
		if (strcmp(m_data, s.m_data) < 0)
			return true;
		else
			return false;
	}

	bool operator>=(String &s)
	{
		return (*this>s) || (*this == s);
	}

	bool operator<=(String &s)
	{
		return (*this < s) || (*this == s);
	}

	~String()
	{
		delete[]m_data;
		m_data = NULL;
	}
public:
	int lenght()
	{
		return strlen(m_data);
	}
private:
	char *m_data;
};

ostream& operator<<(ostream &out, const String &s)
{
	out << s.m_data;
	return out;
}

int main()
{
	String s1("Hello "); //s1[0] ==> H
	String s2("Bit.");

	cout << s1.lenght() << endl;

	for (int i = 0; i<s1.lenght(); ++i)
		cout << s1[i];
	cout << endl;

	String s = s1 + s2; //s = Hello Bit.

	s1 += s2;    
	for (int i = 0; i < s1.lenght(); i++)
		cout << s1[i];
	cout << endl;
	if (s1 == s2)
		cout << "s1 == s2" << endl;
	if (s1 != s2)
		cout << "s1 != s2" << endl;
	if (s1 > s2)
		cout << "s1 > s2" << endl;
	if (s1 < s2)
		cout << "s1 < s2" << endl;
	if (s1 >= s2)
		cout << "s1 >= s2" << endl;
	if (s1 <= s2)
		cout << "s1 <= s2" << endl;
	
	cout << s1 << endl;

	//s1 << cout << endl;

	return 0;
}