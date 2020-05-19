#define _CRT_SECURE_NO_WARNINGS 1
//牛客-链表分割
//编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前
//给定一个链表的头指针 ListNode* pHead，请返回重新排列后的链表的头指针。注意：分割以后保持原来的数据顺序不变。

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

ListNode* partition(ListNode* pHead, int x) 
{
	if (pHead == nullptr)
		return pHead;
	//定义两个链表根据x值划分，完成后连接在一起
	ListNode* small = new ListNode(-1);
	ListNode* big = new ListNode(-1);
	ListNode* ps = small, *pb = big, *p = pHead;
	while (p != nullptr)
	{
		if (p->val < x)
		{
			ps->next = p;
			ps = p;
		}
		else
		{
			pb->next = p;
			pb = p;
		}
		p = p->next;
	}
	pb->next = nullptr;//pb->next可能不为空，连接有其他节点
	ps->next = big->next;
	return small->next;
}

int main()
{
	ListNode *head = NULL;
	Insert(head, 4);
	Insert(head, 2);
	Insert(head, 6);
	Insert(head, 7);
	Insert(head, 1);
	Insert(head, 5);
	Insert(head, 9);

	ListNode* q = partition(head, 3);

	while (q != NULL)
	{
		cout << q->val << "->";
		q = q->next;
	}
	cout << "NULL" << endl;
	Clear(head);

	return 0;
}