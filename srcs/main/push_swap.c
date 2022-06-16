/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 01:25:04 by sehattor          #+#    #+#             */
/*   Updated: 2022/06/16 19:45:22 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push_swap	*ps_init(int argc, char **argv)
{
	t_push_swap	*ps;

	ps = malloc(sizeof(t_push_swap));
	ft_bzero(ps, sizeof(t_push_swap));
	if (!ps)
		put_err_exit(1);
	ps->lst_size = argc - 1;
	ps->now_sort_size = ps->lst_size;
	ps->want_i = 0;
	ps_init_lst(ps, argv + 1);
	ps->stack_size_lst = make_init_lst();
	ps->ans = make_init_lst();
	ps->tmp_ans = make_init_lst();
	ps->max_turn = MIN_LIMIT_SORT_CNT;
	return (ps);
}

void	ps_init_lst(t_push_swap *ps, char **lst)
{
	int	index;

	index = 0;
	while (index < ps->lst_size)
	{
		ps->sorted_lst[index] = ps_atol(lst[index]);
		index++;
	}
	quick_sort(ps->sorted_lst, 0, ps->lst_size - 1);
}

void	free_push_swap(t_push_swap *ps, t_dcl_lst *a, t_dcl_lst *b)
{
	clear_lst(a);
	clear_lst(b);
	clear_lst(ps->ans);
	clear_lst(ps->tmp_ans);
	clear_lst(ps->stack_size_lst);
	free(ps);
}

void	push_swap(int argc, char **argv)
{
	t_dcl_lst	*a;
	t_dcl_lst	*b;
	t_push_swap	*ps;

	a = make_lst(argc - 1, argv + 1);
	b = make_init_lst();
	ps = ps_init(argc, argv);
	if (is_sorted_lst(a))
	{
		free_push_swap(ps, a, b);
		return ;
	}
	if (get_lst_size(a) > 5)
		sort_stack(a, b, ps);
	else
		sort_min_stack(a, b, ps);
	reduction_stack(ps->ans);
	put_ans(ps);
	free_push_swap(ps, a, b);
}
