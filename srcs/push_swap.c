/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 21:47:01 by yeonkim           #+#    #+#             */
/*   Updated: 2021/05/27 15:09:29 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	{
		free(a);
		return (print_error(&a, &b));
	}
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
