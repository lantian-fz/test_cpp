#define _CRT_SECURE_NO_WARNINGS 1
//Emacs������
//Emacs�ų���ı༭�������Դ���һ������������������������ͬ�����ǻ��ں�׺���ʽ�ģ���������ڲ������ĺ��档
//���硰2 3 + ���ȼ�����׺���ʽ�ġ�2 + 3��������ʵ��һ����׺���ʽ�ļ�������
//�������� :��������������ݡ�ÿ�����ݰ������У���һ����һ��������n(3��n��50)�������ŵڶ��а���n������ֵ���������ɵ��б�
//         �� + -*/ ���ֱ�Ϊ�Ӽ��˳��������㣬���г���Ϊ����������5 / 3 = 1����
//������� :��Ӧÿһ�����ݣ�������ǵ���������
//����
//3
//2 3 +
//5
//2 2 + 3 *
//5
//2 2 3 + *
//���
//5
//12
//10

//���ӣ�https://www.nowcoder.com/questionTerminal/1a92fbc771a54feb9eb5bd9b3ff2d0a9
//��Դ��ţ����

#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
	stack<int> s1;
	int n;
	while (cin >> n)
	{
		for (int i = 0; i<n; i++){
			string s;
			cin >> s;
			if (s[0] >= '0'&&s[0] <= '9'){
				int num = 0;
				for (int i = 0; i<s.length(); i++)
					num = num * 10 + s[i] - '0';
				s1.push(num);
			}
			else{
				int x = s1.top(); s1.pop();
				int y = s1.top(); s1.pop();
				if (s == "+")       s1.push(x + y);
				else if (s == "-")  s1.push(y - x);
				else if (s == "*")  s1.push(x*y);
				else if (s == "/")  s1.push(y / x);
			}
		}
		cout << s1.top() << endl;
	}
	return 0;
}
