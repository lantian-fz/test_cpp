#define _CRT_SECURE_NO_WARNINGS 1
//����-2.�������
//�������� �ǿ� ������������ʾ�����Ǹ������������У����Ǹ��Ե�λ���ǰ��� ���� �ķ�ʽ�洢�ģ�
//�������ǵ�ÿ���ڵ�ֻ�ܴ洢һλ���֡���������ǽ��������������������᷵��һ���µ���������ʾ���ǵĺ͡�
//�����Լ���������� 0 ֮�⣬���������������� 0 ��ͷ��
//ʾ����
//���룺(2 -> 4 -> 3) + (5 -> 6 -> 4)
//�����7 -> 0 -> 8
//ԭ��342 + 465 = 807

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