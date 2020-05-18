#define _CRT_SECURE_NO_WARNINGS 1
//����-876.������м���
//����һ������ͷ��� head �ķǿյ���������������м��㡣
//����������м��㣬�򷵻صڶ����м��㡣
//ʾ�� 1��
//���룺[1, 2, 3, 4, 5]
//��������б��еĽ�� 3 (���л���ʽ��[3, 4, 5])
//���صĽ��ֵΪ 3 ��(����ϵͳ�Ըý�����л�������[3, 4, 5])��
//ע�⣬���Ƿ�����һ�� ListNode ���͵Ķ��� ans��������
//ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, �Լ� ans.next.next.next = NULL.
//
//ʾ�� 2��
//���룺[1, 2, 3, 4, 5, 6]
//��������б��еĽ�� 4 (���л���ʽ��[4, 5, 6])
//���ڸ��б��������м��㣬ֵ�ֱ�Ϊ 3 �� 4�����Ƿ��صڶ�����㡣

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

ListNode* middleNode(ListNode* head) //����ָ�뷨
{
	ListNode* p = head;
	ListNode* q = head;
	while (q != NULL&&q->next!=NULL)
	{
		p = p->next;
		q = q->next->next;
	}
	return p;
}
int main()
{
	ListNode *head = NULL;
	Insert(head, 1);
	Insert(head, 2);
	Insert(head, 3);
	Insert(head, 4);
	Insert(head, 5);
	Insert(head, 6);

	ListNode* q = middleNode(head);

	while (q != NULL)
	{
		cout << q->val << "->";
		q = q->next;
	}
	cout << "NULL" << endl;
	Clear(head);

	return 0;
}