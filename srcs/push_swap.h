/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:06:41 by yeonkim           #+#    #+#             */
/*   Updated: 2021/05/28 00:23:33 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct		s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				value;
}					t_node;

typedef struct		s_deque
{
	struct s_node	*front;
	struct s_node	*back;
	int				length;
}					t_deque;

void				print_stack(t_deque *deq);
int					push_back(t_deque *deq, int value);
int					push_front(t_deque *deq, int value);
int					pop_back(t_deque *deq);
int					pop_front(t_deque *deq);

void				swap(t_deque *deq);
void				push(t_deque *src, t_deque *dst);
void				rotate(t_deque *deq);
void				reverse_rotate(t_deque *deq);

int					command(t_deque *a, t_deque *b, char *com);
int					command_swap(t_deque *a, t_deque *b, char *com);
int					command_push(t_deque *a, t_deque *b, char *com);
int					command_rotate(t_deque *a, t_deque *b, char *com);
int					command_reverse_rotate(t_deque *a, t_deque *b, char *com);

int					ft_strequ(char *s1, char *s2, int len);

int					print_error(t_deque **a, t_deque **b);
void				print_stack(t_deque *deq);
void				check_stack(t_deque *a, t_deque *b);

int					is_integer(char *str);
int					is_sorted(t_deque *a);
int					is_duplicated(t_deque *deq, int value);
t_deque				*init_deque(int ac, char **av);
int					command(t_deque *a, t_deque *b, char *com);
void				command_iteration(t_deque *a, t_deque *b, \
										char *cmd, int it);

int					bigger(int a, int b);
int					less(int a, int b);
int					find_max(t_deque *deq, int len);
int					find_min(t_deque *deq, int len);
int					find_position(t_deque *deq, int len, int value);
int					get_position(t_deque *a, int value);

void				rotate_shortest(t_deque *a, t_deque *b, int pos);
void				rotate_b(t_deque *a, t_deque *b, int value);

void				pop_value(t_deque *a, t_deque *b, int value);
int					find_near_min(t_deque *a, int size);
void				sort_list(t_deque *a, t_deque *b, int size);
void				sort_three(t_deque *a, t_deque *b);
void				sort_five(t_deque *a, t_deque *b);

void				free_deque(t_deque *deq);
#endif
