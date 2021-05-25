#include "push_swap.h"

int		print_error(t_deque **a, t_deque **b)
{
	if (*a)
	{
		free(*a);
		*a = NULL;
	}
	if (*b)
	{
		free(*b);
		*b = NULL;
	}
	ft_printf("Error\n");
	return (0);
}

void	print_stack(t_deque *deq)
{
	t_node	*node;

	node = deq->front;
	while (node)
	{
		ft_printf("%d ", node->value);
		node = node->next;
	}
	ft_printf("\n");
}

void	check_stack(t_deque *a, t_deque *b)
{
	if (is_sorted(a) && b->length == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
