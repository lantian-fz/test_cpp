#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAXSIZE 8

typedef int Datatype;

typedef struct CircleQueue
{
	Datatype *data;
	int front;
	int rear;
}CircleQueue;

void QueueInit(CircleQueue *q)//初始化
{
	q->data = (Datatype*)malloc(sizeof(Datatype)*MAXSIZE);
	assert(q->data);
	q->front = 0;
	q->rear = 0;
}

int QueueEmpty(CircleQueue *q)//判队空
{
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}

int QueueEnter(CircleQueue *q, Datatype x)//入队
{
	if ((q->rear + 1) % MAXSIZE == q->front)//判断对满
		return 0;
	q->data[q->rear] = x;
	q->rear = (q->rear + 1) % MAXSIZE;
	return 1;
}

int QueueDelete(CircleQueue *q, Datatype *x)//出队
{
	if (QueueEmpty(q))//判队空
		return 0;
	*x = q->data[q->front];
	q->front = (q->front + 1) % MAXSIZE;
	return 1;
}

void QueueShow(CircleQueue *q)//显示
{
	int n = (q->rear - q->front + MAXSIZE) % MAXSIZE;
	int i = q->front;
	printf("元素：");
	while (n--)
	{
		printf("%d ", q->data[i]);
		i = (i + 1) % MAXSIZE;
	}
	n = (q->rear - q->front + MAXSIZE) % MAXSIZE;
	i = q->front;
	printf("\n位置：");
	while (n--)
	{
		printf("%d ", i);
		i = (i + 1) % MAXSIZE;
	}
	printf("\n");
}

void Menu()
{
	printf("          选择\n");
	printf("*    1.入队    2.出队     *\n");
	printf("*    3.显示    0.退出     *\n");
}

int main()
{
	int input = 0;
	int x = 0;
	CircleQueue qu;
	QueueInit(&qu);//初始化循环队列

	do
	{
		Menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("请输入元素(以-1结束):");
			while (scanf("%d", &x), x != -1)
			{
				if (QueueEnter(&qu, x) == 0)
					printf("队列已满，%d 入队失败\n", x);
			}
			break;
		case 2:
			if (QueueDelete(&qu, &x))
				printf("%d出队\n", x);
			else
				printf("队列为空，出队失败\n");
			break;
		case 3:
			QueueShow(&qu);
			break;
		case 0:
			break;
		default:
			printf("没有这个选项!\n");
		}
	} while (input);

	printf("\n");
	system("pause");
	return 0;
}
/*
//二叉排序树 
#include<stdio.h>  
#include<stdlib.h>  

typedef struct BiTNode
{
	int key;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

int SearchBST(BiTree T, int key, BiTree f, BiTree &p)//查找 
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

int InsertBST(BiTree &T, int key)//插入 
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

void InorderTraverse(BiTree T)//中序遍历
{
	if (T)
	{
		InorderTraverse(T->lchild);
		printf("%d ", T->key);
		InorderTraverse(T->rchild);
	}
}

void Delete(BiTree &p) //删除 
{
	BiTree q, s;
	if (!p->lchild &&!p->rchild) //p为叶子节点  
		p = NULL;
	else if (!p->lchild) //左子树为空，重接右子树
	{
		q = p;
		p = p->rchild;
		free(q);
	}
	else if (!p->rchild) //右子树为空，重接左子树
	{
		q = p;
		p = p->lchild;
		free(q);
	}
	else  //左右子树均不为空   
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

int DeleteBST(BiTree &T, int key)//删除 
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
	printf("输入长度：");
	scanf("%d", &n);
	printf("输入元素：");
	while (n--)
	{
		scanf("%d", &e);
		InsertBST(T, e);
	}
	printf("中序遍历：");
	InorderTraverse(T);
	printf("\n");
	while (1)
	{
		printf("输入要查找元素：");
		scanf("%d", &e);
		if (SearchBST(T, e, f, p)) 
			printf("找到了\n");
		else 
			printf("没找到\n");
		printf("输入要插入元素：");
		scanf("%d", &e);
		InsertBST(T, e);
		printf("中序遍历：");
		InorderTraverse(T);
		printf("\n");
		printf("输入要删除元素：");
		scanf("%d", &e);
		DeleteBST(T, e);
		printf("中序遍历：");
		InorderTraverse(T);
		printf("\n");
	}
}
*/