#define _CRT_SECURE_NO_WARNINGS 1
//����-62.��ͬ·��
//һ��������λ��һ�� m x n ��������Ͻ� ����ʼ������ͼ�б��Ϊ��Start�� ����
//������ÿ��ֻ�����»��������ƶ�һ������������ͼ�ﵽ��������½ǣ�����ͼ�б��Ϊ��Finish������
//���ܹ��ж�������ͬ��·����
//ʾ�� 1:
//����: m = 3, n = 2
//���: 3
//����:
//�����Ͻǿ�ʼ���ܹ��� 3 ��·�����Ե������½ǡ�
//1. ���� -> ���� -> ����
//2. ���� -> ���� -> ����
//3. ���� -> ���� -> ����
//
//ʾ�� 2:
//����: m = 7, n = 3
//���: 28

#include <iostream>
#include <vector>
using namespace std;

int uniquePaths(int m, int n) 
{
	if (m <= 0 || n <= 0)
		return 0;
	vector<vector<int>> dp(m, vector<int>(n,0));

	//ֻ��һ�л�ֻ�п�һ��ʱֻ��һ��·��
	for (int i = 0; i < m; i++)
		dp[i][0] = 1;
	for (int i = 0; i < n; i++)
		dp[0][i] = 1;

	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
	}
	return dp[m - 1][n - 1];
}

int main()
{
	int m = 0, n = 0;
	while (cin >> m >> n)
		cout << uniquePaths(m, n) << endl;


	return 0;
}


//#include <iostream>
//#include <string>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//struct A{
//	long a1;
//	short a2;
//	int a3;
//	double *a4;
//};
//
//int main()
//{
//	cout << sizeof(A) << endl;
//	return 0;
//}

//int Palindrome(string &a, string &b)
//{
//	int ret = 0;
//	for (size_t i = 0; i <= a.size(); i++)
//	{
//		string tmp = a;
//		tmp.insert(i, b);
//		string re = tmp;
//		reverse(re.begin(), re.end());
//		if (strcmp(tmp.c_str(), re.c_str()) == 0)
//			ret++;
//	}
//
//	return ret;
//}
//
//int main()
//{
//	string a;
//	string b;
//	//cin >> a >> b;
//	getline(cin, a);
//	getline(cin, b);
//
//	cout << Palindrome(a, b) << endl;
//
//	return 0;
//}

//class B0//����BO����
//{
//public://�ⲿ�ӿ�
//	virtual void display()//���Ա����
//	{
//		cout << "B0::display0" << endl;
//	}
//};
//class B1 :public B0//��������
//{
//public:
//	void display() { cout << "B1::display0" << endl; }
//};
//class D1 : public B1//��������
//{
//public:
//	void display(){ cout << "D1::display0" << endl; }
//};
//void fun(B0 ptr)//��ͨ����
//{
//	ptr.display();
//}
//int main()//������
//{
//	B0 b0;//������������ָ��
//	B1 b1;//�������������
//	D1 d1;//�������������
//	fun(b0);//���û���B0������Ա
//	fun(b1);//����������B1������Ա
//	fun(d1);//����������D1������Ա
//
//	return 0;
//}

//int main()
//{
//	int a; float b, c;
//	scanf("%3d%3f%4f", &a, &b, &c);
//	printf("\na=%d,b=%d,c=%f\n", a, b, c);
//
//	return 0;
//}
