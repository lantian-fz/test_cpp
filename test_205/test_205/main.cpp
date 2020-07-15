#define _CRT_SECURE_NO_WARNINGS 1
//����-ɾ������Ľڵ�-��ָoffer
//�������������ͷָ���һ��Ҫɾ���Ľڵ��ֵ������һ������ɾ���ýڵ㡣
//����ɾ����������ͷ�ڵ㡣
//����: head = [4,5,1,9], val = 5
//���: [4,1,9]
//����: ������������ֵΪ 5 �ĵڶ����ڵ㣬��ô�ڵ�������ĺ���֮�󣬸�����Ӧ��Ϊ 4 -> 1 -> 9.
//
//����: head = [4,5,1,9], val = 1
//���: [4,5,9]
//����: ������������ֵΪ 1 �ĵ������ڵ㣬��ô�ڵ�������ĺ���֮�󣬸�����Ӧ��Ϊ 4 -> 5 -> 9.

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

//˫ָ��
ListNode* deleteNode_1(ListNode* head, int val)
{
	if (head->val == val)
		return head->next;
	ListNode* p1 = head;
	ListNode* p2 = head->next;
	while (p2)
	{
		if (p2->val == val)
		{
			p1->next = p2->next;
			p2 = nullptr;
			break;
		}
		p1 = p2;
		p2 = p2->next;
	}
	return head;
}

//��ָ��
ListNode* deleteNode_2(ListNode* head, int val)
{
	if (head->val == val)
		return head->next;
	ListNode* p = head;
	while (p->next)
	{
		if (p->next->val == val)
		{
			p->next = p->next->next;
			break;
		}
		p = p->next;
	}
	return head;
}

void main()
{
	ListNode *head = NULL;
	Insert(head, 4);
	Insert(head, 4);
	Insert(head, 5);
	Insert(head, 1);
	Insert(head, 9);

	ListNode* q = deleteNode_2(head,4);

	while (q != NULL)
	{
		cout << q->val << "->";
		q = q->next;
	}
	cout << "NULL" << endl;
	Clear(head);
}