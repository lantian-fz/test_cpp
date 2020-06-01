#define _CRT_SECURE_NO_WARNINGS 1
//����-2.�������
//�������� �ǿ� ������������ʾ�����Ǹ������������У����Ǹ��Ե�λ���ǰ��� ���� �ķ�ʽ�洢�ģ�
//�������ǵ�ÿ���ڵ�ֻ�ܴ洢һλ���֡���������ǽ��������������������᷵��һ���µ���������ʾ���ǵĺ͡�
//�����Լ���������� 0 ֮�⣬���������������� 0 ��ͷ��
//ʾ����
//���룺(2 -> 4 -> 3) + (5 -> 6 -> 4)
//�����7 -> 0 -> 8
//ԭ��342 + 465 = 807

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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
	ListNode *p = new ListNode(-1);
	ListNode *q = p;
	int count = 0;
	while (l1&&l2)
	{
		int x = l1->val + l2->val + count;
		ListNode* s = new ListNode(x % 10);
		q->next = s;
		count = x / 10;
		l1 = l1->next;
		l2 = l2->next;
		q = q->next;
	}
	while (l1)
	{
		int x = l1->val + count;
		ListNode* s = new ListNode(x % 10);
		q->next = s;
		count = x / 10;
		l1 = l1->next;
		q = q->next;
	}

	while (l2)
	{
		int x = l2->val + count;
		ListNode* s = new ListNode(x % 10);
		q->next = s;
		count = x / 10;
		l2 = l2->next;
		q = q->next;
	}
	if (count != 0)
	{
		ListNode *s = new ListNode(count);
		q->next = s;
	}

	return p->next;
}

int main()
{
	ListNode *head1 = NULL;
	ListNode *head2 = NULL;
	Insert(head1, 2);
	Insert(head1, 4);
	Insert(head1, 3);

	Insert(head2, 5);
	Insert(head2, 6);
	Insert(head2, 4); 

	ListNode *q = addTwoNumbers(head1, head2);

	Clear(head1);
	Clear(head2);

	return 0;
}