/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 21:46:48 by yeonkim           #+#    #+#             */
/*   Updated: 2021/05/27 14:07:50 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_deque *deq, int len)
{
	t_node	*node;
	int		i;
	int		max_value;

	node = deq->front;
	i = 0;
	max_value = node->value;
	while (i < len && node)
	{
		max_value = bigger(max_value, node->value);
		node = node->next;
		i++;
	}
	return (max_value);
}

int	find_min(t_deque *deq, int len)
{
	t_node	*node;
	int		i;
	int		min_value;

	node = deq->front;
	i = 0;
	min_value = node->value;
	while (i < len && node)
	{
		min_value = less(min_value, node->value);
		node = node->next;
		i++;
	}
	return (min_value);
}

int	find_position(t_deque *deq, int len, int value)
{
	t_node	*node;
	int		i;

	node = deq->front;
	i = 0;
	while (i < len && node)
	{
		if (value == node->value)
			return (i);
		node = node->next;
		i++;
	}
	return (-1);
}

int	get_position(t_deque *a, int value)
{
	t_node	*node;
	int		pos;

	node = a->front;
	pos = 0;
	while (node)
	{
		if (value == node->value)
			break ;
		node = node->next;
		pos++;
	}
	if (pos < a->length / 2)
		return (pos);
	return (pos - a->length);
}
