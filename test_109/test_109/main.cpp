#define _CRT_SECURE_NO_WARNINGS 1
//���ѵ�����
//NowCoder�����ڳ���Σ�պ���ı�������Ϊ�����棬���״η��������룬���ھ��ӵ���Ϣ���ݡ�
//�������Ǿ����е�һ�����٣���Ҫ�ѷ���������Ϣ������������ṩ����Ľ�����
//��Ϣ���ܵİ취�ǣ�����Ϣԭ���е�ÿ����ĸ���ֱ��ø���ĸ֮��ĵ�5����ĸ�滻�����磺��Ϣԭ���е�ÿ����ĸA���ֱ��滻����ĸF����
//�����ַ����䣬������Ϣԭ�ĵ�������ĸ���Ǵ�д�ġ������е���ĸ��ԭ���е���ĸ��Ӧ��ϵ���¡�
//������ĸ��A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
//ԭ����ĸ��V W X Y Z A B C D E F G H I J K L M N O P Q R S T U
//�������� :��������������ݣ�ÿ������һ�У�Ϊ�յ������ġ����Ľ��пո�ʹ�д��ĸ��ɡ�
//������� :��Ӧÿһ�����ݣ�������ܺ�����ġ�
//����: HELLO WORLD
//      SNHJ
//���: CZGGJ RJMGY
//      NICE

#include <iostream>
#include <string>
using namespace std;

void NowCoder(string &s)
{
	string str;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'F'&&s[i] <= 'Z')
			str.push_back(s[i] - 5);
		else if (s[i] >= 'A'&&s[i] <= 'E')
			str.push_back(s[i] + 21);
		else
			str.push_back(s[i]);
	}
	cout << str << endl;
}

int main()
{
	string s;
	while (getline(cin, s))
		NowCoder(s);

	return 0;
}