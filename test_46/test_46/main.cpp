#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <ctime>
#include <vector>
#include <deque>
#include <algorithm>
#include <string>
using namespace std;

//��ί��ְ�����sort�㷨����
//����5��ѡ�֣��������÷֣���10����ί��5��ѡ�ִ��
//�÷ֹ���ȥ����߷֣�ȥ����ͷ֣���ƽ����
//���÷ֶ�5��ѡ������

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

//����ѡ��
void Creation(vector<Person> &v)
{
	char str[] = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		Person p;
		p.name = "ѡ��";
		p.name += str[i];
		p.score = 0;
		v.push_back(p);
	}
}

//��ֲ�����ƽ����
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
		sort(s.begin(), s.end());//��������
		s.pop_back();//ȥ��һ����߷�
		s.pop_front();//ȥ��һ����ͷ�
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

//����ÿ��ѡ��ƽ��������
void Sort(vector<Person> &v)
{
	sort(v.begin(), v.end(),Compare);//��Ϊv�Ƕ������ͣ�Ӧ��������һ������
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
		cout << "��" << i + 1 << "��" << (*it).name << ",score = " << (*it).score << endl;
		i++;
	}
}