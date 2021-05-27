/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 21:47:17 by yeonkim           #+#    #+#             */
/*   Updated: 2021/05/27 14:09:24 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	if (deq->length == 0)
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

int		push_deque(char **arg, t_deque *new_deque, int ac)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!is_integer(arg[i]) || is_duplicated(new_deque, ft_atoi(arg[i])))
		{
			free(new_deque);
			if (ac == 2)
				free(arg);
			return (0);
		}
		push_back(new_deque, ft_atoi(arg[i]));
		i++;
	}
	return (1);
}

t_deque	*init_deque(int ac, char **av)
{
	t_deque	*new_deque;
	char	**arg;

	new_deque = malloc(sizeof(t_deque));
	if (!new_deque)
		return (NULL);
	new_deque->front = NULL;
	new_deque->back = NULL;
	new_deque->length = 0;
	if (ac == 0)
		return (new_deque);
	if (ac == 2)
		arg = ft_split(av[1], ' ');
	else
		arg = av + 1;
	if (push_deque(arg, new_deque, ac) == 0)
		return (NULL);
	if (ac == 2)
		free(arg);
	return (new_deque);
}
