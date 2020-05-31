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
	ListNode *p = nullptr;

	return p;
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
	Insert(head2, 54);

	Clear(head1);
	Clear(head2);

	return 0;
}