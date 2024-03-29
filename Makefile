NAME		=	push_swap
SRCSDIR		=	./srcs

CMD_SRCS_NAME	=	command_1.c command_2.c command_3.c command_org.c
LST_SRCS_NAME	=	lst_utils_1.c lst_utils_2.c lst_utils_3.c lst_utils_4.c
SORT_SRCS_NAME	=	quick_sort.c sort_min_stack_1.c sort_min_stack_2.c sort_stack_1.c
MAIN_SRCS_NAME	=	main.c  push_swap.c
UTILS_SRCS_NAME	=	utils_1.c
PUSH_SWAP_SRCS_NAME =	$(addprefix cmd/, ${CMD_SRCS_NAME})\
						$(addprefix lst/, ${LST_SRCS_NAME})\
						$(addprefix sort/, ${SORT_SRCS_NAME})\
						$(addprefix main/, ${MAIN_SRCS_NAME})\
						$(addprefix utils/, ${UTILS_SRCS_NAME})
PUSH_SWAP_SRCS	=	$(addprefix ${SRCSDIR}/, ${PUSH_SWAP_SRCS_NAME})
PUSH_SWAP_OBJS	=	${PUSH_SWAP_SRCS:.c=.o}

CHECKER_NAME		=	checker
CHECKER_SRCSDIR		=	./srcs/checker
CHECKER_SRCS_NAME	=	main.c\
						$(addprefix ../cmd/, ${CMD_SRCS_NAME})\
						$(addprefix ../lst/, ${LST_SRCS_NAME})\
						$(addprefix ../sort/, ${SORT_SRCS_NAME})\
						$(addprefix ../utils/, ${UTILS_SRCS_NAME})
CHECKER_SRCS	=	$(addprefix ${CHECKER_SRCSDIR}/, ${CHECKER_SRCS_NAME})
CHECKER_OBJS	=	${CHECKER_SRCS:.c=.o}

INCLUDES	=	-I ./includes -I ${LIBFTDIR}
LIBFTDIR	=	./libft
LIBFT		=	${LIBFTDIR}/libft.a

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

all: ${NAME}

bonus: ${CHECKER_NAME}

${LIBFT}:
	${MAKE} -C ${LIBFTDIR}

${NAME}: ${PUSH_SWAP_OBJS} ${LIBFT}
	${CC} ${CFLAGS} ${PUSH_SWAP_OBJS} ${LIBFT} ${INCLUDES} -o $@

${CHECKER_NAME}: ${CHECKER_OBJS} ${LIBFT}
	${CC} ${CFLAGS} ${CHECKER_OBJS} ${LIBFT} ${INCLUDES} -o $@

.c.o:
	${CC} ${CFLAGS} $< -c ${INCLUDES} -o $@

clean:
	rm -f ${PUSH_SWAP_OBJS} ${CHECKER_OBJS}
	${MAKE} clean -C ${LIBFTDIR}

fclean: clean
	rm -f ${NAME} ${CHECKER_NAME}
	${MAKE} fclean -C ${LIBFTDIR}

re: fclean all


debug: CFLAGS += -g -fsanitize=address
debug: re

.PHONY: all bonus clean fclean re