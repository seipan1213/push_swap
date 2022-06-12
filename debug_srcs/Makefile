NAME		=	debug
SRCSDIR		=	./srcs

DEBUG_NAME	=	debug
DEBUG_SRCS_NAME =  debug.c
DEBUG_SRCS	=	main.c debug.c ../srcs/utils/utils_1.c ../srcs/utils/utils_2.c ../srcs/cmd/command_org.c ../srcs/cmd/command_1.c  ../srcs/cmd/command_2.c  ../srcs/cmd/command_3.c ../srcs/lst/lst_utils_1.c ../srcs/lst/lst_utils_2.c ../srcs/lst/lst_utils_3.c ../srcs/lst/lst_utils_4.c ../srcs/sort/quick_sort.c ../srcs/main/push_swap.c ../srcs/sort/sort_min_stack_1.c ../srcs/sort/sort_min_stack_2.c ../srcs/sort/sort_stack_1.c ../srcs/sort/sort_stack_2.c
DEBUG_OBJS	=	${DEBUG_SRCS:.c=.o}

INCLUDES	=	-I ../includes -I ${LIBFTDIR}
LIBFTDIR	=	../libft
LIBFT		=	${LIBFTDIR}/libft.a

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

${NAME}: ${DEBUG_NAME}

all: ${NAME}

${LIBFT}:
	${MAKE} -C ${LIBFTDIR}

${DEBUG_NAME}: ${DEBUG_OBJS} ${LIBFT}
	${CC} ${CFLAGS} ${DEBUG_OBJS} ${LIBFT} ${INCLUDES} -o $@

.c.o:
	${CC} ${CFLAGS} $< -c ${INCLUDES} -o $@

clean:
	rm -f ${DEBUG_OBJS}
	${MAKE} clean -C ${LIBFTDIR}

fclean: clean
	rm -f ${DEBUG_NAME}
	${MAKE} fclean -C ${LIBFTDIR}

re: fclean all

.PHONY: all bonus clean fclean re