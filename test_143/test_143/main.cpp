#define _CRT_SECURE_NO_WARNINGS 1
//【中级】单词倒排
//对字符串中的所有单词进行倒排。
//1、每个单词是以26个大写或小写英文字母构成；
//2、非构成单词的字符均视为单词间隔符；
//3、要求倒排后的单词间隔符以一个空格表示；如果原字符串中相邻单词间有多个间隔符时，倒排转换后也只允许出现一个空格间隔符；
//4、每个单词最长20个字母；
//输入描述 :输入一行以空格来分隔的句子
//输出描述 :输出句子的逆序
//输入
//I am a student
//输出
//student a am I

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	while (getline(cin, s))
	{
		string ret;
		auto it = s.begin();
		while (it != s.end())
		{
			string tmp;
			while (it != s.end() && (*it >= 'a'&&*it <= 'z' || *it >= 'A'&&*it <= 'Z'))
			{
				tmp += *it;
				it++;
			}
			while (it != s.end() && !(*it >= 'a'&&*it <= 'z' || *it >= 'A'&&*it <= 'Z'))
				it++;
			ret = ' ' + tmp + ret;
		}
		ret.erase(0, 1);
		cout << ret << endl;
	}

	return 0;
}