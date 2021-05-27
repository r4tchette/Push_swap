/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 21:47:03 by yeonkim           #+#    #+#             */
/*   Updated: 2021/05/27 14:09:14 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_deque *src, t_deque *dst)
{
	if (src->length == 0)
		return ;
	push_front(dst, pop_front(src));
}

int		command_push(t_deque *a, t_deque *b, char *com)
{
	if (ft_strequ(com, "pa", 2))
		push(b, a);
	else if (ft_strequ(com, "pb", 2))
		push(a, b);
	else
		return (0);
	return (1);
}
