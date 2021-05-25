#include "push_swap.h"

void	preprocess(t_deque *a, t_deque *b)
{
	int	i;

	i = 0;
	while (i <= a->length)
	{
		if (a->front->value > a->front->next->value)
		{
			command(a, b, "sa");
			ft_printf("sa\n");
			command(a, b, "ra");
			command(a, b, "ra");
			ft_printf("ra\nra\n");
		}
		i += 2;
	}
	if (a->length % 2 == 1)
	{
		command(a, b, "ra");
		ft_printf("ra\n");
	}
}

void	merge(t_deque *a, t_deque *b, int s1, int s2)
{
	int	i;

	i = 0;
	while (i < s1)
	{
		command(a, b, "pb");
		ft_printf("pb\n");
		i++;
	}
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
	while (b->front->value != find_max(b, b->length))
	{
		command(a, b, "rb");
		ft_printf("rb\n");
	}
	//command_iteration(a, b, "pa", s1 + s2);
	i = 0;
	while (i < s1 + s2)
	{
		command(a, b, "pa");
		ft_printf("pa\n");
		i++;
	}
	i = 0;
	while (i < s1 + s2)
	{
		command(a, b, "ra");
		ft_printf("ra\n");
		i++;
	}

	ft_printf("\n----------merged----------\n");
	ft_printf("a : "); print_stack(a);
	ft_printf("b : "); print_stack(b);
}

void	loop_to_merge(t_deque *a, t_deque *b)
{
	int	size;
	int	idx;

	size = 2;
	idx = 1;
	while ((size * idx) < a->length)
	{
		while ((size * idx) <= (a->length / 2))
		{
			merge(a, b, size, size);
			idx++;
		}
		idx--;
		if ((a->length / 2) - (size * idx) > 0)
			merge(a, b, size, (a->length / 2) - (size * idx));
		size *= 2;
		idx = 1;

	}
}

int		main(int ac, char **av)
{
	t_deque	*a;
	t_deque	*b;

	if (ac < 2)
		return (0);
	a = init_deque(ac, av);
	if (!a)
		return (print_error(&a, &b));
	b = init_deque(0, NULL);
	if (!b)
		return (print_error(&a, &b));

	ft_printf("length : %d\n", a->length);

	ft_printf("\n----------initial----------\n");
	ft_printf("a : "); print_stack(a);
	ft_printf("b : "); print_stack(b);

	preprocess(a, b);

	ft_printf("\n----------swapped----------\n");
	ft_printf("a : "); print_stack(a);
	ft_printf("b : "); print_stack(b);

	loop_to_merge(a, b);

	ft_printf("\n----------merged----------\n");
	ft_printf("a : "); print_stack(a);
	ft_printf("b : "); print_stack(b);

	return (0);
}
