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



Slist *BuySlist(DataType x)		//���Ԫ��
{
	Slist *node = (Slist *)malloc(sizeof(Slist));
	assert(node);
	node->data = x;
	node->next = NULL;
	return node;
}


void ListPushback(Slist **head, DataType x)		//β��Ԫ��
{
	if (*head == NULL)		//û��Ԫ�ص����
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






void ListPushFront(Slist **head, DataType x)        //ͷ��Ԫ��  
{
	if (*head == NULL)      //û�н��  
	{
		*head = BuySlist(x);
		return;
	}
	Slist *new;
	new = BuySlist(x);
	new->next = *head;
	*head = new;
}






Slist* Find(Slist *head, DataType x)		//����ָ��Ԫ�أ������±�
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





void Insert(Slist **head, Slist *pos, DataType x)		//����Ԫ��
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





void print(Slist *head)			//��ӡԪ��
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



void ReversePrint(Slist* head)	//��β��ͷ���������
{
	if (head == NULL)
	{
		return;
	}
	Slist* cur = head;
	if (cur->next == NULL)		//ֻ��һ���ڵ�
	{
		printf("%d ", cur->data);
		return;
	}
	ReversePrint(cur->next);
	printf("%d ", cur->data);
	
}


void DelListNode(Slist** pos)		//ɾ��һ����ͷ������ķ�β�ڵ�
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

void PlistInsert(Slist **pos, DataType x)		//����ͷ�������һ���ڵ�ǰ����һ���ڵ㣨���ܱ�������
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


Slist* SListJosephCircle(Slist* phead, int k)        //�����ѹ��ɻ�
{
	if (phead == NULL)
	{
		return NULL;
	}

	Slist* q = phead;
	while (q->next != NULL)		//���ɻ�
	{
		q = q->next;
	}
	q->next = phead;
	
	Slist* cur = phead;
	Slist* p = cur;
	
	while (cur->next != cur)
	{
		int index = k - 1;
		while (index--)		//ȷ��Ҫ�Ƴ��Ľڵ�
		{
			p = p->next;
		}
		if (p->next == cur)		//ʣ�������ڵ�
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


void reverse_list(Slist **pphead)		//����/��ת������
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



void bubble_sort(Slist **pphead)  //ð������
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
		if (flag == 0)		//�Ѿ�����
		{
			return;
		}
	}
}

void SeletSort(Slist** phead)		//ѡ������
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

Slist* SListMerge(Slist* list1, Slist* list2)		//�ϲ�������Ϊ����
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

void SListFindMidNode(Slist* list)		//�����м�ڵ�  �Ѿ���������bug
{
	if (list == NULL)	//û�нڵ�
	{
		return;
	}
	if (list->next == NULL)		//һ���ڵ�
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
	
	if (p2 == NULL)		//ż�����ڵ�
	{
		printf("%d  %d\n", p1->data, p1->next->data);
		return;
	}
	
	if (p2->next == NULL)		//�������ڵ�
	{
		printf("%d \n", p1->data );
		return;
	}
}


void SListFindTailKNode(Slist* list, size_t k)		//������K���ڵ�
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


void SListDeletTailKNode(Slist* list, size_t k)		//ɾ��������K���ڵ�
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