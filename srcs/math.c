/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 21:46:54 by yeonkim           #+#    #+#             */
/*   Updated: 2021/05/26 21:47:24 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bigger(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	less(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	abs(int a)
{
	if (a < 0)
		return (a * (-1));
	return (a);
}
