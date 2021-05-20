#ifndef DEQUE_H
# define DEQUE_H
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int		value;
}				t_node;

typedef struct	s_deque
{
	struct s_node	*front;
	struct s_node	*back;
	int		length;
}				t_deque;

void			delete_node(t_node *node);
void			push_back(t_deque *deq, int value);
void			push_front(t_deque *deq, int value);
int				pop_back(t_deque *deq);
int				pop_front(t_deque *deq);

#endif
