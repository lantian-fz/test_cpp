#define _CRT_SECURE_NO_WARNINGS 1
//��ָoffer-��1+2+...+n
//Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A ? B : C����

#include <iostream>
using namespace std;

class temp
{
public:
	temp(){ x++; sum += x; }
	static void Reset(){ x = 0; sum = 0; }
	static size_t GetSum(){ return sum; }

private:
	static unsigned int x;
	static unsigned int sum;
};

unsigned int temp::x = 0;
unsigned int temp::sum = 0;

int Add(int n)
{
	int sum = n;
	//��sum=0ʱ��&&����Ĳ�����
	sum && (sum += Add(n - 1));
	return sum;
}

size_t Add_2(int n)
{
	temp::Reset();

	temp* a = new temp[n];
	delete[] a;
	a = nullptr;
	return temp::GetSum();
}

void main()
{
	int n = 0;
	while (cin >> n)
		cout << Add_2(n) << endl;
}