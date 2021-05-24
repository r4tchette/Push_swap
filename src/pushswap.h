#ifndef PUSHSWAP_H
# define PUSHSWAP_H
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

void			swap(t_deque *deq);
void			push(t_deque *src, t_deque *dst);
void			rotate(t_deque *deq);
void			reverse_rotate(t_deque *deq);

int				command(t_deque *a, t_deque *b, char *com);
int				command_swap(t_deque *a, t_deque *b, char *com);
int				command_push(t_deque *a, t_deque *b, char *com);
int				command_rotate(t_deque *a, t_deque *b, char *com);
int				command_reverse_rotate(t_deque *a, t_deque *b, char *com);

int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlen(const char *s);

#endif
