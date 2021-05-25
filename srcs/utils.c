#include "push_swap.h"

int		is_integer(char *str)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		num *= 10;
		num += *str - '0';
		str++;
	}
	num *= sign;
	if (*str != '\0' || ft_strlen(str) > 11 \
	|| num > 2147483647 || num < -2147483648)
		return (0);
	return (1);
}

int		is_sorted(t_deque *a)
{
	t_node	*node;
	int		i;

	node = a->front;
	i = 0;
	while (node != a->back)
	{
		if (node->value >= node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}

int		is_duplicated(t_deque *deq, int value)
{
	t_node	*node;

	if(deq->length == 0)
		return (0);
	node = deq->front;
	while (node != deq->back)
	{
		if (value == node->value)
			return (1);
		node = node->next;
	}
	if (value == node->value)
		return (1);
	return (0);
}

t_deque	*init_deque(int ac, char **av)
{
	t_deque	*new_deque;
	int		i;

	new_deque = malloc(sizeof(t_deque));
	if (!new_deque)
		return (NULL);
	new_deque->front = NULL;
	new_deque->back = NULL;
	new_deque->length = 0;
	i = 1;
	while (i < ac)
	{
		if (!is_integer(av[i]) || is_duplicated(new_deque, ft_atoi(av[i])))
		{
			free(new_deque);
			return (NULL);
		}
		push_back(new_deque, ft_atoi(av[i]));
		i++;
	}
	return (new_deque);
}

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
