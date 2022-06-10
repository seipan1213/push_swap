/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min_stack_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 01:24:39 by sehattor          #+#    #+#             */
/*   Updated: 2022/06/11 01:24:40 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void only_run_cmd(t_dcl_lst *a, t_dcl_lst *b, int cmd, bool type)
{
	if (type)
		run_cmd(a, b, cmd);
	else
		run_r_cmd(a, b, cmd);
}

void run_cmd(t_dcl_lst *a, t_dcl_lst *b, int cmd)
{
	if (cmd == SA || cmd == SS)
		sab(a);
	if (cmd == SB || cmd == SS)
		sab(b);
	if (cmd == PA)
		pab(a, b);
	if (cmd == PB)
		pab(b, a);
	if (cmd == RA || cmd == RR)
		rab(a);
	if (cmd == RB || cmd == RR)
		rab(b);
	if (cmd == RRA || cmd == RRR)
		rrab(a);
	if (cmd == RRB || cmd == RRR)
		rrab(b);
}

void run_r_cmd(t_dcl_lst *a, t_dcl_lst *b, int cmd)
{
	if (cmd == SA || cmd == SS)
		sab(a);
	if (cmd == SB || cmd == SS)
		sab(b);
	if (cmd == PA)
		pab(b, a);
	if (cmd == PB)
		pab(a, b);
	if (cmd == RA || cmd == RR)
		rrab(a);
	if (cmd == RB || cmd == RR)
		rrab(b);
	if (cmd == RRA || cmd == RRR)
		rab(a);
	if (cmd == RRB || cmd == RRR)
		rab(b);
}