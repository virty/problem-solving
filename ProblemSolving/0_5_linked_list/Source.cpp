#include <stdio.h>

struct _node {
	int key;
	struct _node *next;
} node_t;
typedef struct _node node_t;