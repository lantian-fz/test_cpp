#define _CRT_SECURE_NO_WARNINGS 1
//“回文串”是一个正读和反读都一样的字符串，比如“level”或者“noon”等等就是回文串。花花非常喜欢这种拥有
//对称美的回文串，生日的时候她得到两个礼物分别是字符串A和字符串B。现在她非常好奇有没有办法将字符串B插入字
//符串A使产生的字符串是一个回文串。你接受花花的请求，帮助她寻找有多少种插入办法可以使新串是一个回文串。
//如果字符串B插入的位置不同就考虑为不一样的办法。
//例如：A = “aba”，B = “b”。这里有4种把B插入A的办法：
//      * 在A的第一个字母之前: "baba" 不是回文
//	  * 在第一个字母‘a’之后 : "abba" 是回文
//      * 在字母‘b’之后 : "abba" 是回文
//      * 在第二个字母'a'之后 "abab" 不是回文
//  所以满足条件的答案为2
//输入描述 :每组输入数据共两行。第一行为字符串A第二行为字符串B
//字符串长度均小于100且只包含小写字母
//输出描述 :输出一个数字，表示把字符串B插入字符串A之后构成一个回文串的方法数
//输入: aba
//      b
//输出: 2
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
	a += b;//如果输入为aaaa   a   的情况,考虑插入到最后是否为回文
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