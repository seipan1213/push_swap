#include "push_swap.h"

void sort_stack(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	if (is_sorted_lst(a, ps))
		return;
	div_a_stack(a, b, ps);
	div_b_stack(a, b, ps);
	while (!is_sorted_lst(a, ps))
	{
		move_a_stack(a, b, ps);
		div_b_stack(a, b, ps);
	}
	put_dcl_lst(a);

	// Bスタックのサイズを図って、基準値の上下で判定をして半分をAスタックの先頭に、もう半分を順序通りに末尾に
	// Bの半分を判断するためにPSに今分割中のスタックの数を記録　200個の要素の場合: 100->50->25->13->7->4 こんな感じで半分にして 4個になったら もう半分を処理する
	// 上記 カウントがなければ、Aから半分にする
	// 判断の基準値は、それぞれのスタックを適宜ソートして中央値をとる
}

void div_a_stack(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	long mid;
	int index;

	index = 0;
	mid = get_mid_value(a);
	while (index < ps->now_sort_size)
	{
		if (get_first_lst(a)->value < mid)
			pb(a, b, ps);
		else
			rra(a, b, ps);
		index++;
	}
	ps->now_sort_size /= 2;
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
		is_sort = selected_value < b_mid || init_lst_size < 5;
		if (selected_value == ps->sorted_lst[ps->next_want_index])
		{
			pa(a, b, ps);
			rra(a, b, ps);
			ps->next_want_index++;
			ft_putnbr_fd(ps->next_want_index, STDOUT_FILENO);
		}
		if (is_sort)
			rrb(a, b, ps);
		else
			pa(a, b, ps);
	}
	if (init_lst_size < 5)
		ps->now_sort_size = ps->lst_size / 2;
	else
		ps->now_sort_size /= 2;
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