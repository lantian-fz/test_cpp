#define _CRT_SECURE_NO_WARNINGS 1
//�����Ĵ�����һ�������ͷ�����һ�����ַ��������硰level�����ߡ�noon���ȵȾ��ǻ��Ĵ��������ǳ�ϲ������ӵ��
//�Գ����Ļ��Ĵ������յ�ʱ�����õ���������ֱ����ַ���A���ַ���B���������ǳ�������û�а취���ַ���B������
//����Aʹ�������ַ�����һ�����Ĵ�������ܻ��������󣬰�����Ѱ���ж����ֲ���취����ʹ�´���һ�����Ĵ���
//����ַ���B�����λ�ò�ͬ�Ϳ���Ϊ��һ���İ취��
//���磺A = ��aba����B = ��b����������4�ְ�B����A�İ취��
//      * ��A�ĵ�һ����ĸ֮ǰ: "baba" ���ǻ���
//	  * �ڵ�һ����ĸ��a��֮�� : "abba" �ǻ���
//      * ����ĸ��b��֮�� : "abba" �ǻ���
//      * �ڵڶ�����ĸ'a'֮�� "abab" ���ǻ���
//  �������������Ĵ�Ϊ2
//�������� :ÿ���������ݹ����С���һ��Ϊ�ַ���A�ڶ���Ϊ�ַ���B
//�ַ������Ⱦ�С��100��ֻ����Сд��ĸ
//������� :���һ�����֣���ʾ���ַ���B�����ַ���A֮�󹹳�һ�����Ĵ��ķ�����
//����: aba
//      b
//���: 2
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

int Palindrome(string &a, string &b)
{
	int ret = 0;
	auto a_p = a.begin();

	while (a_p != a.end())
	{
		string front(a.begin(), a_p);
		string back(a_p, a.end());

		front += b;
		front += back;

		string tmp = front;
		reverse(tmp.begin(), tmp.end());

		if (strcmp(front.c_str(), tmp.c_str()) == 0)
			ret++;
		a_p++;
	}
	a += b;//�������Ϊaaaa   a   �����,���ǲ��뵽����Ƿ�Ϊ����
	string tmp = a;
	reverse(tmp.begin(), tmp.end());

	if (strcmp(a.c_str(), tmp.c_str()) == 0)
		ret++;

	return ret;
}

int main()
{
	string a;
	string b;
	//cin >> a >> b;
	getline(cin, a);
	getline(cin, b);

	cout << Palindrome(a, b) << endl;

	return 0;
}