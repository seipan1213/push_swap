#include "push_swap.h"

void dcl_lst_addfront(t_dcl_lst *lst, long value)
{
	t_dcl_lst *new;

	new = malloc(sizeof(t_dcl_lst));
	if (!new)
		put_err_exit(1);
	while (lst->value != NULL)
		lst = lst->next;
	new->value = value;
	new->next = lst->next;
	new->prev = lst;
	lst->next = new;
}

void dcl_lst_addback(t_dcl_lst *lst, long value)
{
	t_dcl_lst *new;

	new = malloc(sizeof(t_dcl_lst));
	if (!new)
		put_err_exit(1);
	while (lst->value != NULL)
		lst = lst->next;
	new->value = value;
	new->prev = lst->prev;
	new->next = lst;
	lst->prev = new;
}