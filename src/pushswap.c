#include <stdio.h>
#include "pushswap.h"

void	print(t_deque *deq)
{
	t_node	*node;

	node = deq->front;
	while (node)
	{
		printf("%d ", node->value);
		node = node->next;
	}
	printf("\n");
}

int		main(void)
{
	t_deque	*a;
	t_deque	*b;

	a = malloc(sizeof(t_deque));
	a->front = NULL;
	a->back = NULL;
	a->length = 0;
	b = malloc(sizeof(t_deque));
	b->front = NULL;
	b->back = NULL;
	b->length = 0;
	push_back(a, 2);
	push_back(a, 1);
	push_back(a, 3);
	push_back(a, 6);
	push_back(a, 5);
	push_back(a, 8);
	print(a);
	swap(a);
	print(a);
	push(a, b);
	push(a, b);
	push(a, b);
	print(a);
	swap(a);
	print(a);
	push(b, a);
	push(b, a);
	push(b, a);
	print(a);
	return (0);
}
