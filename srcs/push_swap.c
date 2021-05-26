#include "push_swap.h"

void	preprocess(t_deque *a, t_deque *b)
{
	int	i;

	i = 0;
	while (i < a->length)
	{
		if (a->front->value > a->front->next->value)
		{
			command(a, b, "sa");
			ft_printf("sa\n");
		}
		command(a, b, "ra");
		command(a, b, "ra");
		ft_printf("ra\nra\n");
		i += 2;
	}
	if (a->length % 2 == 1)
	{
		command(a, b, "ra");
		ft_printf("ra\n");
	}
}

void	command_iteration(t_deque *a, t_deque *b, char *cmd, int it)
{
	int	i;

	i = 0;
	while (i < it)
	{
		command(a, b, cmd);
		ft_printf("%s\n", cmd);
		i++;
	}
}

void	merge(t_deque *a, t_deque *b, int s1, int s2)
{
	int	i;
	int	pos;

	if (s1 + s2 == 2)
	{
		if (a->front->value > a->front->next->value)
			command_iteration(a, b, "sa", 1);
		command_iteration(a, b, "ra", 2);
		return ;
	}
	if (s2 == 0)
	{
		command_iteration(a, b, "ra", s1);
		return ;
	}
	command_iteration(a, b, "pb", s1);
	i = 0;
	while (i < s2)
	{
		if (a->front->value < find_min(b, b->length))
		{
			if (b->front->value == find_max(b, b->length))
			{
				command(a, b, "pb");
				command(a, b, "rb");
				ft_printf("pb\nrb\n");
				i++;
			}
		}
		else if (a->front->value > find_max(b, b->length))
		{
			if (b->front->value == find_max(b, b->length))
			{
				command(a, b, "pb");
				ft_printf("pb\n");
				i++;
			}
		}
		else if (a->front->value > b->front->value && a->front->value < b->back->value)
		{
			command(a, b, "pb");
			ft_printf("pb\n");
			i++;
		}
		command(a, b, "rb");
		ft_printf("rb\n");
	}
	pos = find_position(b, b->length, find_max(b, b->length));
	if (pos < b->length)
		command_iteration(a, b, "rb", pos);
	else
		command_iteration(a, b, "rrb", b->length - pos);
	command_iteration(a, b, "pa", s1 + s2);
	if (s1 + s2 < a->length - s1 - s2)
		command_iteration(a, b, "ra", s1 + s2);
	else
		command_iteration(a, b, "rra", a->length - s1 - s2);
}

void	loop_to_merge(t_deque *a, t_deque *b)
{
	int	size;
	int	idx;

	size = 2;
	while (size < a->length)
	{
		idx = 1;
		while ((size * idx) <= a->length)
		{
			if (idx % 2 == 0)
				merge(a, b, size, size);
			idx++;
		}
		idx--;
		if (idx % 2 == 1)
			merge(a, b, size, a->length - size * idx);
		else
			merge(a, b, a->length - size * idx, 0);
		size *= 2;
	}
}

int		abs(int a)
{
	if (a < 0)
		return (a * (-1));
	return (a);
}

int		get_position(t_deque *a, int value)
{
	t_node	*node;
	int		pos;

	node = a->front;
	pos = 0;
	while (node)
	{
		if (value == node->value)
			break ;
		node = node->next;
		pos++;
	}
	if (pos < a->length / 2)
		return (pos);
	return (pos - a->length);
}

void	pop_value(t_deque *a, t_deque *b, int value)
{
	int	pos;

	pos = get_position(a, value);
	if (pos > 0)
		command_iteration(a, b, "ra", pos);
	else
		command_iteration(a, b, "rra", abs(pos));
	command_iteration(a, b, "pb", 1);
}

int		find_near_min(t_deque *a)
{
	t_node	*node;
	int		pos;
	int		min;
	int		range;

	node = a->front;
	pos = 0;
	min = node->value;
	range = (a->length < 40) ? 10 : a->length / 4;
	while (node)
	{
		if (pos < range || pos > a->length - range)
			min = (min < node->value) ? min : node->value;
		node = node->next;
		pos++;
	}
	return (min);
}

void	rotate_shortest(t_deque *a, t_deque *b, int pos)
{
	if (pos < b->length - pos)
		command_iteration(a, b, "rb", pos);
	else
		command_iteration(a, b, "rrb", b->length - pos);
}

void	rotate_b(t_deque *a, t_deque *b, int value)
{
	t_node	*node;
	int		pos;

	node = b->front;
	pos = 1;
	while (node->next)
	{
		if (node->value > value && value > node->next->value)
		{
			rotate_shortest(a, b, pos);
			return ;
		}
		node = node->next;
		pos++;
	}
}

void	sort_list(t_deque *a, t_deque *b)
{
	int	target;

/*
	ft_printf("a: "); print_stack(a);
	ft_printf("b: "); print_stack(b);
	ft_printf("\n");
*/
	while (a->length > 0)
	{
		target = find_near_min(a);
		if (b->length > 1)
		{
			if (target > find_max(b, b->length) || target < find_min(b, b->length))
				rotate_shortest(a, b, find_position(b, b->length, find_max(b, b->length)));
			else
				rotate_b(a, b, target);
		}
		pop_value(a, b, target);
		if (b->length == 2 && b->front->value < b->front->next->value)
			command_iteration(a, b, "sa", 1);
		if (b->front->value == find_min(b, b->length))
			command_iteration(a, b, "rb", 1);
	}
}

int		main(int ac, char **av)
{
	t_deque	*a;
	t_deque	*b;

	if (ac == 1)
		return (0);
	a = init_deque(ac, av);
	if (!a)
		return (print_error(&a, &b));
	b = init_deque(0, NULL);

	if (!b)
		return (print_error(&a, &b));

//	ft_printf("length : %d\n", a->length);

//	ft_printf("\n----------initial----------\n");
//	ft_printf("a : "); print_stack(a);
//	ft_printf("b : "); print_stack(b);

//	preprocess(a, b);

//	ft_printf("\n----------swapped----------\n");
//	ft_printf("a : "); print_stack(a);
//	ft_printf("b : "); print_stack(b);

/*
	if (a->length == 100)
		sort100(a, b);
	loop_to_merge(a, b);
*/
	//sort100(a, b);

	sort_list(a, b);
/*
	ft_printf("\n----------merged----------\n");
	ft_printf("a : "); print_stack(a);
	ft_printf("b : "); print_stack(b);
	*/

	free(a);
	free(b);
	return (0);
}
