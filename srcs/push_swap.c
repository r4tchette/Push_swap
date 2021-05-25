#include "push_swap.h"

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
	return (0);
}
