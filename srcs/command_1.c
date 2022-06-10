/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 01:24:20 by sehattor          #+#    #+#             */
/*   Updated: 2022/06/11 01:24:22 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool sa(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	(void)b;
	sab(a);
	dcl_lst_addback(ps->ans, SA);
	return (true);
}

bool sb(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	(void)a;
	sab(b);
	dcl_lst_addback(ps->ans, SB);
	return (true);
}

bool ss(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	sab(a);
	sab(b);
	dcl_lst_addback(ps->ans, SS);
	return (true);
}

bool pa(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	if (pab(a, b))
		dcl_lst_addback(ps->ans, PA);
	return (true);
}

bool pb(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	if (pab(b, a))
		dcl_lst_addback(ps->ans, PB);
	return (true);
}