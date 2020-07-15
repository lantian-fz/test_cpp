#define _CRT_SECURE_NO_WARNINGS 1
//力扣-删除链表的节点-剑指offer
//给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
//返回删除后的链表的头节点。
//输入: head = [4,5,1,9], val = 5
//输出: [4,1,9]
//解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
//
//输入: head = [4,5,1,9], val = 1
//输出: [4,5,9]
//解释: 给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.

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

//双指针
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

//单指针
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