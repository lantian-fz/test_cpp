#define _CRT_SECURE_NO_WARNINGS 1
//ƹ�����
//nowcoder�����У�A��B��ƹ�����к�˫ϲ�ġ��������ǵġ�����������Ҫ�б�A���Ƿ������B�������е����࣬
//����ÿ���������������B���е�����������ô���أ�
//�������� :�����ж������ݡ�ÿ�����ݰ��������ַ���A��B������A����B���е�ƹ����ÿ��ƹ������һ����д��ĸ��ʾ��
//	      ����ͬ���͵�ƹ����Ϊ��ͬ�Ĵ�д��ĸ���ַ������Ȳ�����10000��
//������� :ÿһ�������Ӧһ����������B�����������������A�ж��У�����ÿ�����������������A���������Yes�������������No����
//����
//ABCDFYE CDE
//ABCDGEAS CDECDE
//���
//Yes
//No

#include <iostream>
#include <string>
using namespace std;

void YesNo(string &s1, string &s2)
{
	int hash1[26] = { 0 };
	int hash2[26] = { 0 };
	for (size_t i = 0; i < s1.size(); i++)
		hash1[s1[i] - 'A']++;
	for (size_t i = 0; i < s2.size(); i++)
		hash2[s2[i] - 'A']++;
	for (int i = 0; i < 26; i++)
	{
		if (hash2[i]>hash1[i])
		{
			cout << "No" << endl;
			return;
		}
	}
	cout << "Yes" << endl;
}

int main()
{
	string s1;
	string s2;

	while (cin >> s1 >> s2)
		YesNo(s1, s2);

	return 0;
}