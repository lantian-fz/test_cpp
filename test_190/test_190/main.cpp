#define _CRT_SECURE_NO_WARNINGS 1
//力扣-2.两数相加
//给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，
//并且它们的每个节点只能存储一位数字。如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
//您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
//示例：
//输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
//输出：7 -> 0 -> 8
//原因：342 + 465 = 807

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