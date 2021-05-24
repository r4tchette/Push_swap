#include "pushswap.h"

void	push(t_deque *src, t_deque *dst)
{
	push_front(dst, pop_front(src));
}

int		command_push(t_deque *a, t_deque *b, char *com)
{
	if (ft_strncmp(com, "pa", 2))
		push(a, b);
	else if (ft_strncmp(com, "pb", 2))
		push(b, a);
	else
		return (0);
	return (1);
}

