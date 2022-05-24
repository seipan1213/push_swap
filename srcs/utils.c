#include "push_swap.h"

void put_err_exit(int exit_num)
{
	ft_putendl_fd("ERROR\n", STDOUT_FILENO);
	exit(exit_num);
}

int div_up(int num, int div_num)
{
	return ((num + 1) / div_num);
}

void put_dcl_lst(t_dcl_lst *lst)
{
	while (lst->value != NIL)
		lst = lst->next;
	while (lst->value != NIL)
	{
		printf("%ld\n", lst->value);
		lst = lst->next;
	}
	printf("\n");
}

void put_arr(long values[], int size)
{
	int index;

	index = 0;
	while (index < size)
	{
		printf("%ld\n", values[index]);
		index++;
	}
	printf("\n");
}