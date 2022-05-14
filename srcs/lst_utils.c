#include "push_swap.h"

void dcl_lst_addfront(t_dcl_lst *lst, long value)
{
	t_dcl_lst *new;

	new = malloc(sizeof(t_dcl_lst));
	if (!new)
		put_err_exit(1);
	while (lst->value != NIL)
		lst = lst->next;
	new->value = value;
	new->next = lst->next;
	new->next->prev = new;
	new->prev = lst;
	lst->next = new;
}

void dcl_lst_addback(t_dcl_lst *lst, long value)
{
	t_dcl_lst *new;

	new = malloc(sizeof(t_dcl_lst));
	if (!new)
		put_err_exit(1);
	while (lst->value != NIL)
		lst = lst->next;
	new->value = value;
	new->prev = lst->prev;
	new->prev->next = new;
	new->next = lst;
	lst->prev = new;
}

t_dcl_lst *make_dcl_lst(int size, char **str)
{
	t_dcl_lst *lst;
	int index;

	index = 0;
	lst = make_init_dcl_lst();
	while (index < size)
	{
		dcl_lst_addback(lst, atol(str[index])); // TODO: ft_
		index++;
	}
	return lst;
}

t_dcl_lst *make_init_dcl_lst()
{
	t_dcl_lst *lst;

	lst = malloc(sizeof(t_dcl_lst));
	if (!lst)
		put_err_exit(1);
	lst->value = NIL;
	lst->next = lst;
	lst->prev = lst;
	return lst;
}

int dcl_lst_size(t_dcl_lst *lst)
{
	int index;

	while ((*lst).value != NIL)
		lst = lst->next;
	lst = lst->next;
	index = 0;
	while ((*lst).value != NIL)
	{
		lst = lst->next;
		index++;
	}
	return (index);
}

t_dcl_lst *get_first_lst(t_dcl_lst *lst)
{
	while (lst->value != NIL)
		lst = lst->next;
	lst = lst->next;
	return (lst);
}

t_dcl_lst *get_last_lst(t_dcl_lst *lst)
{
	while (lst->value != NIL)
		lst = lst->next;
	lst = lst->prev;
	return (lst);
}

long get_mid_value(t_dcl_lst *lst)
{
	long lst_ary[ARG_LIMIT + 10];
	t_dcl_lst *tmp_lst;
	int index;

	tmp_lst = get_first_lst(lst);
	ft_bzero(lst_ary, ARG_LIMIT + 10);
	index = 0;
	while (tmp_lst->value != NIL)
	{
		lst_ary[index] = tmp_lst->value;
		index++;
		tmp_lst = tmp_lst->next;
	}
	quick_sort(lst_ary, 0, index - 1);
	return (lst_ary[index / 2]);
}