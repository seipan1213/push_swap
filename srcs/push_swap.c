#include "push_swap.h"

void sort_stack(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	half_set_stack(a, b, ps);
	while (!is_sorted_lst(a, ps))
	{
		if (dcl_lst_size(b) <= MIN_SORT_NUM)
			sort_b(a, b, ps);
		while (dcl_lst_size(b) > 0)
			div_b_stack(a, b, ps);
		div_a_stack(a, b, ps);
		if (dcl_lst_size(ps->stack_size_lst) == 0 && dcl_lst_size(b) == 0)
			dcl_lst_addfront(ps->stack_size_lst, ps->lst_size - ps->next_want_index);
	}
}

void sort_b(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	int pool_count;

	pool_count = 0;
	while (dcl_lst_size(b) > 0 || pool_count > 0)
	{
		if (get_first_lst(b)->value == ps->sorted_lst[ps->next_want_index])
		{
			pa(a, b, ps);
			ra(a, b, ps);
			ps->next_want_index++;
		}
		else if (get_first_lst(a)->value == ps->sorted_lst[ps->next_want_index])
		{
			ra(a, b, ps);
			pool_count--;
			ps->next_want_index++;
		}
		else if (get_first_lst(b)->value < get_first_lst(a)->value || pool_count <= 0)
		{
			pa(a, b, ps);
			pool_count++;
		}
		else if (get_last_lst(b)->value == ps->sorted_lst[ps->next_want_index])
			rrb(a, b, ps);
		else
			rb(a, b, ps);
	}
}

void half_set_stack(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	long mid;
	int index;

	index = 0;
	mid = get_mid_value(a);
	while (index < ps->now_sort_size)
	{
		if (get_first_lst(a)->value <= mid)
			pb(a, b, ps);
		else
			ra(a, b, ps);
		index++;
	}
}

void div_a_stack(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	long selected_value;
	t_dcl_lst *stack_size_first;

	stack_size_first = get_first_lst(ps->stack_size_lst);
	while (stack_size_first->value > 0)
	{
		selected_value = get_first_lst(a)->value;
		if (selected_value == ps->sorted_lst[ps->next_want_index])
		{
			ra(a, b, ps);
			ps->next_want_index++;
		}
		else
			pb(a, b, ps);
		stack_size_first->value--;
	}
	if (stack_size_first->value != NIL)
		delete_lst(stack_size_first);
}

void div_b_stack(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	bool is_under;
	long selected_value;
	long b_mid;
	long stack_size;
	int check_size;

	b_mid = get_mid_value(b);
	check_size = dcl_lst_size(b);
	stack_size = 0;
	while (check_size > 0)
	{
		selected_value = get_first_lst(b)->value;
		is_under = selected_value <= b_mid;
		if (selected_value == ps->sorted_lst[ps->next_want_index])
		{
			pa(a, b, ps);
			ra(a, b, ps);
			ps->next_want_index++;
		}
		else if (is_under)
			rb(a, b, ps);
		else
		{
			pa(a, b, ps);
			stack_size++;
		}
		check_size--;
	}
	dcl_lst_addfront(ps->stack_size_lst, stack_size);
}

void move_a_stack(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	int index;

	index = 0;
	while (index < ps->now_sort_size)
	{
		pb(a, b, ps);
		index++;
	}
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

void reduction_stack(t_dcl_lst *lst)
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

void update_ans(t_push_swap *ps, long turn)
{
	int ans_size;
	t_dcl_lst *tmp_ans;

	if (ps->max_turn <= turn)
		return;
	ps->max_turn = turn;
	reset_lst(ps->ans);
	ans_size = dcl_lst_size(ps->tmp_ans);
	tmp_ans = get_first_lst(ps->tmp_ans);
	while (ans_size > 0)
	{
		dcl_lst_addback(ps->ans, tmp_ans->value);
		tmp_ans = tmp_ans->next;
		ans_size--;
	}
}

void sort_min_stack(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	sort_dfs(a, b, ps, 0);
}

bool check_avoid_cmd(t_push_swap *ps, int cmd)
{
	t_dcl_lst *last;

	last = get_last_lst(ps->tmp_ans);
	if (last->value == PA && cmd == PB)
		return (true);
	if (last->value == PB && cmd == PA)
		return (true);
	if (last->value == RA && cmd == RRA)
		return (true);
	if (last->value == RB && cmd == RRB)
		return (true);
	if (last->value == RR && cmd == RRR)
		return (true);
	if (last->value == RRA && cmd == RA)
		return (true);
	if (last->value == RRB && cmd == RB)
		return (true);
	if (last->value == RRR && cmd == RR)
		return (true);
	if (last->value == SA && cmd == SA)
		return (true);
	if (last->value == SB && cmd == SB)
		return (true);
	if (last->value == SS && cmd == SS)
		return (true);
	return (false);
}

void sort_dfs(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps, long turn)
{
	int cmd;

	cmd = -1;
	if (turn >= ps->max_turn)
		return;
	if (dcl_lst_size(b) == 0 && is_sorted_lst(a, ps))
	{
		update_ans(ps, turn);
		return;
	}
	while (cmd++ < 11)
	{
		if (check_avoid_cmd(ps, cmd))
			continue;
		only_run_cmd(a, b, cmd, true);
		dcl_lst_addback(ps->tmp_ans, cmd);
		sort_dfs(a, b, ps, turn + 1);
		only_run_cmd(a, b, cmd, false);
		delete_lst(get_last_lst(ps->tmp_ans));
	}
}

void only_run_cmd(t_dcl_lst *a, t_dcl_lst *b, int cmd, bool type)
{
	if (type)
		run_cmd(a, b, cmd);
	else
		run_r_cmd(a, b, cmd);
}

void run_cmd(t_dcl_lst *a, t_dcl_lst *b, int cmd)
{
	if (cmd == SA)
		sab(a);
	if (cmd == SB)
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
	if (cmd == SA)
		sab(a);
	if (cmd == SB)
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