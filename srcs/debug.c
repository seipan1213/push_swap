#include "push_swap.h"

void put_dcl_lst(t_dcl_lst *lst)
{
	lst = lst->next;
	while (lst->value != NIL)
	{
		printf("%ld\n", lst->value);
		lst = lst->next;
	}
}

int main(int argc, char **argv)
{
	t_dcl_lst *lst = make_dcl_lst(argc, argv);
	sa(lst);
	sa(lst);
	put_dcl_lst(lst);
}
