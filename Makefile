NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCPATH = ./src/

SOURCES = $(addprefix $(SRCPATH),ft_init_stack.c main.c ft_sort_a.c ft_sort_b.c ft_sort_both.c swap_a.c parse.c values.c threes.c top.c diff.c moves.c moving.c swap_b.c cheap.c)

OBJECTS = $(SOURCES:.c=.o)

LPATH = ./libft

LNAME = ft

${NAME}: ${OBJECTS}
	${MAKE} -C ${LPATH}
	${MAKE} -C ./printf
	${MAKE} -C ${LPATH} bonus
	${CC} ${CFLAGS} ${SOURCES} -L ${LPATH} -l ${LNAME} -L ./printf -l ftprintf -o ${NAME}

clean:
	${MAKE} -C ./libft clean
	${MAKE} -C ./printf	clean
	rm -f ${OBJECTS} ${BONUS_OBJ}

fclean: clean
	${MAKE} -C ./libft fclean
	${MAKE} -C ./printf	fclean
	rm -f ${NAME}

all: ${NAME}

re: fclean all

.PHONY: all clean fclean re
