#include <stdio.h>
#include <malloc.h>

int T, V, E, Q, v1, v2, q1;

typedef struct node
{
	int vertex;
	node *next;
} Node;

typedef struct
{
	int num;
	Node *head;
	Node *tail;
} List;

typedef struct
{
	int num;
	List *list;
} Graph;

Node* createNode(int v)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->vertex = v;
	newNode->next = NULL;
	return newNode;
}

Graph* createGraph(int n)
{
	Graph *graph = (Graph*)malloc(sizeof(Graph));
	graph->num = n;
	graph->list = (List*)malloc(sizeof(List)*n);
	for (int i = 0; i < n; i++)
	{
		graph->list[i].num = 0;
		graph->list[i].head = graph->list[i].tail = NULL;
	}
	return graph;
}

void addEdge(Graph *graph, int v1, int v2)
{
	Node *newNode = createNode(v2);
	if (graph->list[v1].tail != NULL)
	{
		graph->list[v1].tail->next = newNode;
		graph->list[v1].tail = newNode;		
	}
	else
	{
		graph->list[v1].tail = graph->list[v1].head = newNode;
	}
	graph->list[v1].num++;

	newNode = createNode(v1);
	if (graph->list[v2].tail != NULL)
	{
		graph->list[v2].tail->next = newNode;
		graph->list[v2].tail = newNode;
	}
	else
	{
		graph->list[v2].tail = graph->list[v2].head = newNode;
	}
	graph->list[v2].num++;
}

void displayGraph(Graph *graph, int v)
{
	Node *nodePtr = graph->list[v].head;
	while (nodePtr)
	{
		printf("%d ", nodePtr->vertex);
		nodePtr = nodePtr->next;
	}
	printf("\n");
}

void destroyGraph(Graph *graph)
{
	if (graph)
	{
		if (graph->list)
		{
			for (int i = 0; i < graph->list->num; i++)
			{
				Node *node = graph->list[i].head;
				while (node)
				{
					Node *tmp = node;
					node = node->next;
					free(tmp);
				}
			}
			free(graph->list);
		}
		free(graph);
	}
}

int main()
{
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		printf("#%d\n", tc);
		scanf("%d %d %d", &V, &E, &Q);
		Graph *graph = createGraph(V);
		for (int i = 0; i < E; i++)
		{
			scanf("%d %d", &v1, &v2);
			addEdge(graph, v1, v2);
		}
		for (int i = 0; i < Q; i++)
		{
			scanf("%d", &q1);
			displayGraph(graph, q1);
		}
		destroyGraph(graph);
	}
	return 0;
}







