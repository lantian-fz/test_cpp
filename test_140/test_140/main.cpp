#define _CRT_SECURE_NO_WARNINGS 1
//电话号码
//  1   2   3
//     ABC DEF
//  4   5   6
// GHI JKL MNO
//  7   8   9
//PQRS TUV WXYZ
//上图是一个电话的九宫格，如你所见一个数字对应一些字母，因此在国外企业喜欢把电话号码设计成与自己公司名字相对应。
//例如公司的Help Desk号码是4357，因为4对应H、3对应E、5对应L、7对应P，因此4357就是HELP。
//同理，TUT-GLOP就代表888-4567、310-GINO代表310-4466。
//NowCoder刚进入外企，并不习惯这样的命名方式，现在给你一串电话号码列表，请你帮他转换成数字形式的号码，并去除重复的部分。
//输入描述 :输入包含多组数据。每组数据第一行包含一个正整数n（1≤n≤1024）。
//          紧接着n行，每行包含一个电话号码，电话号码仅由连字符“-”、数字和大写字母组成。
//          没有连续出现的连字符，并且排除连字符后长度始终为7（美国电话号码只有7位）。
//输出描述 :对应每一组输入，按照字典顺序输出不重复的标准数字形式电话号码，即“xxx-xxxx”形式。
//          每个电话号码占一行，每组数据之后输出一个空行作为间隔符。
//输入
//12
//4873279
//ITS-EASY
//888-4567
//3-10-10-10
//888-GLOP
//TUT-GLOP
//967-11-11
//310-GINO
//F101010
//888-1200
//-4-8-7-3-2-7-9-
//487-3279
//4
//UTT-HELP
//TUT-GLOP
//310-GINO
//000-1213
//输出
//310-1010
//310-4466
//487-3279
//888-1200
//888-4567
//967-1111
//
//000-1213
//310-4466
//888-4357
//888-4567

#include <iostream>
#include <string>
#include <set>
using namespace std;
//  1   2   3
//     ABC DEF
//  4   5   6
// GHI JKL MNO
//  7   8   9
//PQRS TUV WXYZ

int main()
{
	int n = 0;
	string s = "22233344455566677778889999";
	while (cin >> n)
	{
		set<string> st;

		for (int i = 0; i < n; i++)
		{
			string str;
			string tmp;
			int count = 0;
			cin >> str;
			for (size_t j = 0; j < str.size(); j++)
			{
				if (str[j] >= 'A'&&str[j] <= 'Z')
				{
					tmp += s[str[j] - 'A'];
					count++;
					if (count == 3)
						tmp += '-';
				}
				else if (str[j] >= '0'&&str[j] <= '9')
				{
					tmp += str[j];
					count++;
					if (count == 3)
						tmp += '-';
				}
			}
			st.insert(tmp);
		}
		for (auto it : st)
			cout << it << endl;
		cout << endl;
	}

	return 0;
}