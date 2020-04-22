#define _CRT_SECURE_NO_WARNINGS 1
//乒乓球筐
//nowcoder有两盒（A、B）乒乓球，有红双喜的、有亚力亚的……现在他需要判别A盒是否包含了B盒中所有的种类，
//并且每种球的数量不少于B盒中的数量，该怎么办呢？
//输入描述 :输入有多组数据。每组数据包含两个字符串A、B，代表A盒与B盒中的乒乓球，每个乒乓球用一个大写字母表示，
//	      即相同类型的乒乓球为相同的大写字母。字符串长度不大于10000。
//输出描述 :每一组输入对应一行输出：如果B盒中所有球的类型在A中都有，并且每种球的数量都不大于A，则输出“Yes”；否则输出“No”。
//输入
//ABCDFYE CDE
//ABCDGEAS CDECDE
//输出
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