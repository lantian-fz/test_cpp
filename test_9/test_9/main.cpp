#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1("hello world");
	
	cout << "size: "<< s1.size() << endl;
	cout << "capacity: "<< s1.capacity() << endl;
	cout << "lengh: "<< s1.length() << endl;
	cout << s1 << endl;
	cout << endl;

	s1.clear();//����ַ����������ı�������
	cout << "size: " << s1.size() << endl;
	cout << "capacity: " << s1.capacity() << endl;
	cout << "lengh: " << s1.length() << endl;
	cout << s1 << endl;
	cout << endl;

	s1.resize(10, 'a');//��s1����Ч�ַ��������ӵ�10�������λ����'a'�������
	cout << "size: " << s1.size() << endl;
	cout << "capacity: " << s1.capacity() << endl;
	cout << "lengh: " << s1.length() << endl;
	cout << s1 << endl;
	cout << endl;
	cout << endl;

	// ��s����Ч�ַ��������ӵ�15�������λ����ȱʡֵ'\0'�������
	// "aaaaaaaaaa\0\0\0\0\0"
	// ע���ʱs����Ч�ַ������Ѿ����ӵ�15��
	s1.resize(15);
	cout << "size: " << s1.size() << endl;
	cout << "capacity: " << s1.capacity() << endl;
	cout << "lengh: " << s1.length() << endl;
	cout << s1 << endl;
	cout << endl;

	s1.resize(5);//��Ч�ַ��������ٵ�5��
	cout << "size: " << s1.size() << endl;
	cout << "capacity: " << s1.capacity() << endl;
	cout << "lengh: " << s1.length() << endl;
	cout << s1 << endl;
	cout << endl;

	s1.resize(50);
	cout << "size: " << s1.size() << endl;
	cout << "capacity: " << s1.capacity() << endl;
	cout << s1 << endl;
	cout << endl;

	s1.resize(30);//��С�󲻻���Сcapacity�ռ�
	cout << "size: " << s1.size() << endl;
	cout << "capacity: " << s1.capacity() << endl;
	cout << s1 << endl;
	cout << endl;

	string s2;
	size_t sz = s2.capacity();
	for (int i = 0; i < 100; i++)
	{
		s2.push_back('c');
		if (sz != s2.capacity())
		{
			sz = s2.capacity();
			cout << "�ı���:  " << sz << endl;
		}
	}

	return 0;
}