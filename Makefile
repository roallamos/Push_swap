NAME = push_swap

BONUS_NAME = checker_mio

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCPATH = ./src/

SOURCES = $(addprefix $(SRCPATH),ft_init_stack.c main.c ft_sort_a.c ft_sort_b.c ft_sort_both.c swap_a.c parse.c values.c threes.c top.c diff.c moves.c moving.c swap_b.c cheap.c)

BONUS_SRC = $(addprefix ./bonus/,main.c parse.c ft_init_stack.c ft_sort_both.c ft_sort_b.c ft_sort_a.c ft_sort.c)

OBJECTS = $(SOURCES:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

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
	rm -f ${BONUS_NAME}

bonus: ${BONUS_OBJ}
	${MAKE} -C ${LPATH}
	${MAKE} -C ./printf
	${MAKE} -C ${LPATH} bonus
	${CC} ${CFLAGS} ${BONUS_SRC} -L ${LPATH} -l ${LNAME} -L ./printf -l ftprintf -o ${BONUS_NAME}


all: ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
