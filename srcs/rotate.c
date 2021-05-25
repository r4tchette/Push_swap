#include "push_swap.h"

void	rotate(t_deque *deq)
{
	push_back(deq, pop_front(deq));
}

int		command_rotate(t_deque *a, t_deque *b, char *com)
{
	if (ft_strequ(com, "ra", 2))
		rotate(a);
	else if (ft_strequ(com, "rb", 2))
		rotate(b);
	else if (ft_strequ(com, "rr", 2))
	{
		rotate(a);
		rotate(b);
	}
	else
		return (0);
	return (1);
}
