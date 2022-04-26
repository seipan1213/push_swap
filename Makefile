NAME		=	push_swap
SRCSDIR		=	./srcs

PUSH_SWAP_NAME	=	push_swap
PUSH_SWAP_SRCS_NAME =  lst_utils.c main.c push_swap.c quick_sort.c utils.c
PUSH_SWAP_SRCS	=	$(addprefix ${SRCSDIR}/, ${PUSH_SWAP_SRCS_NAME})
PUSH_SWAP_OBJS	=	${PUSH_SWAP_SRCS:.c=.o}

INCLUDES	=	-I ./includes -I ${LIBFTDIR}
LIBFTDIR	=	./libft
LIBFT		=	${LIBFTDIR}/libft.a

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

${NAME}: ${PUSH_SWAP_NAME}

all: ${NAME}

${LIBFT}:
	${MAKE} -C ${LIBFTDIR}

${PUSH_SWAP_NAME}: ${PUSH_SWAP_OBJS} ${LIBFT}
	${CC} ${CFLAGS} ${PUSH_SWAP_OBJS} ${LIBFT} ${INCLUDES} -o $@

.c.o:
	${CC} ${CFLAGS} $< -c ${INCLUDES} -o $@

clean:
	rm -f ${PUSH_SWAP_OBJS}
	${MAKE} clean -C ${LIBFTDIR}

fclean: clean
	rm -f ${PUSH_SWAP_NAME}
	${MAKE} fclean -C ${LIBFTDIR}

re: fclean all

.PHONY: all bonus clean fclean re