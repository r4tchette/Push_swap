#include "push_swap.h"

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
