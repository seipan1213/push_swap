/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 18:34:47 by sehattor          #+#    #+#             */
/*   Updated: 2022/06/09 01:08:08 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool same_arg(int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
			{
				return (true);
			}
			j++;
		}
		i++;
	}
	return (false);
}

bool input_check(int argc, char **argv)
{
	if (argc == 1)
		return (false);
	else if (same_arg(argc, argv))
		return (false);
	return (true);
}

t_push_swap *ps_init(int argc, char **argv)
{
	t_push_swap *ps;

	ps = malloc(sizeof(t_push_swap));
	ft_bzero(ps, sizeof(t_push_swap));
	if (!ps)
		put_err_exit(1);
	ps->lst_size = argc - 1;
	ps->now_sort_size = ps->lst_size;
	ps->next_want_index = 0;
	ps_init_lst(ps, argv + 1);
	ps->stack_size_lst = make_init_dcl_lst();
	ps->ans = make_init_dcl_lst();
	ps->tmp_ans = make_init_dcl_lst();
	ps->max_turn = 4;
	return (ps);
}

void ps_init_lst(t_push_swap *ps, char **lst)
{
	int index;

	index = 0;
	while (index < ps->lst_size)
	{
		ps->sorted_lst[index] = atol(lst[index]); // TODO: ft_
		index++;
	}
	quick_sort(ps->sorted_lst, 0, ps->lst_size - 1);
}

void free_push_swap(t_push_swap *ps, t_dcl_lst *a, t_dcl_lst *b)
{
	clear_lst(a);
	clear_lst(b);
	clear_lst(ps->ans);
	clear_lst(ps->tmp_ans);
	clear_lst(ps->stack_size_lst);
	free(ps);
}

void push_swap(int argc, char **argv)
{
	t_dcl_lst *a;
	t_dcl_lst *b;
	t_push_swap *ps;

	a = make_dcl_lst(argc - 1, argv + 1);
	b = make_init_dcl_lst();
	ps = ps_init(argc, argv);
	if (is_sorted_lst(a, ps))
	{
		free_push_swap(ps, a, b);
		return;
	}
	if (dcl_lst_size(a) > 5)
		sort_stack(a, b, ps);
	else
		sort_min_stack(a, b, ps);
	reduction_stack(ps->ans);
	put_ans(ps);
	free_push_swap(ps, a, b);
}

int main(int argc, char **argv)
{
	if (!input_check(argc, argv))
		return (0);
	push_swap(argc, argv);
}