/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 01:24:18 by sehattor          #+#    #+#             */
/*   Updated: 2022/06/11 01:24:19 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool ra(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	(void)b;
	rab(a);
	dcl_lst_addback(ps->ans, RA);
	return (true);
}

bool rb(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	(void)a;
	rab(b);
	dcl_lst_addback(ps->ans, RB);
	return (true);
}

bool rr(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	rab(a);
	rab(b);
	dcl_lst_addback(ps->ans, RR);
	return (true);
}

bool rra(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	(void)b;
	rrab(a);
	dcl_lst_addback(ps->ans, RRA);
	return (true);
}

bool rrb(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	(void)a;
	rrab(b);
	dcl_lst_addback(ps->ans, RRB);
	return (true);
}
