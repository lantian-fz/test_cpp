#define _CRT_SECURE_NO_WARNINGS 1
//剑指offer-两个链表的第一个公共结点
//输入两个链表，找出它们的第一个公共结点。（注意因为传入数据是链表，
//所以错误测试数据的提示是用其他方式显示的，保证传入数据是正确的）

#include <iostream>
using namespace std;

struct ListNode 
{
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};

//先计算出长度，长的一方将长的那一部分走完后，两个链表一起走
ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) 
{
	int len1 = 0, len2 = 0;
	ListNode* ph1 = pHead1;
	ListNode* ph2 = pHead2;
	while (ph1) len1++, ph1 = ph1->next;
	while (ph2) len2++, ph2 = ph2->next;
	ph1 = pHead1;
	ph2 = pHead2;
	if (len1>len2)
	{
		for (int i = 0; i<len1 - len2; i++)
			ph1 = ph1->next;
	}
	else if (len2>len1)
	{
		for (int i = 0; i<len2 - len1; i++)
			ph2 = ph2->next;
	}
	while (ph1)
	{
		if (ph1 == ph2)
			return ph1;
		ph1 = ph1->next;
		ph2 = ph2->next;
	}
	return NULL;
}
void main()
{
	ListNode* h1 = new ListNode(1);
	h1->next = new ListNode(2);
	h1->next->next = new ListNode(3);
	h1->next->next->next = new ListNode(6);
	h1->next->next->next->next = new ListNode(7);

	ListNode* h2 = new ListNode(4);
	h2->next = new ListNode(5);
	h2->next->next = h1->next->next->next;
	h2->next->next->next = h1->next->next->next->next;

	ListNode* h3 = FindFirstCommonNode(h1, h2);

}