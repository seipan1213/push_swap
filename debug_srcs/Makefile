NAME		=	debug
SRCSDIR		=	./srcs

DEBUG_NAME	=	debug
DEBUG_SRCS_NAME =  debug.c
DEBUG_SRCS	=	debug.c ../srcs/command_org.c ../srcs/command.c ../srcs/lst_utils.c ../srcs/utils.c ../srcs/quick_sort.c ../srcs/push_swap.c
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