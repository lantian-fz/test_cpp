#define _CRT_SECURE_NO_WARNINGS 1
//��һ�仰�ĵ��ʽ��е��ã���㲻���á����� I like beijing.�����������Ϊ��beijing. like I
//�������� :ÿ�������������1������������ I like beijing.�����������Ȳ�����100
//������� :�����������֮����ַ���, �Կո�ָ�
//����: I like beijing.
//���: beijing. like I

//#include <iostream>
//#include <string>
//using namespace std;
//// cin��ȡstringʱ�Զ��ᱻ�ո�ָ���������һ���ַ����洢�����������
//int main()
//{
//	string s1, s2;
//	cin >> s2;
//	while (cin >> s1)
//		s2 = s1 + " " + s2;
//	cout << s2 << endl;
//	return 0;
//}
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string& Reverse(string &s)
{
	reverse(s.begin(), s.end());
	string::iterator it1 = s.begin();
	string::iterator it2 = s.begin();
	int n = 0;
	while (it1 != s.end())
	{
		if (*it1 == ' ')
		{
			reverse(it2, it2 + n);
			it2 += n+1;
			n = 0;
			it1++;
			continue;
		}
		if (it1 + 1 == s.end())
		{
			reverse(it2, s.end());
			break;
		}
		it1++;
		n++;
	}

	return s;
}

int main()
{
	string s;
	getline(cin, s);
	cout << Reverse(s) << endl;

	return 0;
}