#include "pushswap.h"

void	reverse_rotate(t_deque *deq)
{
	push_front(deq, pop_back(deq));
}

int		command_reverse_rotate(t_deque *a, t_deque *b, char *com)
{
	if (ft_strncmp(com, "rra", 3))
		reverse_rotate(a);
	else if (ft_strncmp(com, "rrb", 3))
		reverse_rotate(b);
	else if (ft_strncmp(com, "rrr", 3))
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
	else
		return (0);
	return (1);
}
