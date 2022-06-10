/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 01:24:43 by sehattor          #+#    #+#             */
/*   Updated: 2022/06/11 01:39:15 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_stack(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	half_set_stack(a, b, ps);
	while (!is_sorted_lst(a, ps))
	{
		if (get_lst_size(b) <= MIN_SORT_NUM)
			sort_b(a, b, ps);
		while (get_lst_size(b) > 0)
			div_b_stack(a, b, ps);
		div_a_stack(a, b, ps);
		if (get_lst_size(ps->stack_size_lst) == 0 && get_lst_size(b) == 0)
			dcl_lst_addfront(ps->stack_size_lst, ps->lst_size - ps->next_want_index);
	}
}

void sort_b(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps) // 2行多い
{
	int pool_count;

	pool_count = 0;
	while (get_lst_size(b) > 0 || pool_count > 0)
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

void div_b_stack(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps) // 4行多い
{
	bool is_under;
	long selected_value;
	long b_mid;
	long stack_size;
	int check_size;

	b_mid = get_mid_value(b);
	check_size = get_lst_size(b);
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
