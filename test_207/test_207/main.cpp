#define _CRT_SECURE_NO_WARNINGS 1
//ţ��-ɾ��������м�ڵ�
//���ӣ�https ://www.nowcoder.com/questionTerminal/0796dbf0eb054716937b0b82e0671c5f
//��Դ��ţ����
//����һ������ʵ��ɾ������� K ���ڵ�ĺ�����
//n ��ʾ����ĳ��ȡ�m ��ʾɾ������ڼ����ڵ㡣val ��ʾ����ڵ��ֵ��
//������� :�ڸ����ĺ����з��������ͷָ�롣
//
//����
//5 3
//1 2 3 4 5
//���
//1 2 4 5

#include <iostream>
using namespace std;

struct list_node{
	int val;
	struct list_node * next;
}; //����Ľڵ�

int K;

list_node * input_list(void) //��������
{
	int n, val;
	list_node * phead = new list_node();
	list_node * cur_pnode = phead;
	scanf("%d %d", &n, &K);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &val);
		if (i == 1) {
			cur_pnode->val = val;
			cur_pnode->next = NULL;
		}
		else {
			list_node* new_pnode = new list_node();
			new_pnode->val = val;
			new_pnode->next = NULL;
			cur_pnode->next = new_pnode;
			cur_pnode = new_pnode;
		}
	}
	return phead;
}

list_node* remove_kth_node(list_node* head, int K)
{
	if (head == nullptr || K <= 0)
		return nullptr;
	list_node* p = head;
	for (int i = 1; i < K - 1; i++)
	{
		if (p == nullptr)
			return head;
		p = p->next;
	}
	p->next = p->next->next;
	return head;
}

void print_list(list_node* head)
{
	while (head != NULL) {
		printf("%d ", head->val);
		head = head->next;
	}
}

int main()
{
	list_node* head = input_list(); // �����ͷ�ڵ�
	list_node* rhead = remove_kth_node(head, K);
	print_list(rhead);
	return 0;
}