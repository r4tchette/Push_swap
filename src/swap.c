#include "pushswap.h"

void	swap(t_deque *deq)
{
	int	first;
	int	second;

	first = pop_front(deq);
	second = pop_front(deq);
	push_front(deq, first);
	push_front(deq, second);
}

int		command_swap(t_deque *a, t_deque *b, char *com)
{
	if (ft_strncmp(com, "sa", 2))
		swap(a);
	else if (ft_strncmp(com, "sb", 2))
		swap(b);
	else if (ft_strncmp(com, "ss", 2))
	{
		swap(a);
		swap(b);
	}
	else
		return (0);
	return (1);
}
