#define _CRT_SECURE_NO_WARNINGS 1
//密码强度等级
//密码按如下规则进行计分，并根据不同的得分为密码进行安全等级划分。
//一、密码长度: 5 分: 小于等于4 个字符    10 分: 5 到7 字符                25 分: 大于等于8 个字符
//二、字母:     0 分: 没有字母            10 分: 全都是小（大）写字母      20 分: 大小写混合字母
//三、数字:     0 分: 没有数字            10 分: 1 个数字                  20 分: 大于1 个数字
//四、符号:     0 分: 没有符号            10 分: 1 个符号                  25 分: 大于1 个符号
//五、奖励:     2 分: 字母和数字          3 分: 字母、数字和符号           5 分: 大小写字母、数字和符号
//最后的评分标准:>= 90: 非常安全          >= 80: 安全（Secure）            >= 70: 非常强         >= 60: 强（Strong）
//               >= 50: 一般（Average）   >= 25: 弱（Weak）                >= 0:  非常弱
//对应输出为：VERY_WEAK, WEAK, AVERAGE,  STRONG, VERY_STRONG, SECURE, VERY_SECURE 
//请根据输入的密码字符串，进行安全评定。
//注：字母：a-z, A-Z    数字：-9
//符号包含如下： (ASCII码表可以在UltraEdit的菜单view->ASCII Table查看)
//               !"#$%&'()*+,-./     (ASCII码：x21~0x2F)
//               :;<=>?@             (ASCII<=><=><=><=><=>码：x3A~0x40)
//               [\]^_`              (ASCII码：x5B~0x60)
//               {|}~                (ASCII码：x7B~0x7E)

//输入描述:输入一个string的密码
//输出描述:输出密码等级
//输入: 38$@NoNoNo
//输出: VERY_SECURE
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int Evaluate(string &password)
{
	int score = 0;

	//一、密码长度:
	if (password.size() <= 4)
		score += 5;
	else if (password.size() <= 7)
		score += 10;
	else
		score += 25;
	//二、字母:三、数字: 四、符号:
	int majuscule = 0;//大写字母 
	int small_letter = 0;//小写字母
	int num = 0;//数字
	int symbol = 0;//符号
	for (size_t i = 0; i < password.size(); i++)
	{
		if (password[i] >= '0'&&password[i] <= '9')
			num++;
		else if (password[i] >= 'A'&&password[i] <= 'Z')
			majuscule++;
		else if (password[i] >= 'a'&&password[i] <= 'z')
			small_letter++;
		else
			symbol++;
	}
	if (majuscule != 0 && small_letter != 0)//字母分
		score += 20;
	else if (majuscule > 0 || small_letter > 0)
		score += 10;

	if (num > 1)//数字分
		score += 20;
	else if (num == 1)
		score += 10;

	if (symbol > 1)//符号分
		score += 25;
	else if (symbol == 1)
		score += 10;

	if (majuscule != 0 && small_letter != 0 && num != 0 && symbol != 0)//奖励分
		score += 5;
	else if ((majuscule != 0 || small_letter != 0) && num != 0 && symbol != 0)
		score += 3;
	else if ((majuscule != 0 || small_letter != 0) && num != 0)
		score += 2;

	if (score >= 60)
	{
		if (score >= 80)
		{
			if (score >= 90)
				return 6;
			else
				return 5;
		}
		else
		{
			if (score >= 70)
				return 4;
			else
				return 3;
		}
	}
	else
	{
		if (score >= 25)
		{
			if (score >= 50)
				return 2;
			else
				return 1;
		}
		else
			return 0;
	}
}

int main()
{
	//密码强度：弱->强  0->6级
	vector<string> cla = { "VERY_WEAK", "WEAK", "AVERAGE", "STRONG", "VERY_STRONG", "SECURE", "VERY_SECURE" };
	string password;

	while (cin >> password)
	{
		cout << cla[Evaluate(password)] << endl;
	}

	return 0;
}