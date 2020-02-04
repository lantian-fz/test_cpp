#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Compare
{
public:
	bool operator()(int v1, int v2)//重载
	{
		return v1 > v2;
	}
};

void test1()
{
	set<int,Compare> s;//默认为升序
	s.insert(4);
	s.insert(6);
	s.insert(1);
	s.insert(9);
	s.insert(3);

	set<int>::iterator it = s.begin();
	for (; it != s.end(); it++)
		cout << (*it) << " ";
	cout << endl;
}

class Parson
{
public:
	Parson(int id, int age) :id(id), age(age)
	{
	}

public:
	int id;
	int age;
};

class Compare2
{
public:
	bool operator()(Parson p1, Parson p2)
	{
		return p1.age < p2.age;
	}
};

void test2()
{
	set<Parson, Compare2> s;
	Parson p1(1, 2);
	Parson p2(3, 4);
	Parson p3(5, 6);
	Parson p4(7, 8);
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);

	set<Parson, Compare2>::iterator it = s.begin();
	for (; it != s.end(); it++)
		cout << (*it).age << " ";
	cout << endl;

	Parson p5(1, 4);

	set<Parson, Compare2>::iterator it2 = s.find(p5);//find查找时根据所写仿函数里面的值进行排序，比如这里与id无关
	if (it2 == s.end())
		cout << "没有找到" << endl;
	else
		cout << (*it2).id << " " << (*it2).age << endl;
}

void reverse(vector<int>& nums,int begin,int end)
{
	while (begin < end)
	{
		int tem = nums[begin];
		nums[begin++] = nums[end];
		nums[end--] = tem;
	}
}

void rotate(vector<int>& nums, int k)
{
	k %= nums.size();
	reverse(nums, 0, nums.size() - 1);//先反转所有元素 7 6 5 4 3 2 1
	reverse(nums, 0, k - 1);//再反转前k个元素 5 6 7 4 3 2 1
	reverse(nums, k, nums.size() - 1);//再反转后size-k个元素 5 6 7 1 2 3 4
}

void test3()
{
	int i = 0, a = 0;
	while (i<20)
	{
		for (;;)
		{
			if ((i % 10) == 0) break;
			else i--;
		} 
		i += 11; 
		a += i;
	}
	cout << a << endl;
}

void test4()
{
	cout << sizeof(float) << endl;
}

void main()
{
	//test1();
	//test2();
	//test3();
	//vector<int> p;
	//for (int i = 0; i < 7; i++)
	//	p.push_back(i + 1);
	//rotate(p,3);
	test4();
}