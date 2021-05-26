/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 21:47:09 by yeonkim           #+#    #+#             */
/*   Updated: 2021/05/26 21:47:29 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	rotate_shortest(t_deque *a, t_deque *b, int pos)
{
	if (pos < b->length - pos)
		command_iteration(a, b, "rb", pos);
	else
		command_iteration(a, b, "rrb", b->length - pos);
}

void	rotate_b(t_deque *a, t_deque *b, int value)
{
	t_node	*node;
	int		pos;

	node = b->front;
	pos = 1;
	while (node->next)
	{
		if (node->value > value && value > node->next->value)
		{
			rotate_shortest(a, b, pos);
			return ;
		}
		node = node->next;
		pos++;
	}
}
