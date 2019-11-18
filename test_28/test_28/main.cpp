#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
using namespace std;
class Furn
{
public:
	Furn()
	{
		this->m = "未知";
	}
	string m;
};
//在父亲类继承爷爷类的时候加virtual ，改为虚继承
//防止孙子类在继承父亲类时，对爷爷类的变量发生歧义
class Bed :virtual public Furn
{
public:

	void sleep()
	{
		cout << "床上睡觉" << endl;
	}

};

class Sofa :virtual public Furn
{
public:
	void sit()
	{
		cout << "沙发上休息" << endl;
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
	sb1.m;//没有报错，此时的m继承的爷爷类的m

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
//		this->m = "木质";
//	}
//	void sleep()
//	{
//		cout << "床上睡觉" << endl;
//	}
//
//	void furnitureBed()
//	{
//		cout << "床的材质为 " << this->m << endl;
//	}
//};
//
//class Sofa:public Furn
//{
//public:
//	Sofa()
//	{
//		this->m = "皮质";
//	}
//
//	void sit()
//	{
//		cout << "沙发上休息" << endl;
//	}
//
//	void furnitureSofa()
//	{
//		cout << "沙发的材质为 " << this->m << endl;
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
//	//s1.m;//m不明确，无法确定是哪个基类的m，应该用下面这种方法使用
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