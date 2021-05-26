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

int	find_position(t_deque *deq, int len, int value)
{
	t_node	*node;
	int		i;

	node = deq->front;
	i = 0;
	while (i < len && node)
	{
		if (value == node->value)
			return (i);
		node = node->next;
		i++;
	}
	return (-1);
}
