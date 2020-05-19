#define _CRT_SECURE_NO_WARNINGS 1
//牛客-链表的回文结构
//对于一个链表，请设计一个时间复杂度为O(n), 额外空间复杂度为O(1)的算法，判断其是否为回文结构。
//给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。
//测试样例：1->2->2->1     返回：true

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

//可以先反转链表，再判断两个链表的值是否相等，但空间复杂度不符合要求
bool chkPalindrome(ListNode* A) 
{
	//用快慢指针找到链表中间结点，反转后半部分，再判断两部分结点值是否相等
	if (A == nullptr)
		return false;
	if (A->next == nullptr)
		return true;
	ListNode *p = A;
	ListNode *q = A;
	while (q&&q->next)
	{
		p = p->next;
		q = q->next->next;
	}
	q = nullptr;
	while (p)//反转后半部分链表
	{
		ListNode *t = p->next;
		p->next = q;
		q = p;
		p = t;
	}
	p = A;
	while (q != nullptr&&p->val == q->val)
	{
		p = p->next;
		q = q->next;
	}
	if (q == nullptr)
		return true;
	return false;
}

int main()
{
	ListNode *head = NULL;
	Insert(head, 1);
	Insert(head, 2);
	Insert(head, 2);
	Insert(head, 1);


	cout << chkPalindrome(head) << endl;

	Clear(head);

	return 0;
}