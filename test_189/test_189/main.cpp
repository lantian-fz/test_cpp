#define _CRT_SECURE_NO_WARNINGS 1
//����-10.������ʽƥ��
//����һ���ַ��� s ��һ���ַ����� p��������ʵ��һ��֧�� '.' �� '*' ��������ʽƥ�䡣
//'.' ƥ�����ⵥ���ַ�
//'*' ƥ���������ǰ�����һ��Ԫ��
//��νƥ�䣬��Ҫ���� ���� �ַ��� s�ģ������ǲ����ַ�����
//˵��:
//s ����Ϊ�գ���ֻ������ a-z ��Сд��ĸ��
//p ����Ϊ�գ���ֻ������ a-z ��Сд��ĸ���Լ��ַ� . �� *��
//ʾ�� 1:
//����:
//s = "aa"
//p = "a"
//���: false
//����: "a" �޷�ƥ�� "aa" �����ַ�����
//
//ʾ�� 2:
//����:
//s = "aa"
//p = "a*"
//���: true
//����: ��Ϊ '*' �������ƥ���������ǰ�����һ��Ԫ��, ������ǰ���Ԫ�ؾ��� 'a'����ˣ��ַ��� "aa" �ɱ���Ϊ 'a' �ظ���һ�Ρ�
//
//ʾ�� 3:
//����:
//s = "ab"
//p = ".*"
//���: true
//����: ".*" ��ʾ��ƥ�����������'*'�������ַ���'.'����
//
//ʾ�� 4:
//����:
//s = "aab"
//p = "c*a*b"
//���: true
//����: ��Ϊ '*' ��ʾ������������� 'c' Ϊ 0 ��, 'a' ���ظ�һ�Ρ���˿���ƥ���ַ��� "aab"��
//
//ʾ�� 5:
//����:
//s = "mississippi"
//p = "mis*is*p*."
//���: false

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isMatch(string s, string p) 
{
	if (p.empty()) 
		return s.empty();
	int m = s.size(), n = p.size();
	vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
	dp[0][0] = true;
	//�Ƚ�p�Ŀ�ȥ��ͷ�ҳ���
	for (int j = 0; j < n; j++)
	{
		if (p[j] == '*')
			dp[0][j + 1] = dp[0][j - 1];
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (s[i] == p[j] || p[j] == '.')
				dp[i + 1][j + 1] = dp[i][j];
			else if (p[j] == '*')
			{
				//�ɺ��Ի�p�ɶ�ƥ��
				dp[i + 1][j + 1] = dp[i + 1][j - 1] || (dp[i][j + 1] && (p[j - 1] == s[i] || p[j - 1] == '.'));
			}
			else
				dp[i + 1][j + 1] = false;
		}
	}
	return dp[m][n];
}

int main()
{
	string s, p;
	while (cin >> s >> p)
		cout << isMatch(s, p) << endl;

	return 0;
}