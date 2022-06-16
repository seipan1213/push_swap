/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 01:24:43 by sehattor          #+#    #+#             */
/*   Updated: 2022/06/16 19:45:22 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	half_set_stack(a, b, ps);
	while (!is_sorted_lst(a) || get_lst_size(b) !=0)
	{
		if (get_lst_size(b) <= MIN_SORT_NUM)
			sort_b(a, b, ps);
		while (get_lst_size(b) > MIN_SORT_NUM)
			div_b_stack(a, b, ps);
		if (get_lst_size(b) == 0)
			div_a_stack(a, b, ps);
		if (get_lst_size(ps->stack_size_lst) == 0
			&& get_lst_size(b) == 0)
			dcl_lst_addfront(ps->stack_size_lst,
				ps->lst_size - ps->want_i);
	}
}

void	sort_b(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	int	pool_count;

	pool_count = 0;
	while (get_lst_size(b) > 0 || pool_count > 0)
	{
		if (get_first_lst(a)->value == ps->sorted_lst[ps->want_i])
		{
			ra(a, b, ps);
			pool_count--;
			ps->want_i++;
		}
		else if (get_first_lst(b)->value == ps->sorted_lst[ps->want_i]
			|| get_first_lst(b)->value < get_first_lst(a)->value
			|| pool_count <= 0)
		{
			pa(a, b, ps);
			pool_count++;
		}
		else if (get_last_lst(b)->value == ps->sorted_lst[ps->want_i])
			rrb(a, b, ps);
		else
			rb(a, b, ps);
	}
}

void	half_set_stack(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	long	mid;
	int		index;
	int		end_size;

	index = 0;
	mid = get_mid_value(a);
	end_size = get_lst_size(a) / 2 + get_lst_size(a) % 2;
	while (index < ps->now_sort_size)
	{
		if (get_first_lst(a)->value <= mid)
			pb(a, b, ps);
		else
		{
			if (get_first_lst(b)->value < get_mid_value(b))
				rr(a, b, ps);
			else
				ra(a, b, ps);
		}
		if (end_size <= get_lst_size(b))
			break ;
		index++;
	}
}

void	div_a_stack(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	t_dcl_lst	*stack_size_first;

	stack_size_first = get_first_lst(ps->stack_size_lst);
	while (stack_size_first->value > 0)
	{
		if (get_first_lst(a)->value == ps->sorted_lst[ps->want_i])
		{
			if (get_first_lst(b)->value < get_mid_value(b))
				rr(a, b, ps);
			else
				ra(a, b, ps);
			ps->want_i++;
		}
		else if ((get_first_lst(a)->next->value == ps->sorted_lst[ps->want_i])
			&& (get_first_lst(a)->value == ps->sorted_lst[ps->want_i + 1]))
		{
			sa(a, b, ps);
			continue ;
		}
		else
			pb(a, b, ps);
		stack_size_first->value--;
	}
	if (stack_size_first->value != NIL)
		delete_lst(stack_size_first);
}

void	div_b_stack(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	long	b_mid;
	int		upper_size;

	b_mid = get_mid_value(b);
	upper_size = get_lst_size(b) / 2;
	dcl_lst_addfront(ps->stack_size_lst, 0);
	while (upper_size > 0)
	{
		if (!(get_first_lst(b)->value <= b_mid))
			upper_size--;
		if (get_first_lst(b)->value == ps->sorted_lst[ps->want_i])
		{
			pa(a, b, ps);
			ra(a, b, ps);
			ps->want_i++;
		}
		else if (get_first_lst(b)->value <= b_mid)
			rb(a, b, ps);
		else
		{
			pa(a, b, ps);
			get_first_lst(ps->stack_size_lst)->value++;
		}
	}
}
