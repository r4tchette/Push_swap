SRC_CHECKER =	./src/checker.c \
				./src/deque.c \
				./src/swap.c \
				./src/push.c \
				./src/rotate.c \
				./src/reverse_rotate.c \
				./src/ft_strlen.c \
				./src/ft_strncmp.c

SRC_PUSHSWAP =	./src/pushswap.c \
				./src/deque.c \
				./src/swap.c \
				./src/push.c \
				./src/rotate.c \
				./src/reverse_rotate.c \
				./src/ft_strlen.c \
				./src/ft_strncmp.c

OBJ_CHECKER =	$(SRC_CHECKER:.c=.o)
OBJ_PUSHSWAP =	$(SRC_PUSHSWAP:.c=.o)

CHECKER =	checker
PUSHSWAP =	push_swap
CC =		gcc
CFLAG =		-Wall -Werror -Wextra
INC =		-I.
RM =		rm -rf

$(CHECKER):
	$(CC) $(CFLAG) $(SRC_CHECKER) -o $(CHECKER)

$(PUSHSWAP):
	$(CC) $(CFLAG) $(SRC_PUSHSWAP) -o $(PUSHSWAP)

all:	$(CHECKER) $(PUSHSWAP)

clean:
	$(RM) $(OBJ_CHECKER) $(OBJ_PUSHSWAP)

fclean:		clean
	$(RM) $(CHECKER) $(PUSHSWAP)

re:			fclean all

.PHONY: all bonus clean fclean re
