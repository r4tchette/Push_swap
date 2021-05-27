/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 21:47:01 by yeonkim           #+#    #+#             */
/*   Updated: 2021/05/27 15:01:27 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pop_value(t_deque *a, t_deque *b, int value)
{
	int	pos;

	pos = get_position(a, value);
	if (pos > 0)
		command_iteration(a, b, "ra", pos);
	else
		command_iteration(a, b, "rra", abs(pos));
	command_iteration(a, b, "pb", 1);
}

int		find_near_min(t_deque *a, int size)
{
	t_node	*node;
	int		pos;
	int		min;
	int		range;

	node = a->front;
	pos = 0;
	min = node->value;
	range = (a->length < 30) ? 6 : a->length / 5;
	if (size > 100)
		range = (a->length < 288) ? 12 : a->length / 24;
	while (node)
	{
		if (pos < range || pos > a->length - range)
			min = (min < node->value) ? min : node->value;
		node = node->next;
		pos++;
	}
	return (min);
}

void	sort_list(t_deque *a, t_deque *b, int size)
{
	int	target;

	while (a->length > 0)
	{
		target = find_near_min(a, size);
		if (b->length > 1)
		{
			if (target > find_max(b, b->length) \
			|| target < find_min(b, b->length))
				rotate_shortest(a, b, \
				find_position(b, b->length, find_max(b, b->length)));
			else
				rotate_b(a, b, target);
		}
		pop_value(a, b, target);
		if (b->length == 2 && b->front->value < b->front->next->value)
			command_iteration(a, b, "sa", 1);
		if (b->front->value == find_min(b, b->length))
			command_iteration(a, b, "rb", 1);
	}
	command_iteration(a, b, "pa", b->length);
}

void	sort_three(t_deque *a, t_deque *b)
{
	if (find_min(a, a->length) == a->front->value && \
		find_max(a, a->length) == a->front->next->value)
	{
		command_iteration(a, b, "sa", 1);
		command_iteration(a, b, "ra", 1);
	}
	else if (find_min(a, a->length) == a->front->next->value && \
		find_max(a, a->length) == a->back->value)
		command_iteration(a, b, "sa", 1);
	else if (find_min(a, a->length) == a->back->value && \
		find_max(a, a->length) == a->front->next->value)
		command_iteration(a, b, "rra", 1);
	else if (find_min(a, a->length) == a->front->next->value && \
		find_max(a, a->length) == a->front->value)
		command_iteration(a, b, "ra", 1);
	else if (find_min(a, a->length) == a->back->value && \
		find_max(a, a->length) == a->front->value)
	{
		command_iteration(a, b, "sa", 1);
		command_iteration(a, b, "rra", 1);
	}
}

void	sort_five(t_deque *a, t_deque *b)
{
	int	cnt;

	command_iteration(a, b, "pb", 2);
	sort_three(a, b);
	if (b->front->value > b->back->value)
		command_iteration(a, b, "sb", 1);
	if (b->front->value < find_min(a, a->length))
		command_iteration(a, b, "pa", 1);
	cnt = 0;
	while (cnt < a->length)
	{
		if (b->length > 0)
		{
			if (a->back->value < b->front->value && \
			b->front->value < a->front->value)
				command_iteration(a, b, "pa", 1);
		}
		command_iteration(a, b, "ra", 1);
		cnt++;
	}
	while (b->length > 0)
	{
		command_iteration(a, b, "pa", 1);
		command_iteration(a, b, "ra", 1);
	}
}

int		main(int ac, char **av)
{
	t_deque	*a;
	t_deque	*b;

	if (ac == 1)
		return (0);
	a = init_deque(ac, av);
	if (!a)
		return (print_error(&a, &b));
	b = init_deque(0, NULL);
	if (!b)
		return (print_error(&a, &b));
	if (is_sorted(a))
		return (0);
	if (a->length == 3)
		sort_three(a, b);
	else if (a->length == 5)
		sort_five(a, b);
	else
		sort_list(a, b, a->length);
	free(a);
	free(b);
	return (0);
}
