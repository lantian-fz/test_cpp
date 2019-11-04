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

	s1.clear();//清空字符串，但不改变其容量
	cout << "size: " << s1.size() << endl;
	cout << "capacity: " << s1.capacity() << endl;
	cout << "lengh: " << s1.length() << endl;
	cout << s1 << endl;
	cout << endl;

	s1.resize(10, 'a');//将s1中有效字符个数增加到10个，多出位置用'a'进行填充
	cout << "size: " << s1.size() << endl;
	cout << "capacity: " << s1.capacity() << endl;
	cout << "lengh: " << s1.length() << endl;
	cout << s1 << endl;
	cout << endl;
	cout << endl;

	// 将s中有效字符个数增加到15个，多出位置用缺省值'\0'进行填充
	// "aaaaaaaaaa\0\0\0\0\0"
	// 注意此时s中有效字符个数已经增加到15个
	s1.resize(15);
	cout << "size: " << s1.size() << endl;
	cout << "capacity: " << s1.capacity() << endl;
	cout << "lengh: " << s1.length() << endl;
	cout << s1 << endl;
	cout << endl;

	s1.resize(5);//有效字符个数减少到5个
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

	s1.resize(30);//减小后不会缩小capacity空间
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
			cout << "改变了:  " << sz << endl;
		}
	}

	return 0;
}