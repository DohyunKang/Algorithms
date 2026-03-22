#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000
#define MAX_M 500000

int M, L;
char str[MAX_N] = { '\0' };
char B, C;

typedef char element;

typedef struct _node
{
	element data;
	struct _node* prev;
	struct _node* next;
}node;

node* createNode(element data)
{
	node* newnode = NULL;
	newnode = (node*)calloc(1, sizeof(node));
	if (newnode == NULL)
	{
		exit(1);
	}

	newnode->data = data;
	newnode->prev = NULL;
	newnode->next = NULL;

	return newnode;
}

void appendNode(element data, node* Tail)
{
	node* newnode = createNode(data);

	newnode->next = Tail;
	newnode->prev = Tail->prev;
	Tail->prev->next = newnode;
	Tail->prev = newnode;
}

void deleteNode(node* target)
{
	if (target == NULL || target->prev == NULL || target->next == NULL)
		return;

	target->prev->next = target->next;
	target->next->prev = target->prev;

	free(target);
}

void insertNode(element data, node* cursor)
{
	node* newnode = createNode(data);
	if (newnode == NULL)
		return;

	newnode->prev = cursor->prev;
	newnode->next = cursor;

	cursor->prev->next = newnode;
	cursor->prev = newnode;
}

void inputData(node* cursor, node* Head, node* Tail)
{
	scanf("%s", str);
	scanf("%d", &M);
	L = strlen(str);

	for (int i = 0; i < L; i++)
	{
		appendNode(str[i], Tail);
	}

	for (int i = 0; i < M; i++)
	{
		scanf(" %c", &B);

		if (B == 'P')
		{
			scanf(" %c", &C);
			insertNode(C, cursor);
		}
		else if (B == 'L' && cursor->prev != Head)
		{
			cursor = cursor->prev;
		}
		else if (B == 'D' && cursor != Tail)
		{
			cursor = cursor->next;
		}
		else if (B == 'B' && cursor->prev != Head)
		{
			deleteNode(cursor->prev);
		}
	}
}

void printList(node* Head, node* Tail)
{
	node* curr = Head->next;
	while (curr != Tail)
	{
		printf("%c", curr->data);
		curr = curr->next;
	}
	printf("\n");
}

int main()
{
	node* Head;
	node* Tail;
	node* cursor;

	Head = createNode('H');
	Tail = createNode('T');
    
    Head->next = Tail;
    Tail->prev = Head;
    
	cursor = Tail;

	inputData(cursor, Head, Tail);

	printList(Head, Tail);

	return 0;
}