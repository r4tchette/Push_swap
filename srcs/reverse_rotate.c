/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 21:47:06 by yeonkim           #+#    #+#             */
/*   Updated: 2021/05/26 21:47:28 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_deque *deq)
{
	push_front(deq, pop_back(deq));
}

int		command_reverse_rotate(t_deque *a, t_deque *b, char *com)
{
	if (ft_strequ(com, "rra", 3))
		reverse_rotate(a);
	else if (ft_strequ(com, "rrb", 3))
		reverse_rotate(b);
	else if (ft_strequ(com, "rrr", 3))
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
	else
		return (0);
	return (1);
}
