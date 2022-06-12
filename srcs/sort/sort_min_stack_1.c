/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min_stack_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 01:24:36 by sehattor          #+#    #+#             */
/*   Updated: 2022/06/12 22:42:25 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_min_stack(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	sort_dfs(a, b, ps, 0);
}

void	update_ans(t_push_swap *ps, long turn)
{
	int			ans_size;
	t_dcl_lst	*tmp_ans;

	if (ps->max_turn <= turn)
		return ;
	ps->max_turn = turn;
	reset_lst(ps->ans);
	ans_size = get_lst_size(ps->tmp_ans);
	tmp_ans = get_first_lst(ps->tmp_ans);
	while (ans_size > 0)
	{
		dcl_lst_addback(ps->ans, tmp_ans->value);
		tmp_ans = tmp_ans->next;
		ans_size--;
	}
}

bool	check_avoid_cmd(int cmd, int pre)
{
	if (cmd == PA && pre == PB)
		return (true);
	if (cmd == PB && pre == PA)
		return (true);
	if (cmd == RA && (pre == RRA || pre == RRR))
		return (true);
	if (cmd == RB && (pre == RRB || pre == RRR))
		return (true);
	if (cmd == RR && (pre == RRA || pre == RRB || pre == RRR))
		return (true);
	if (cmd == RRA && (pre == RA || pre == RR))
		return (true);
	if (cmd == RRB && (pre == RB || pre == RR))
		return (true);
	if (cmd == RRR && (pre == RA || pre == RB || pre == RR))
		return (true);
	if (cmd == SA && (pre == SA || pre == SS))
		return (true);
	if (cmd == SB && (pre == SB || pre == SS))
		return (true);
	if (cmd == SS && (pre == SA || pre == SB || pre == SS))
		return (true);
	return (false);
}

bool	cant_cmd(t_dcl_lst *a, t_dcl_lst *b, int cmd)
{
	if (cmd == PA && get_lst_size(b) == 0)
		return (true);
	if (cmd == PB && get_lst_size(a) == 0)
		return (true);
	if ((cmd == SA || cmd == RA || cmd == RRA || cmd == RR || cmd == RRR)
		&& get_lst_size(a) <= 1)
		return (true);
	if ((cmd == SB || cmd == RB || cmd == RRB || cmd == RR || cmd == RRR)
		&& get_lst_size(b) <= 1)
		return (true);
	return (false);
}

void	sort_dfs(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps, long turn)
{
	int	cmd;

	cmd = -1;
	if (turn >= ps->max_turn)
		return ;
	if (get_lst_size(b) == 0 && is_sorted_lst(a, ps))
	{
		update_ans(ps, turn);
		return ;
	}
	while (cmd++ < 11)
	{
		if (check_avoid_cmd(cmd, get_last_lst(ps->tmp_ans)->value)
			|| cant_cmd(a, b, cmd) || turn >= ps->max_turn)
			continue ;
		only_run_cmd(a, b, cmd, true);
		dcl_lst_addback(ps->tmp_ans, cmd);
		sort_dfs(a, b, ps, turn + 1);
		only_run_cmd(a, b, cmd, false);
		delete_lst(get_last_lst(ps->tmp_ans));
	}
}
