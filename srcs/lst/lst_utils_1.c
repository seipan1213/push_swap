/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 01:24:04 by sehattor          #+#    #+#             */
/*   Updated: 2022/06/12 21:09:01 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dcl_lst_addfront(t_dcl_lst *lst, long value)
{
	t_dcl_lst	*new;

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

void	dcl_lst_addback(t_dcl_lst *lst, long value)
{
	t_dcl_lst	*new;

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

t_dcl_lst	*make_lst(int size, char **str)
{
	t_dcl_lst	*lst;
	int			index;

	index = 0;
	lst = make_init_lst();
	while (index < size)
	{
		dcl_lst_addback(lst, ps_atol(str[index]));
		index++;
	}
	return (lst);
}

t_dcl_lst	*make_init_lst(void)
{
	t_dcl_lst	*lst;

	lst = malloc(sizeof(t_dcl_lst));
	if (!lst)
		put_err_exit(1);
	lst->value = NIL;
	lst->next = lst;
	lst->prev = lst;
	return (lst);
}

int	get_lst_size(t_dcl_lst *lst)
{
	int	index;

	while (lst->value != NIL)
		lst = lst->next;
	lst = lst->next;
	index = 0;
	while (lst->value != NIL)
	{
		lst = lst->next;
		index++;
	}
	return (index);
}
