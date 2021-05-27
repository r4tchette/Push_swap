CHECKER = checker
PUSH_SWAP = push_swap
LIB = libft/libft.a

SRCS_CHECKER = srcs/checker.c \
		srcs/deque.c \
		srcs/push.c \
		srcs/reverse_rotate.c \
		srcs/rotate.c \
		srcs/swap.c \
		srcs/utils.c \
		srcs/print.c \
		srcs/ft_strequ.c \
		srcs/command.c

SRCS_PUSH_SWAP = srcs/push_swap.c \
		srcs/deque.c \
		srcs/push.c \
		srcs/reverse_rotate.c \
		srcs/rotate.c \
		srcs/swap.c \
		srcs/utils.c \
		srcs/print.c \
		srcs/ft_strequ.c \
		srcs/math.c \
		srcs/find.c \
		srcs/command.c \
		srcs/sort.c

OBJS_CHECKER = $(SRCS_CHECKER:.c=.o)
OBJS_PUSH_SWAP = $(SRCS_PUSH_SWAP:.c=.o)
INCLUDES += -I libft/libft
INCLUDES += -I libft/get_next_line
INCLUDES += -I libft/libftprintf
CFLAGS = -Wall -Werror -Wextra
CC = gcc
RM = rm -rf

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(CHECKER) $(PUSH_SWAP)

$(CHECKER): $(OBJS_CHECKER) $(LIB)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^

$(PUSH_SWAP): $(OBJS_PUSH_SWAP) $(LIB)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^

$(LIB):
	make -C libft/

clean:
	make clean -C libft/
	$(RM) $(OBJS_CHECKER) $(OBJS_PUSH_SWAP)

fclean: clean
	make fclean -C libft/
	$(RM) $(CHECKER) $(PUSH_SWAP)

re: fclean all

.PHONY: clean fclean re all
