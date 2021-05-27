/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 00:29:27 by yeonkim           #+#    #+#             */
/*   Updated: 2021/05/28 00:29:29 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_deque(t_deque *deq)
{
	while (deq->length > 0)
		pop_back(deq);
	free(deq);
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
