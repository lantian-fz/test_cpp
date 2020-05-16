#define _CRT_SECURE_NO_WARNINGS 1
//����-206.��ת����
//��תһ��������
//���� : 1->2->3->4->5->NULL
//��� : 5->4->3->2->1->NULL

#include <iostream>
using namespace std;

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList_1(ListNode* head) //˫ָ��1
{
	ListNode *q = NULL;
	ListNode *p = head;
	while (p != NULL)
	{
		ListNode* t = p->next;
		p->next = q;
		q = p;
		p = t;
	}
	return q;
}

ListNode* reverseList_2(ListNode* head)//�ݹ�
{
	if (head == NULL || head->next == NULL)
		return head;
	ListNode* ret = reverseList_2(head->next);
	head->next->next = head;
	head->next = NULL;
	return ret;
}

ListNode* reverseList_3(ListNode* head)//˫ָ��2
{
	if (head == NULL)
		return head;
	ListNode* p = head;
	while (head->next != NULL)
	{
		ListNode* t = head->next->next;
		head->next->next = p;
		p = head->next;
		head->next = t;
	}
	return p;
}

int main()
{
	ListNode *head = new ListNode(1);
	ListNode *p = head;
	for (int i = 2; i <= 5; i++)
	{
		ListNode* s = new ListNode(i);
		p->next = s;
		p = p->next;
	}

	ListNode *q = reverseList_3(head);

	while (q != NULL)
	{
		cout << q->val << "->";
		q = q->next;
	}
	cout << "NULL" << endl;
	return 0;
}