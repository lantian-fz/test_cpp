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
		cout << "创建了一个重量为 " << weight << " 的货物" << endl;
	}

	Goods(int w)
	{
		weight = w;
		next = NULL;
		total_w += w;
		cout << "创建了一个重量为 " << weight << " 的货物" << endl;
	}

	~Goods()
	{
		cout << "删除了一个重量为 " << weight << " 的货物" << endl;
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
	static int total_w;//总重量
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
		cout << "仓库已空" << endl;
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
		cout << "1.进货" << endl;
		cout << "2.出货" << endl;
		cout << "0.退出" << endl;
		cout << "请选择：";
		cin >> input;

		switch (input)
		{
		case 1:
			cout << "请输入货物重量: ";
			cin >> w;
			buy(head, w);
			break;
		case 2:
			sale(head);

			break;
		case 0:
			break;
		default:
			cout << "没有这个选项" << endl;
			break;
		}
		cout << "当前货物总重量 = " << Goods::getT() << endl;
	} while (input);

	return 0;
}