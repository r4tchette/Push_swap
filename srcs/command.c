/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 21:46:40 by yeonkim           #+#    #+#             */
/*   Updated: 2021/05/26 21:47:20 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	command_iteration(t_deque *a, t_deque *b, char *cmd, int it)
{
	int	i;

	i = 0;
	while (i < it)
	{
		command(a, b, cmd);
		ft_printf("%s\n", cmd);
		i++;
	}
}

int		command(t_deque *a, t_deque *b, char *com)
{
	int	ret;

	ret = 0;
	if (ft_strlen(com) == 2)
	{
		if (ft_strequ(com, "s", 1))
			ret = command_swap(a, b, com);
		else if (ft_strequ(com, "p", 1))
			ret = command_push(a, b, com);
		else if (ft_strequ(com, "r", 1))
			ret = command_rotate(a, b, com);
		else
			ret = 0;
	}
	else if (ft_strlen(com) == 3)
	{
		if (ft_strequ(com, "rr", 2))
			ret = command_reverse_rotate(a, b, com);
		else
			ret = 0;
	}
	return (ret);
}
