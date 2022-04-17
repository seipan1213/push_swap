#include "push_swap.h"

void	put_err_exit(int exit_num)
{
	ft_putendl_fd("ERROR\n",STDOUT_FILENO);
	exit(exit_num);
}