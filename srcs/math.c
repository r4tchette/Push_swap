#include "push_swap.h"

int	bigger(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	less(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	find_max(t_deque *deq, int len)
{
	t_node	*node;
	int		i;
	int		max_value;

	node = deq->front;
	i = 0;
	max_value = node->value;
	while (i < len && node)
	{
		max_value = bigger(max_value, node->value);
		node = node->next;
		i++;
	}
	return (max_value);
}

int	find_min(t_deque *deq, int len)
{
	t_node	*node;
	int		i;
	int		min_value;

	node = deq->front;
	i = 0;
	min_value = node->value;
	while (i < len && node)
	{
		min_value = less(min_value, node->value);
		node = node->next;
		i++;
	}
	return (min_value);
}
