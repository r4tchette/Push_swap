#include "push_swap.h"

int		command(t_deque *a, t_deque *b, char *com)
{
	int	ret;

	ret = 0;
	if (ft_strlen(com) == 2)
	{
		if (ft_strequ(com, "s", 1))
			ret = command_swap(a, b, com);
		else if (ft_strequ(com, "p", 1))
			ret = command_push(a, b, com);
		else if (ft_strequ(com, "r", 1))
			ret = command_rotate(a, b, com);
		else
			ret = 0;
	}
	else if (ft_strlen(com) == 3)
	{
		if (ft_strequ(com, "rr", 2))
			ret = command_reverse_rotate(a, b, com);
		else
			ret = 0;
	}
	return (ret);
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

int		main(int ac, char **av)
{
	t_deque	*a;
	t_deque	*b;
	char	*line;

	if (ac < 2)
		return (0);
	a = init_deque(ac, av);
	if (!a)
		return (print_error(&a, &b));
	b = init_deque(0, NULL);
	if (!b)
		return (print_error(&a, &b));
	//ft_printf("a: "); print_stack(a);
	//ft_printf("b: "); print_stack(b);
	while (get_next_line(0, &line) == 1)
	{
		if (!command(a, b, line))
			return (print_error(&a, &b));
		//ft_printf("a: "); print_stack(a);
		//ft_printf("b: "); print_stack(b);
	}
	check_stack(a, b);
	free(a);
	free(b);
	return (0);
}
