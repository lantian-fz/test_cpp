#define _CRT_SECURE_NO_WARNINGS 1
//ţ��-����ָ�
//��д���룬�Ը���ֵxΪ��׼������ָ�������֣�����С��x�Ľ�����ڴ��ڻ����x�Ľ��֮ǰ
//����һ�������ͷָ�� ListNode* pHead���뷵���������к�������ͷָ�롣ע�⣺�ָ��Ժ󱣳�ԭ��������˳�򲻱䡣

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
	//���������������xֵ���֣���ɺ�������һ��
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
	pb->next = nullptr;//pb->next���ܲ�Ϊ�գ������������ڵ�
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