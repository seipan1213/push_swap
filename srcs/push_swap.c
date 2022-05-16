#include "push_swap.h"

void sort_stack(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	div_a_stack(a, b, ps);
	div_b_stack(a, b, ps);
	while (!is_sorted_lst(a, ps))
	{
		move_a_stack(a, b, ps);
		div_b_stack(a, b, ps);
	}
	// bを半分にしつづけて4要素以下になったらソートをする
	// 50 -> 25 -> 13 -> 7 -> 4
	//                     -> 3
	//                -> 6 -> 3
	//                     -> 3
	//          -> 12 -> 6 -> 3
	//                     -> 3
	//                -> 6 -> 3
	//                     -> 3
	//    -> 25 -> 13 -> 7 -> 4
	//                     -> 3
	//                -> 6 -> 3
	//                     -> 3
	//          -> 12 -> 6 -> 3
	//                     -> 3
	//                -> 6 -> 3
	//                     -> 3
}

void div_a_stack(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
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
	ps->now_sort_size = div_up(ps->now_sort_size, 2);
}

void div_b_stack(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	bool is_sort;
	long selected_value;
	int init_lst_size;
	long b_mid;

	b_mid = get_mid_value(b);
	init_lst_size = dcl_lst_size(b);
	while (dcl_lst_size(b) > 0)
	{
		selected_value = get_first_lst(b)->value;
		is_sort = selected_value <= b_mid || init_lst_size <= MIN_SORT_NUM;
		if (selected_value == ps->sorted_lst[ps->next_want_index])
		{
			pa(a, b, ps);
			ra(a, b, ps);
			ps->next_want_index++;
			ps->now_sort_size--;
		}
		if (is_sort)
			rb(a, b, ps);
		else
			pa(a, b, ps);
	}
	if (init_lst_size <= MIN_SORT_NUM)
		ps->now_sort_size = ps->lst_size / 2;
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