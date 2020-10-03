#define _CRT_SECURE_NO_WARNINGS 1
//��Ч����ĸ��λ��
//���������ַ��� s �� t ����дһ���������ж� t �Ƿ��� s ����ĸ��λ�ʡ�
//
//����: s = "anagram", t = "nagaram"         ���: true
//
//����: s = "rat", t = "car"                 ���: false
//˵��: ����Լ����ַ���ֻ����Сд��ĸ��

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

bool isAnagram_1(string s, string t) 
{
	if (s.size()!=t.size())
		return false;
	if (s.empty())
		return true;
	unordered_map<char, int> mp1;
	unordered_map<char, int> mp2;
	for (int i = 0; i < s.size(); i++)
	{
		mp1[s[i]]++;
		mp2[t[i]]++;
	}
	for (auto& e : mp1)
	{
		if (e.second != mp2[e.first])
			return false;
	}
	return true;
}

bool isAnagram_2(string s, string t)
{
	if (s.size() != t.size())
		return false;
	if (s.empty())
		return true;
	int arr1[26] = { 0 };
	int arr2[26] = { 0 };
	for (int i = 0; i < s.size(); i++)
	{
		arr1[s[i] - 'a']++;
		arr2[t[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (arr1[i] != arr2[i])
			return false;
	}
	return true;
}

bool isAnagram_3(string s, string t)
{
	if (s.size() != t.size())
		return false;
	if (s.empty())
		return true;
	int arr[26] = { 0 };
	for (int i = 0; i < s.size(); i++)
	{
		arr[s[i] - 'a']++;
		arr[t[i] - 'a']--;
	}
	for (int i = 0; i < 26; i++)
	{
		if (arr[i] != 0)
			return false;
	}
	return true;
}
void main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
		cout << isAnagram_2(s1, s2) << endl;
}