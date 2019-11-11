#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class Goods
{
public:
	Goods()
	{
		weight = 0;
		next = NULL;
		cout << "������һ������Ϊ " << weight << " �Ļ���" << endl;
	}

	Goods(int w)
	{
		weight = w;
		next = NULL;
		total_w += w;
		cout << "������һ������Ϊ " << weight << " �Ļ���" << endl;
	}

	~Goods()
	{
		cout << "ɾ����һ������Ϊ " << weight << " �Ļ���" << endl;
		total_w -= weight;
	}

public:
	Goods *next;

public:
	static int getT()
	{
		return total_w;
	}

private:
	int weight;
	static int total_w;//������
};

int Goods::total_w = 0;

void buy(Goods * &head, int w)
{
	Goods *g1 = new Goods(w);
	if (head == NULL)
	{
		head = g1;
	}
	else
	{
		g1->next = head;
		head = g1;
	}
}

void sale(Goods * &head)
{
	if (head == NULL)
	{
		cout << "�ֿ��ѿ�" << endl;
	}
	else
	{
		Goods *tmp = head;
		head = head->next;

		delete tmp;
	}
}

int main()
{
	int input = 0;
	Goods *head = NULL;
	int w = 0;

	do
	{
		cout << "1.����" << endl;
		cout << "2.����" << endl;
		cout << "0.�˳�" << endl;
		cout << "��ѡ��";
		cin >> input;

		switch (input)
		{
		case 1:
			cout << "�������������: ";
			cin >> w;
			buy(head, w);
			break;
		case 2:
			sale(head);

			break;
		case 0:
			break;
		default:
			cout << "û�����ѡ��" << endl;
			break;
		}
		cout << "��ǰ���������� = " << Goods::getT() << endl;
	} while (input);

	return 0;
}