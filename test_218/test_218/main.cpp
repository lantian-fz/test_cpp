#define _CRT_SECURE_NO_WARNINGS 1
//��ָoffer-�ַ���������
//����һ���ַ���, ���ֵ����ӡ�����ַ������ַ����������С����������ַ���abc, 
//���ֵ����ӡ�����ַ�a, b, c�������г����������ַ���abc, acb, bac, bca, cab��cba��
//����һ���ַ���, ���Ȳ�����9(�������ַ��ظ�), �ַ�ֻ������Сд��ĸ��

#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

void swap(char& a, char& b)
{
	char tmp = a;
	a = b;
	b = tmp;
}

void Permutation(string str, set<string>& st, int begin)
{
	if (begin == str.size() - 1)
		st.insert(str);
	else
	{
		for (int i = begin; i < str.size(); i++)
		{
			swap(str[begin], str[i]);
			Permutation(str, st, begin + 1);
			swap(str[begin], str[i]);
		}
	}
}

vector<string> Permutation(string str) 
{
	set<string> st;
	vector<string> arr;
	if (str.empty())
		return arr;
	Permutation(str, st, 0);

	vector<string> s(st.begin(), st.end());
	return s;
}

void main()
{
	string s = "aabc";
	vector<string>& arr = Permutation(s);
	for (auto e : arr)
		cout << e << endl;
}

//// ר�Ŵ���int�ļӷ�����
//int Add(int left, int right){return left + right;}
//
//// ͨ�üӷ�����
//template<class T>
//T Add(T left, T right){return left + right;}
//
//void main()
//{
//	Add(1, 2); // ���ģ�庯��ƥ�䣬����������Ҫ�ػ�
//	cout<<Add<int>(1, 2)<<endl; // ���ñ������ػ���Add�汾
//}

//template<typename T>
//T Add(const T& a, const T& b){return a + b;}
//
//void main()
//{
//	int a1 = 1, a2 = 2;
//	double b1 = 10.0, b2 = 20.0;
//	Add(a1, a2);
//	Add(b1, b2);
//
//	//Add(a1, b1);//����ͨ�����룬���Ͳ�ͬ
//
//	//һ�ַ��������û�����ǿ��ת��
//	Add(a1, (int)b1);
//	
//	//��һ�ַ�������ʹ����ʾʵ����
//	Add<int>(a1, b1);
//}