#define _CRT_SECURE_NO_WARNINGS 1
//剑指offer-复杂链表的复杂
//链接：https ://www.nowcoder.com/questionTerminal/f836b2c43afc4b35ad6adc41ec941dba
//来源：牛客网
//
//输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个
//特殊指针random指向一个随机节点），请对此链表进行深拷贝，并返回拷贝后的头结点。
//（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）

#include <iostream>
using namespace std;

struct RandomListNode 
{
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :label(x), next(NULL), random(NULL) {}
};

//复制原链表的结点，并将复制出的结点连在原结点后面
//即2->3->4->null，变为了2->2->3->3->4->4->null
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

//复制原链表的random指针
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

//拆分链表，得到复制的链表
RandomListNode* RandomNode(RandomListNode* head)
{
	RandomListNode* pNode = head;
	RandomListNode* cloneHead = nullptr;
	RandomListNode* cloneNode = nullptr;

	if (pNode)
	{
		cloneHead = pNode->next;//复制链表的头结点
		cloneNode = pNode->next;
		pNode->next = cloneNode->next;
		pNode = pNode->next;
	}
	//得到奇数链表
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