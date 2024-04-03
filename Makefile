NAME = push_swap.out

CC = cc

CFLAGS = -Wall -Werror -Wextra

SOURCES = ft_init_stack.c main.c ft_sort_a.c ft_sort_b.c 

OBJECTS = $(SOURCES:.c=.o)

LPATH = ./libft

LNAME = ft

${NAME}: ${OBJECTS}
	${MAKE} -C ${LPATH}
	${MAKE} -C ${LPATH} bonus
	${CC} ${CFLAGS} ${SOURCES} -L ${LPATH} -l ${LNAME} -g

clean:
	${MAKE} -C ./libft clean
	rm -f ${OBJECTS} ${BONUS_OBJ}

fclean: clean
	${MAKE} -C ./libft fclean
	rm -f ${NAME}

all: ${NAME}

re: fclean all

.PHONY: all clean fclean re

