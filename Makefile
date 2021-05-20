SRC	=		./src/main.c \
			./src/deque.c

B_SRC =		./src/main.c \
			./src/deque.c

OBJ =		$(SRC:.c=.o)
B_OBJ =		$(B_SRC:.c=.o)

NAME =		push_swap
CC =		gcc
CFLAG =		-Wall -Werror -Wextra
INC =		-I.
RM =		rm -rf

ifdef WITH_BONUS
	OBJ_SELECTED = $(B_OBJ)
else
	OBJ_SELECTED = $(OBJ)
endif

$(NAME):	$(OBJ)
	$(CC) $(CFLAG) -o $(NAME) $(SRC)

all:		$(NAME)

bonus:
	$(MAKE) WITH_BONUS=1 $(NAME)

clean:
	$(RM) $(OBJ) $(B_OBJ)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

.PHONY: all bonus clean fclean re
