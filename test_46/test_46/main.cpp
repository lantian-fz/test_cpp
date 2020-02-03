#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <ctime>
#include <vector>
#include <deque>
#include <algorithm>
#include <string>
using namespace std;

//评委打分案例（sort算法排序）
//创建5个选手（姓名，得分），10个评委对5个选手打分
//得分规则，去掉最高分，去掉最低分，求平均分
//按得分对5个选手排名

class Person
{
public:
	Person()
	{}
	Person(string name, int score) :name(name), score(score)
	{}
public:
	string name;
	int score;
};

//创建选手
void Creation(vector<Person> &v)
{
	char str[] = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		Person p;
		p.name = "选手";
		p.name += str[i];
		p.score = 0;
		v.push_back(p);
	}
}

//打分并计算平均分
void AvgScore(vector<Person> &v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		deque<int> s;
		for (int i = 0; i < 10; i++)
		{
			int sc = rand() % 40 + 60;
			s.push_back(sc);
		}
		sort(s.begin(), s.end());//升序排列
		s.pop_back();//去掉一个最高分
		s.pop_front();//去掉一个最低分
		int avg = 0;
		for (deque<int>::iterator its = s.begin(); its != s.end();its++)
		{
			avg += (*its);
		}
		(*it).score = avg / s.size();
	}
}

bool Compare(Person &p1, Person &p2)
{
	return p1.score > p2.score;
}

//根据每个选手平均分排名
void Sort(vector<Person> &v)
{
	sort(v.begin(), v.end(),Compare);//因为v是对象类型，应该再设置一个函数
}

void main()
{
	srand((unsigned int)time(NULL));
	vector<Person> p;
	Creation(p);
	AvgScore(p);
	Sort(p);
	int i = 0;
	for (vector<Person>::iterator it = p.begin(); it != p.end(); it++)
	{
		cout << "第" << i + 1 << "名" << (*it).name << ",score = " << (*it).score << endl;
		i++;
	}
}