/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 21:46:43 by yeonkim           #+#    #+#             */
/*   Updated: 2021/05/27 14:07:06 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	delete_node(t_node *node)
{
	node->next = NULL;
	node->prev = NULL;
	node->value = 0;
	free(node);
}

int			push_back(t_deque *deq, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->value = value;
	new_node->prev = deq->back;
	new_node->next = NULL;
	if (deq->length == 0)
		deq->front = new_node;
	else
		deq->back->next = new_node;
	deq->back = new_node;
	deq->length += 1;
	return (1);
}

int			push_front(t_deque *deq, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->value = value;
	new_node->next = deq->front;
	new_node->prev = NULL;
	if (deq->length == 0)
		deq->back = new_node;
	else
		deq->front->prev = new_node;
	deq->front = new_node;
	deq->length += 1;
	return (1);
}

int			pop_back(t_deque *deq)
{
	t_node	*back;
	int		value;

	if (deq->length == 0)
		return (0);
	back = deq->back;
	value = back->value;
	deq->back = deq->back->prev;
	if (deq->length == 1)
		deq->front = NULL;
	else
		deq->back->next = NULL;
	delete_node(back);
	deq->length -= 1;
	return (value);
}

int			pop_front(t_deque *deq)
{
	t_node	*front;
	int		value;

	if (deq->length == 0)
		return (0);
	front = deq->front;
	value = front->value;
	deq->front = deq->front->next;
	if (deq->length == 1)
		deq->back = NULL;
	else
		deq->front->prev = NULL;
	delete_node(front);
	deq->length -= 1;
	return (value);
}
