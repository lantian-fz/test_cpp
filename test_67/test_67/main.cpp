#define _CRT_SECURE_NO_WARNINGS 1
//201301 JAVA ��Ŀ2 - 3��
//���дһ�����������������Ӻ�����������n x m�����̸��ӣ�nΪ����ĸ�������mΪ����ĸ�������
//���Ÿ��Ա�Ե�ߴ����Ͻ��ߵ����½ǣ��ܹ��ж������߷���Ҫ�����߻�ͷ·������ֻ�����Һ������ߣ���������������ߡ�
//�������� :��������������
//������� :���ؽ��
//����: 2
//      2
//���: 6
#include <iostream>
#include <vector>
using namespace std;

//��(m, n)��>(0, 0)�ͷ������ߣ�
//������һ����f(m, n - 1)��>(0, 0) ��������һ����f(m - 1, n)��>(0, 0)
//ע�⣺�����Ǵ������߽磬Ҳ����˵f(x, 0)����f(0, x)��ֻ��һ��ֱ·�����ˣ������x�Ǳ�������
//f(m, n) = f(m, n - 1) + f(m - 1, n)
int LeftRight(int n, int m)//�ݹ�
{
	if (n == 0 || m == 0)
		return 1;
	else
		return LeftRight(n - 1, m) + LeftRight(n, m - 1);
}

int main()
{
	int n, m;
	cin >> n >> m;

	cout << LeftRight(n, m) << endl;

	return 0;
}

//int main()//��ѧ����
//{
//	//����  A(m+n,m+1)/n!  ���߷�
//	int n, m;
//	while (cin >> n >> m)
//	{
//		int get = 1;
//		for (int i = n + m; i>n; i--)
//			get *= i;
//		for (int i = 2; i <= m; i++)
//			get /= i;
//		cout << get << endl;
//	}
//	return 0;
//}

//int main()//��̬�滮
//{
//	int m, n;
//	while (cin >> m >> n) {
//		vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
//		for (int i = 0; i <= n; i++) {
//			for (int j = 0; j <= m; j++) {
//				if (i == 0 && j == 0) {
//					dp[i][j] = 1;
//					continue;
//				}
//				if (i == 0) {    // �ϱ߽�
//					dp[i][j] = dp[i][j - 1];
//				}
//				else if (j == 0) {    // ��߽�
//					dp[i][j] = dp[i - 1][j];
//				}
//				else {
//					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//				}
//			}
//		}
//		cout << dp[n][m] << endl;
//	}
//
//	return 0;
//}