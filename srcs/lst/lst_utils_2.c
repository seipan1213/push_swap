/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 01:24:01 by sehattor          #+#    #+#             */
/*   Updated: 2022/06/12 21:09:37 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dcl_lst	*get_first_lst(t_dcl_lst *lst)
{
	while (lst->value != NIL)
		lst = lst->next;
	lst = lst->next;
	return (lst);
}

t_dcl_lst	*get_last_lst(t_dcl_lst *lst)
{
	while (lst->value != NIL)
		lst = lst->next;
	lst = lst->prev;
	return (lst);
}

void	clear_lst(t_dcl_lst *lst)
{
	int	lst_size;
	int	index;

	lst_size = get_lst_size(lst) + 1;
	index = 0;
	while (index < lst_size)
	{
		delete_lst(lst->next);
		index++;
	}
}

void	reset_lst(t_dcl_lst *lst)
{
	int	lst_size;
	int	index;

	lst_size = get_lst_size(lst);
	lst = get_first_lst(lst)->prev;
	index = 0;
	while (index < lst_size)
	{
		delete_lst(lst->next);
		index++;
	}
}

void	delete_lst(t_dcl_lst *lst)
{
	t_dcl_lst	*prev;
	t_dcl_lst	*next;

	prev = lst->prev;
	next = lst->next;
	prev->next = next;
	next->prev = prev;
	free(lst);
}
