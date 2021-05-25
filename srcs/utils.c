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

int		ft_strequ(char *s1, char *s2, int len)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	if (ft_strlen(s1) == 0 || ft_strlen(s2) == 0)
		return (0);
	while (i < len)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
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

int	is_duplicated(t_deque *deq, int value)
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
