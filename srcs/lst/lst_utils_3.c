/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 01:23:58 by sehattor          #+#    #+#             */
/*   Updated: 2022/06/11 01:38:56 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long get_mid_value(t_dcl_lst *lst)
{
	long lst_ary[ARG_LIMIT + 10];
	t_dcl_lst *tmp_lst;
	int index;
	int mid_index;

	tmp_lst = get_first_lst(lst);
	ft_bzero(lst_ary, sizeof(long) * ARG_LIMIT + 10);
	index = 0;
	mid_index = index / 2;
	while (tmp_lst->value != NIL)
	{
		lst_ary[index] = tmp_lst->value;
		index++;
		tmp_lst = tmp_lst->next;
	}
	if (index > 0)
		index--;
	quick_sort(lst_ary, 0, index);
	mid_index = index / 2;
	return (lst_ary[mid_index]);
}

bool is_sorted_lst(t_dcl_lst *lst, t_push_swap *ps)
{
	int index;

	index = 0;
	lst = get_first_lst(lst);
	while (index < ps->lst_size)
	{
		if (lst->value != ps->sorted_lst[index])
			return false;
		lst = lst->next;
		index++;
	}
	return true;
}

void put_ans(t_push_swap *ps)
{

	t_dcl_lst *lst;
	lst = ps->ans;
	lst = get_first_lst(lst);
	while (lst->value != NIL)
	{
		put_cmd(lst->value);
		lst = lst->next;
	}
}

void put_cmd(int cmd)
{
	if (cmd == SA)
		ft_putendl_fd("sa", STDOUT_FILENO);
	else if (cmd == SB)
		ft_putendl_fd("sb", STDOUT_FILENO);
	else if (cmd == SS)
		ft_putendl_fd("ss", STDOUT_FILENO);
	else if (cmd == PA)
		ft_putendl_fd("pa", STDOUT_FILENO);
	else if (cmd == PB)
		ft_putendl_fd("pb", STDOUT_FILENO);
	else if (cmd == RA)
		ft_putendl_fd("ra", STDOUT_FILENO);
	else if (cmd == RB)
		ft_putendl_fd("rb", STDOUT_FILENO);
	else if (cmd == RR)
		ft_putendl_fd("rr", STDOUT_FILENO);
	else if (cmd == RRA)
		ft_putendl_fd("rra", STDOUT_FILENO);
	else if (cmd == RRB)
		ft_putendl_fd("rrb", STDOUT_FILENO);
	else if (cmd == RRR)
		ft_putendl_fd("rrr", STDOUT_FILENO);
}

void reduction_stack(t_dcl_lst *lst) // 大幅OVER
{
	lst = get_first_lst(lst);
	while (lst->value != NIL)
	{
		if ((lst->value == PA && lst->next->value == PB) ||
			(lst->value == PB && lst->next->value == PA))
		{
			lst = lst->prev;
			delete_lst(lst->next);
			delete_lst(lst->next);
		}
		else if ((lst->value == SA && lst->next->value == SB) ||
				 (lst->value == SB && lst->next->value == SA))
		{
			lst->value = SS;
			delete_lst(lst->next);
		}
		else if ((lst->value == RA && lst->next->value == RB) ||
				 (lst->value == RB && lst->next->value == RA))
		{
			lst->value = RR;
			delete_lst(lst->next);
		}
		else if ((lst->value == RRA && lst->next->value == RRB) ||
				 (lst->value == RRB && lst->next->value == RRA))
		{
			lst->value = RRR;
			delete_lst(lst->next);
		}
		lst = lst->next;
	}
}