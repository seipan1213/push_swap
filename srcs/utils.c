#include "push_swap.h"

void put_err_exit(int exit_num)
{
	ft_putendl_fd("ERROR\n", STDOUT_FILENO);
	exit(exit_num);
}

void put_dcl_lst(t_dcl_lst *lst)
{
	lst = lst->next;
	while (lst->value != NIL)
	{
		printf("%ld\n", lst->value);
		lst = lst->next;
	}
	printf("\n");
}