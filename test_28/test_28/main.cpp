#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
using namespace std;
class Furn
{
public:
	Furn()
	{
		this->m = "δ֪";
	}
	string m;
};
//�ڸ�����̳�үү���ʱ���virtual ����Ϊ��̳�
//��ֹ�������ڼ̳и�����ʱ����үү��ı�����������
class Bed :virtual public Furn
{
public:

	void sleep()
	{
		cout << "����˯��" << endl;
	}

};

class Sofa :virtual public Furn
{
public:
	void sit()
	{
		cout << "ɳ������Ϣ" << endl;
	}

};

class SofaBed :public Bed, public Sofa
{
public:
	void sleep_sofa()
	{
		sleep();
		sit();
	}

};

int main()
{
	SofaBed sb1;
	sb1.m;//û�б�����ʱ��m�̳е�үү���m

	return 0;
}
//class Furn
//{
//public:
//	string m;
//};
//
//class Bed:public Furn
//{
//public:
//	Bed()
//	{
//		this->m = "ľ��";
//	}
//	void sleep()
//	{
//		cout << "����˯��" << endl;
//	}
//
//	void furnitureBed()
//	{
//		cout << "���Ĳ���Ϊ " << this->m << endl;
//	}
//};
//
//class Sofa:public Furn
//{
//public:
//	Sofa()
//	{
//		this->m = "Ƥ��";
//	}
//
//	void sit()
//	{
//		cout << "ɳ������Ϣ" << endl;
//	}
//
//	void furnitureSofa()
//	{
//		cout << "ɳ���Ĳ���Ϊ " << this->m << endl;
//	}
//};
//
//class SofaBed :public Bed, public Sofa
//{
//public:
//	void sleep_sofa()
//	{
//		sleep();
//		sit();
//	}
//};
//
//int main()
//{
//	SofaBed sb1;
//	sb1.sleep_sofa();
//	sb1.furnitureBed();
//	sb1.furnitureSofa();
//
//	//s1.m;//m����ȷ���޷�ȷ�����ĸ������m��Ӧ�����������ַ���ʹ��
//	sb1.Sofa::m = "lllll";
//	sb1.Bed::m = "2222";
//	sb1.furnitureBed();
//	sb1.furnitureSofa();
//
//	//b1.furnitureBed();
//	//s1.furnitureSofa();
//
//	return 0;
//}