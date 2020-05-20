#define _CRT_SECURE_NO_WARNINGS 1
//����-141.��������
//����һ�������ж��������Ƿ��л���
//Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ���� 
//��� pos �� -1�����ڸ�������û�л���
//ʾ�� 1��
//���룺head = [3, 2, 0, -4], pos = 1      �����true
//���ͣ���������һ��������β�����ӵ��ڶ����ڵ㡣
//
//ʾ�� 2��
//���룺head = [1, 2], pos = 0             �����true
//���ͣ���������һ��������β�����ӵ���һ���ڵ㡣
//
//ʾ�� 3��
//���룺head = [1], pos = -1               �����false
//���ͣ�������û�л���

#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void Insert(ListNode *&head, const int x)
{
	if (head == NULL)
		head = new ListNode(x);
	else
		Insert(head->next, x);
}

void Clear(ListNode *&head)
{
	while (head != NULL)
	{
		ListNode* r = head;
		head = r->next;
		delete r;
		r = NULL;
	}
}

bool hasCycle_1(ListNode *head) //����ָ�뷨
{
	if (head == nullptr)
		return false;
	ListNode *p = head;
	ListNode *q = head;
	do
	{
		if (q==nullptr||q->next==nullptr)
			return false;
		p = p->next;
		q = q->next->next;
	}while (p != q);
	return true;
}

int main()
{
	ListNode *head = NULL;
	Insert(head, 1);
	Insert(head, 2);
	Insert(head, 3);
	Insert(head, 4);
	head->next->next->next->next = head->next->next;

	cout << hasCycle_1(head) << endl;
	//Clear(head);

	return 0;
}