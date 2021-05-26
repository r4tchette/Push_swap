/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 21:46:37 by yeonkim           #+#    #+#             */
/*   Updated: 2021/05/26 21:47:20 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_deque	*a;
	t_deque	*b;
	char	*line;

	if (ac < 2)
		return (0);
	a = init_deque(ac, av);
	if (!a)
		return (print_error(&a, &b));
	b = init_deque(0, NULL);
	if (!b)
		return (print_error(&a, &b));
	while (get_next_line(0, &line) == 1)
	{
		if (!command(a, b, line))
			return (print_error(&a, &b));
	}
	check_stack(a, b);
	free(a);
	free(b);
	return (0);
}
