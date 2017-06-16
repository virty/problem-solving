#include <stdio.h>

#define MAX_NODE 100

typedef struct listNode
{
	int data;
	struct listNode* prev;
	struct listNode* next;
} ListNode;

typedef struct
{
	int use;
	ListNode node;
} ListNodeHeap;

ListNodeHeap heap[MAX_NODE];

void initHeap()
{
	for (int i = 0; i < MAX_NODE; i++)
		heap[i].use = 0;
}

void initListNode(ListNode* node)
{
	node->data = 0;
	node->prev = node;
	node->next = node;
}

ListNode* getListNode()
{
	for (int i = 0; i < MAX_NODE; i++)
	{
		if (!heap[i].use)
		{
			heap[i].use = 1;
			initListNode(&heap[i].node);
			return &heap[i].node;
		}
	}
	return NULL;
}

void destroyListNode(ListNode* node)
{
	ListNodeHeap* heap_node = (ListNodeHeap*)((int*)node - 1);
	heap_node->use = 0;
}

ListNode* appendListNode(ListNode* list, int data)
{
	ListNode* node = getListNode();
	node->data = data;
	if (list == NULL)
		return node;
	else
	{
		ListNode* last = list->prev;
		last
	}
}

int main()
{
	int T, N, val;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &val);
		}
	}
}