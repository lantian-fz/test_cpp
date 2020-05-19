#define _CRT_SECURE_NO_WARNINGS 1
//ţ��-����Ļ��Ľṹ
//����һ�����������һ��ʱ�临�Ӷ�ΪO(n), ����ռ临�Ӷ�ΪO(1)���㷨���ж����Ƿ�Ϊ���Ľṹ��
//����һ�������ͷָ��A���뷵��һ��boolֵ���������Ƿ�Ϊ���Ľṹ����֤������С�ڵ���900��
//����������1->2->2->1     ���أ�true

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

//�����ȷ�ת�������ж����������ֵ�Ƿ���ȣ����ռ临�ӶȲ�����Ҫ��
bool chkPalindrome(ListNode* A) 
{
	//�ÿ���ָ���ҵ������м��㣬��ת��벿�֣����ж������ֽ��ֵ�Ƿ����
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
	while (p)//��ת��벿������
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