#include <stdio.h>
#include <malloc.h>

typedef struct node
{
	int value;
	node *prev;
	node *next;
} Node;

typedef struct
{
	int num;
	Node *head;
	Node *tail;
} List;

Node* createNode(int val)
{
	Node *node = (Node*)malloc(sizeof(Node));
	node->value = val;
	node->prev = node->next = node;
	return node;
}

List* createList()
{
	List *list = (List*)malloc(sizeof(List));
	list->num = 0;
	list->head = list->tail = NULL;
	return list;
}

void appendNode(List *list, Node *node)
{
	if (list->head == NULL)
	{
		list->head = list->tail = node;
	}
	else
	{
		list->tail->next = node;
		node->prev = list->tail;
		node->next = list->head;
		list->tail = node;
	}
}

void deleteNode(List *list, Node *node)
{
	printf("delete(%d)\n", node->value);	
	Node *prevNode = node->prev;
	Node *nextNode = node->next;
	prevNode->next = nextNode;
	nextNode->prev = prevNode;
	if (node == list->head)
		list->head = nextNode;
	if (node == list->tail)
		list->tail = prevNode;
	list->tail->next = list->head;
	free(node);
}

void displayList(List *list)
{
	Node *node = list->head;
	while (node != list->tail)
	{
		printf("%d ", node->value);
		node = node->next;
	}
	printf("%d\n", list->tail->value);
}

void display(List *list)
{
	Node *node = list->head;
	for(int i=0; i<20; i++)
	{
		printf("%d ", node->value);
		node = node->next;
	}
	printf("\n");
}

void destroyList(List *list)
{
	if (list)
	{
		Node *node = list->head;
		while (node != list->tail)
		{
			Node *temp = node;
			node = node->next;
			free(temp);
		}
		free(list->tail);
		free(list);
	}
}

int main()
{
	int T, N, v;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		printf("#%d\n", tc);
		List *list = createList();
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &v);
			Node *node = createNode(v);
			appendNode(list, node);
		}

		Node *node = list->head;
		while (node->next != node)
		{
			Node *nextNode = node->next;
			deleteNode(list, node);
			//displayList(list);
			node = nextNode->next->next;
		}
		displayList(list);
		//display(list);
		destroyList(list);
	}
	return 0;
}