#define _CRT_SECURE_NO_WARNINGS 1
//����ָ��
#include <iostream>
using namespace std;

int func(int a, int b)
{
	cout << "func..." << endl;
	return 1;
}
//����һ
typedef int(fp1)(int, int);//�Ƽ�ʹ�÷���һ

//������
typedef int(*fp2)(int, int);

void main()
{
	fp1 *p1 = func;
	p1(1, 2);
	
	fp2 p2 = func;
	p2(2, 3);

	//������
	int(*p3)(int, int) = func;
	p3(4, 5);
}