#define _CRT_SECURE_NO_WARNINGS 1
//����-387.�ַ����еĵ�һ��Ψһ�ַ�
//����һ���ַ������ҵ����ĵ�һ�����ظ����ַ���������������������������ڣ��򷵻� - 1��
//���� :s = "leetcode"           ���� 0.
//      s = "loveleetcode",      ���� 2.
//ע����������Լٶ����ַ���ֻ����Сд��ĸ��

#include <iostream>
#include <string>
using namespace std;

int firstUniqChar(string s) 
{
	int arr[256] = { 0 };
	for (size_t i = 0; i < s.size(); i++)
		arr[s[i]]++;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (arr[s[i]] == 1)
			return i;
	}
	return -1;
}

int main()
{
	string s;
	while (cin >> s)
		cout << firstUniqChar(s) << endl;

	return 0;
}