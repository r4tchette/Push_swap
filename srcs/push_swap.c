/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 21:47:01 by yeonkim           #+#    #+#             */
/*   Updated: 2021/05/26 21:51:28 by yeonkim          ###   ########.fr       */
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

	range = (a->length < 48) ? 6 : a->length / 8;
	if (size > 400)
		//range = 16;
		range = (a->length < 336) ? 12 : a->length / 28;
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
	sort_list(a, b, a->length);
	free(a);
	free(b);
	return (0);
}
