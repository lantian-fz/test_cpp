#define _CRT_SECURE_NO_WARNINGS 1
//ɾ���ظ��ַ�
//���ӣ�https://www.nowcoder.com/questionTerminal/c4ea1f2263434861aef111aa44a5b064
//��Դ��ţ����
//ţţ��һ����Сд��ĸ��ɵ��ַ���s,��s�п�����һЩ��ĸ�ظ����֡�������"banana"��,��ĸ'a'����ĸ'n'�ֱ���������κ����Ρ�
//����ţţ��ϲ���ظ�������ͬһ����ĸ,��ֻ�뱣����һ�γ��ֲ�ɾ����������ֵ���ĸ�������ţţ��ɶ�s�Ĳ�����
//��������:�������һ���ַ���s,s�ĳ���length(1 �� length �� 1000),s�е�ÿ���ַ�����Сд��Ӣ����ĸ('a' - 'z')
//�������:���һ���ַ���,��ʾ����ţţҪ����ַ���
//
//���룺banana
//�����ban

#include <iostream>
#include <string>
#include <map>
using namespace std;

void DeDuplication_1(string s)
{
	string ret = "";
	map<char, int> book;
	for (int i = 0; i < s.size(); i++)
	{
		if (!book.count(s[i]))
		{
			ret += s[i];
			book[s[i]] = 1;
		}
	}
	cout << ret;
}

void DeDuplication_2(string s)
{
	int arr[26] = { 0 };
	for (auto e : s)
	{
		if (arr[e - 'a'] == 0)
			cout << e;
		arr[e - 'a']++;
	}
}

int main()
{
	string s;
	while (cin >> s)
		DeDuplication_2(s);
}

//���ӣ�https://www.nowcoder.com/questionTerminal/c4ea1f2263434861aef111aa44a5b064
//��Դ��ţ����
//
//#include<iostream>
//#include<string>
//#include<map>
//using namespace std;
//int main(){
//	string x, res = "";
//	map<char, int> book;
//	int i;
//	for (cin >> x, i = 0; i<x.length(); i++)
//	if (!book.count(x[i])) res += x[i], book[x[i]] = 1;
//	cout << res;
//}