#define _CRT_SECURE_NO_WARNINGS 1
//�����ǹ�
//A, B, C�������Ǻ�����, ÿ�������ﶼ��һЩ�ǹ�, ���ǲ�֪������ÿ�������Ͼ����ж��ٸ��ǹ�, ��������֪�����µ���Ϣ��
//A - B, B - C, A + B, B + C.���ĸ���ֵ.ÿ����ĸ����ÿ������ӵ�е��ǹ���.
//������Ҫͨ�����ĸ���ֵ�����ÿ���������ж��ٸ��ǹ�, ��A, B, C�����ﱣ֤���ֻ��һ������A, B, C������������������
//�������� :����Ϊһ�У�һ��4���������ֱ�ΪA - B��B - C��A + B��B + C���ÿո������ ��Χ���� - 30��30֮��(������)��
//������� :���Ϊһ�У�����������������A��B��C��˳�����A��B��C���ÿո��������ĩ�޿ո� �������������������A��B��C�������No
//����: 1 - 2 3 4
//���:2 1 3
#include <iostream>
#include <vector>
using namespace std;

vector<int> ABCMeet(vector<int> &arr)
{
	vector<int> s;
	//s.resize(3);

	if ((arr[0] + arr[1] + arr[2] + arr[3] + 120) % 2 == 1)
		return s;

	s.resize(3);//�˲�����Ҫ����ǰ��ͻ���bug

	s[0] = (arr[0] + arr[2]) / 2;
	s[1] = (arr[1] + arr[3]) / 2;
	s[2] = arr[3] - s[1];

	if (s[0] - s[1] == arr[0] && s[1] - s[2] == arr[1] && s[0] + s[1] == arr[2] && s[1] + s[2] == arr[3])
		return s;
	s.resize(0);

	return s;
}

int main()
{
	vector<int> arr;
	for (int i = 0; i < 4; i++)
	{
		int tmp = 0;
		cin >> tmp;
		if (tmp<-30 || tmp>30)
		{
			cout << "No" << endl;
			return 0;
		}
		arr.push_back(tmp);
	}
	vector<int> abc = ABCMeet(arr);
	if (abc.size()==0)
		cout << "No" << endl;
	else
	{
		for (int i = 0; i < 3; i++)
		{
			if (i < 2)
				cout << abc[i] << " ";
			else
				cout << abc[i];
		}
		cout << endl;
	}
	return 0;
}