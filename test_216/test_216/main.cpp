#define _CRT_SECURE_NO_WARNINGS 1
//��ָoffer-��������ĸ���
//���ӣ�https ://www.nowcoder.com/questionTerminal/f836b2c43afc4b35ad6adc41ec941dba
//��Դ��ţ����
//
//����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬��һ��
//����ָ��randomָ��һ������ڵ㣩����Դ������������������ؿ������ͷ��㡣
//��ע�⣬���������벻Ҫ���ز����еĽڵ����ã�������������ֱ�ӷ��ؿգ�

#include <iostream>
using namespace std;

struct RandomListNode 
{
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :label(x), next(NULL), random(NULL) {}
};

//����ԭ����Ľ�㣬�������Ƴ��Ľ������ԭ������
//��2->3->4->null����Ϊ��2->2->3->3->4->4->null
void CloneNodes(RandomListNode* head)
{
	RandomListNode* phead = head;
	while (phead)
	{
		RandomListNode* clone = new RandomListNode(phead->label);
		clone->next = phead->next;
		
		phead->next = clone;
		phead = clone->next;
	}
}

//����ԭ�����randomָ��
void CloneRandom(RandomListNode* head)
{
	RandomListNode* p = head;
	while (p)
	{
		RandomListNode* clone = p->next;
		if (p->random != nullptr)
			clone->random = p->random->next;
		p = clone->next;
	}
}

//��������õ����Ƶ�����
RandomListNode* RandomNode(RandomListNode* head)
{
	RandomListNode* pNode = head;
	RandomListNode* cloneHead = nullptr;
	RandomListNode* cloneNode = nullptr;

	if (pNode)
	{
		cloneHead = pNode->next;//���������ͷ���
		cloneNode = pNode->next;
		pNode->next = cloneNode->next;
		pNode = pNode->next;
	}
	//�õ���������
	while (pNode)
	{
		cloneNode->next = pNode->next;
		cloneNode = cloneNode->next;

		pNode->next = cloneNode->next;
		pNode = pNode->next;
	}
	return cloneHead;
}

RandomListNode* Clone(RandomListNode* pHead)
{
	if (pHead == nullptr)
		return nullptr;
	CloneNodes(pHead);
	CloneRandom(pHead);
	return RandomNode(pHead);
}

void main()
{
	RandomListNode* head = new RandomListNode(1);
	head->next = new RandomListNode(2);
	head->next->next = new RandomListNode(3);
	head->next->next->next = new RandomListNode(4);
	head->next->next->next->next = new RandomListNode(5);

	head->random = head->next->next;
	head->next->random = head->next->next->next->next;
	head->next->next->next->random = head->next;

	RandomListNode* p = Clone(head);
}