#define _CRT_SECURE_NO_WARNINGS 1
//��������
//NowCoder����һ����͵꣬��ҵ�Ŀ��˶��и���ֵ��ã�����ֻҪ����ҵ�Թ�һ����ͣ��ͻ�ÿ�춼������
//���ң�����������ҵ����������ͺ󣬽�����ÿ�춼���һλ������һ����Ʒ����
//���ǣ���ҵ�Ŀ��˴����һ���˷�չ�ɺƺƵ����ɰ���ǧ�ˣ�1��1��2��3��5����
//���ڣ�NowCoder�������æͳ��һ�£�ĳһ��ʱ�䷶Χ�����ܹ��������ٷ���ͣ�����ÿλ����ֻ��һ����ͣ���
//�������� :�������ݰ������顣
//          ÿ�����ݰ�����������from��to(1��from��to��80)���ֱ������ĵ�from��͵�to�졣
//������� :��Ӧÿһ�����룬�����from��to��Щ�������from��to���죩����Ҫ�����ٷ���͡�

#include <iostream>
using namespace std;

long long fun(int from, int to)
{
	long long arr[81] = { 0 };
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i < 81; i++)
		arr[i] = arr[i - 1] + arr[i - 2];
	long long ret = 0;
	for (int i = from-1; i < to; i++)
		ret += arr[i];
	return ret;
}

int main()
{
	int from = 0, to = 0;
	while (cin >> from >> to)
		cout << fun(from, to) << endl;
	return 0;
}