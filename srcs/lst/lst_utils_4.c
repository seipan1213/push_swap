/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 22:35:04 by sehattor          #+#    #+#             */
/*   Updated: 2022/06/12 22:39:08 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reduction_cmd(t_dcl_lst **lst)
{
	if (((*lst)->value == PA && (*lst)->next->value == PB)
		|| ((*lst)->value == PB && (*lst)->next->value == PA))
	{
		(*lst) = (*lst)->prev;
		delete_lst((*lst)->next);
		delete_lst((*lst)->next);
	}
	else if (((*lst)->value == SA && (*lst)->next->value == SB)
		|| ((*lst)->value == SB && (*lst)->next->value == SA))
	{
		(*lst)->value = SS;
		delete_lst((*lst)->next);
	}
	else if (((*lst)->value == RA && (*lst)->next->value == RB)
		|| ((*lst)->value == RB && (*lst)->next->value == RA))
	{
		(*lst)->value = RR;
		delete_lst((*lst)->next);
	}
	else if (((*lst)->value == RRA && (*lst)->next->value == RRB)
		|| ((*lst)->value == RRB && (*lst)->next->value == RRA))
	{
		(*lst)->value = RRR;
		delete_lst((*lst)->next);
	}
}
