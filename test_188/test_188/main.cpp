#define _CRT_SECURE_NO_WARNINGS 1
//���������� 
#include<stdio.h>  
#include<stdlib.h>  

typedef struct BiTNode
{
	int key;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

int SearchBST(BiTree T, int key, BiTree f, BiTree &p)//���� 
{
	if (!T)  
	{
		p = f; 
		return 0; 
	}
	else if (key == T->key) 
	{ 
		p = T; 
		return 1; 
	}
	else if (key<T->key) 
		SearchBST(T->lchild, key, T, p);
	else 
		SearchBST(T->rchild, key, T, p);
}

int InsertBST(BiTree &T, int key)//���� 
{
	if (!T)
	{
		T = (BiTree)malloc(sizeof(BiTNode));
		T->key = key;
		T->lchild = (T)->rchild = NULL;
		return 1;
	}
	if (key == T->key) 
		return 0;
	if (key>T->key) 
		InsertBST(T->rchild, key);
	else 
		InsertBST(T->lchild, key);
}

void InorderTraverse(BiTree T)//�������
{
	if (T)
	{
		InorderTraverse(T->lchild);
		printf("%d ", T->key);
		InorderTraverse(T->rchild);
	}
}

void Delete(BiTree &p) //ɾ�� 
{
	BiTree q, s;
	if (!p->lchild &&!p->rchild) //pΪҶ�ӽڵ�  
		p = NULL;
	else if (!p->lchild) //������Ϊ�գ��ؽ�������
	{
		q = p;
		p = p->rchild;
		free(q);
	}
	else if (!p->rchild) //������Ϊ�գ��ؽ�������
	{
		q = p;
		p = p->lchild;
		free(q);
	}
	else  //������������Ϊ��   
	{
		q = p;
		s = p->lchild;
		while (s->rchild)
		{
			q = s;
			s = s->rchild;
		}
		p->key = s->key;
		if (q != p)
			q->rchild = s->lchild;
		else
			q->lchild = s->lchild;
		free(s);
	}
}

int DeleteBST(BiTree &T, int key)//ɾ�� 
{
	if (!T) 
		return 0;
	else
	{
		if (key == T->key) Delete(T);
		else if (key<T->key)  
			DeleteBST(T->lchild, key);
		else 
			DeleteBST(T->rchild, key);
	}
}

int main()
{
	int e = 0, n = 0;
	BiTree T = NULL, f=NULL, p=NULL;
	printf("���볤�ȣ�");
	scanf("%d", &n);
	printf("����Ԫ�أ�");
	while (n--)
	{
		scanf("%d", &e);
		InsertBST(T, e);
	}
	printf("���������");
	InorderTraverse(T);
	printf("\n");
	while (1)
	{
		printf("����Ҫ����Ԫ�أ�");
		scanf("%d", &e);
		if (SearchBST(T, e, f, p)) 
			printf("�ҵ���\n");
		else 
			printf("û�ҵ�\n");
		printf("����Ҫ����Ԫ�أ�");
		scanf("%d", &e);
		InsertBST(T, e);
		printf("���������");
		InorderTraverse(T);
		printf("\n");
		printf("����Ҫɾ��Ԫ�أ�");
		scanf("%d", &e);
		DeleteBST(T, e);
		printf("���������");
		InorderTraverse(T);
		printf("\n");
	}
}
