#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<Windows.h>
#include<assert.h>
typedef int DataType;
typedef struct Slist
{
	struct Slist *next;
	DataType data;
}Slist;


Slist List;



Slist *BuySlist(DataType x)		//添加元素
{
	Slist *node = (Slist *)malloc(sizeof(Slist));
	assert(node);
	node->data = x;
	node->next = NULL;
	return node;
}


void ListPushback(Slist **head, DataType x)		//尾插元素
{
	if (*head == NULL)		//没有元素的情况
	{
		*head = BuySlist(x);
	}
	else
	{
		Slist *cur = *head;
		while (cur->next != NULL)
		{		
			cur = cur->next;
		}
		cur->next = BuySlist(x);
	}
}






void ListPushFront(Slist **head, DataType x)        //头插元素  
{
	if (*head == NULL)      //没有结点  
	{
		*head = BuySlist(x);
		return;
	}
	Slist *new;
	new = BuySlist(x);
	new->next = *head;
	*head = new;
}






Slist* Find(Slist *head, DataType x)		//查找指定元素，返回下标
{
	Slist *cur = head;
	while (cur!=NULL)
	{
		if (cur->data == x)
		{
			return cur;

		}
		cur = cur->next;
	}
	return NULL;
}





void Insert(Slist **head, Slist *pos, DataType x)		//插入元素
{
	assert(*head&&pos);
	//assert(pos);
	Slist *cur = *head;
	Slist *tmp=NULL;
	while (cur->next!=pos)
	{
		
		cur=cur->next; 
	}
	tmp = BuySlist(x);
	tmp->next = pos;
	cur->next = tmp;
}





void print(Slist *head)			//打印元素
{
	Slist *cur = head;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL");
	printf("\n");
}



void ReversePrint(Slist* head)	//从尾到头输出单链表
{
	if (head == NULL)
	{
		return;
	}
	Slist* cur = head;
	if (cur->next == NULL)		//只有一个节点
	{
		printf("%d ", cur->data);
		return;
	}
	ReversePrint(cur->next);
	printf("%d ", cur->data);
	
}


void DelListNode(Slist** pos)		//删除一个无头单链表的非尾节点
{
	if (*pos == NULL)
	{
		return;
	}
	if ((*pos)->next == NULL)
	{
		free(pos);
		pos = NULL;
	}
	else
	{
		Slist* ret = (*pos)->next;
		(*pos)->data = ret->data;
		(*pos)->next = ret->next;
		free(ret);
		ret = NULL;
	}

}

void swap(DataType* x, DataType* y)
{
	DataType tmp=*x;
	*x = *y;
	*y = tmp;
}

void PlistInsert(Slist **pos, DataType x)		//在无头单链表的一个节点前插入一个节点（不能遍历链表）
{
	if (*pos == NULL)
	{
		return;
	}
	else
	{
		Slist* cur = BuySlist(x);
		cur->next = (*pos)->next;
		(*pos)->next = cur;
		swap(&(*pos)->data, &cur->data);	
	}
}


Slist* SListJosephCircle(Slist* phead, int k)        //链表已构成环
{
	if (phead == NULL)
	{
		return NULL;
	}

	Slist* q = phead;
	while (q->next != NULL)		//构成环
	{
		q = q->next;
	}
	q->next = phead;
	
	Slist* cur = phead;
	Slist* p = cur;
	
	while (cur->next != cur)
	{
		int index = k - 1;
		while (index--)		//确定要移除的节点
		{
			p = p->next;
		}
		if (p->next == cur)		//剩下两个节点
		{
			free(p);
			p = NULL;
			return cur;
		}
		cur->next = p->next;
		free(p);
		cur = cur->next;
		p = cur;
		
	}
	return NULL;
}


void reverse_list(Slist **pphead)		//逆置/反转单链表
{
	if (*pphead == NULL||(*pphead)->next==NULL)
	{
		return ;
	}
	Slist* p1 = *pphead;
	Slist* p2 = p1->next;
	Slist* p3 = p2->next;
	p1->next = NULL;
	while (p3!=NULL)
	{
		p2->next = p1; 
		p1 = p2;
		p2 = p3;
		p3 = p2->next;
	}
	p2->next = p1;
	*pphead = p2;
}



void bubble_sort(Slist **pphead)  //冒泡排序
{
	if (*pphead == NULL)
	{
		return;
	}
	int flag = 0;
	Slist* tail = NULL;
	while (tail != (*pphead)->next)
	{
		Slist* cur = *pphead;
		while (cur->next != tail)
		{
			if (cur->data > (cur->next)->data)
			{
				flag = 1;
				swap(&cur->data, &(cur->next)->data);
			}
			cur = cur->next;
		}

		tail = cur;
		if (flag == 0)		//已经有序
		{
			return;
		}
	}
}

void SeletSort(Slist** phead)		//选择排序
{
	if (*phead == NULL)
	{
		return;
	}
	Slist* p1 = *phead;
	while (p1->next != NULL)
	{
		Slist* min = p1;
		Slist* p2 = p1;
		while (p2!=NULL)
		{
			if (p2->data <= min->data)
			{
				min = p2;
			}
			p2 = p2->next;
		}
		if (min != p1)
		{
			swap(&min->data, &p1->data);
		}
		p1 = p1->next;
	}

}

Slist* SListMerge(Slist* list1, Slist* list2)		//合并两量表为有序
{
	assert(list1&&list2);
	Slist* p1 = list1;
	Slist* p2 = list2;
	Slist* list3 = NULL;
	while (1)
	{
		if (p1->data <= p2->data)
		{
			ListPushback(&list3, p1->data);
			p1 = p1->next;
		}
		if (p1 == NULL)
		{
			break;
		}
		if (p1->data > p2->data)
		{
			ListPushback(&list3, p2->data);
			p2 = p2->next;
		}
		if (p2 == NULL)
		{
			break;
		}
	}
	Slist* p3 = list3;
	while(p3->next != NULL)
	{
		p3 = p3->next;
	}

	if (p1 == NULL)
	{
		p3->next = p2;

	}
	if (p2 == NULL)
	{
		p3->next = p1;;
	}
	return list3;
}

void SListFindMidNode(Slist* list)		//查找中间节点  已经过测试无bug
{
	if (list == NULL)	//没有节点
	{
		return;
	}
	if (list->next == NULL)		//一个节点
	{
		printf("%d\n", list->data);
		return;
	}
	Slist* p1 = list;
	Slist* p2 = list;
	while ( p2 != NULL && p2->next != NULL)
	{		
		p2 = p2->next->next;
		if (p2 == NULL)
		{
			break;
		}
		p1 = p1->next;
	}
	
	if (p2 == NULL)		//偶数个节点
	{
		printf("%d  %d\n", p1->data, p1->next->data);
		return;
	}
	
	if (p2->next == NULL)		//奇数个节点
	{
		printf("%d \n", p1->data );
		return;
	}
}


void SListFindTailKNode(Slist* list, size_t k)		//倒数第K个节点
{
	if (list == NULL)
	{
		return;
	}
	Slist* p1 = list;
	Slist* p2 = list;
	while (k--)
	{
		p2 = p2->next;
	}

	while (p2 != NULL)
	{
		p2 = p2->next;
		p1 = p1->next;
	}
	printf("%d\n", p1->data);
}


void SListDeletTailKNode(Slist* list, size_t k)		//删除倒数第K个节点
{
	if (list == NULL)
	{
		return;
	}
	Slist* p1 = list;
	Slist* pre = p1;
	Slist* p2 = list;
	while (k--)
	{
		p2 = p2->next;
	}

	while (p2 != NULL)
	{
		p2 = p2->next;
		pre = p1;
		p1 = p1->next;
	}
	DelListNode(&p1);
}




void test1()
{
	Slist *list = NULL;
	
	ListPushback(&list, 1);	
	ListPushback(&list, 4);
	ListPushback(&list, 5);
	ListPushback(&list, 2);
	ListPushback(&list, 10);
	ListPushback(&list, 20);
	SListDeletTailKNode(list, 2);
	print(list);
}

int main()
{
	
	test1();
	system("pause");
	return 0;
}