#define _CRT_SECURE_NO_WARNINGS 1
//牛客 - 从尾到头打印链表
//输入一个链表，按链表从尾到头的顺序返回一个ArrayList。

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
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

vector<int> printListFromTailToHead_1(ListNode* head)
{
	vector<int> arr;
	ListNode *p = head;
	while (p)
	{
		arr.push_back(p->val);
		p = p->next;
	}
	reverse(arr.begin(), arr.end());
	return arr;
}

void printListFromTailToHead_2(ListNode* head)
{
	stack<ListNode*> sk;
	ListNode* p = head;
	while (p)
	{
		sk.push(p);
		p = p->next;
	}
	while (!sk.empty())
	{
		p = sk.top();
		cout << p->val << " ";
		sk.pop();
	}
}

void printListFromTailToHead_3(ListNode* head)
{
	if (head)
	{
		if (head->next)
			printListFromTailToHead_3(head->next);
		cout << head->val << " ";
	}
}

void main()
{
	ListNode* head = nullptr;
	Insert(head, 2);
	Insert(head, 3);
	Insert(head, 4);
	Insert(head, 5);
	printListFromTailToHead_3(head);
}