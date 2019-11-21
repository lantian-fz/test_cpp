#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
using namespace std;
//����һ���ַ�����һ������ k������Ҫ�Դ��ַ�����ͷ�����ÿ�� 2k ���ַ���ǰk���ַ����з�ת��
//���ʣ������ k ���ַ�����ʣ�������ȫ����ת�������С�� 2k �����ڻ���� k ���ַ���
//��תǰ k ���ַ�������ʣ����ַ�����ԭ����
//ʾ�� :
//
//���� : s = "abcdefg", k = 2
//��� : "bacdfeg"
//Ҫ�� :
//	���ַ���ֻ����Сд��Ӣ����ĸ��
//	�����ַ����ĳ��Ⱥ� k ��[1, 10000]��Χ�ڡ�
void reverse(string &s, int i, int k)
{
	int j = i + k - 1;
	k /= 2;
	while (k)
	{
		swap(s[i++], s[j--]);
		k--;
	}
}
string reverseStr(string s, int k)
{
	int sz = s.size();
	if (k>sz)
		return s;
	int i = 0;
	while (i < sz)
	{
		if (sz - i < k)
		{
			//ʣ�µ�ȫ����ת
			reverse(s, i, sz - i);	
		}
		else
		{
			//ÿ2k���ַ���ǰk���ַ���ת
			reverse(s, i, k);
			i += 2 * k;
		}
	}
	return s;
}

int main()
{
	string s = "abcd";
	string s2 = reverseStr(s, 2);
	cout << s2 << endl;

	return 0;
}
//void reverse(string &s,int k)
//{
//	int i, j;
//	for (i = 0, j = k-1; i < j; i++, j--)
//	{
//		swap(s[i], s[j]);
//	}
//}
//string reverseStr(string s, int k) 
//{
//	int sz = s.size();
//	if (k>sz)
//		return s;
//	int i = 0;
//	string tmp;
//	tmp.resize(10000);
//	while (i <= sz)
//	{
//		if (sz - i < k)
//		{
//			//ʣ�µ�ȫ����ת
//
//			int x = i;
//			for (int j = 0; i < sz; i++, j++)
//			{
//				tmp[j] = s[i];
//			}
//			reverse(tmp,k);
//			for (int j = 0; tmp[j] != '\0'; j++)
//			{
//				s[x++] = tmp[j];
//			}
//		}
//		else
//		{
//			//ÿ2k���ַ���ǰk���ַ���ת
//
//			int x = i;
//			for (int j = 0; j < k; j++, i++)
//			{
//				tmp[j] = s[i];
//			}
//			reverse(tmp,k);
//			for (int j = 0; j < k; j++)
//			{
//				s[x++] = tmp[j];
//				i++;
//			}
//		}
//	}
//	return s;
//}
//
//int main()
//{
//	string s = "abcdefg";
//	string s2 = reverseStr(s, 2);
//	cout << s2 << endl;
//
//	return 0;
//}