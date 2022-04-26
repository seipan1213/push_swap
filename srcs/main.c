/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 18:34:47 by sehattor          #+#    #+#             */
/*   Updated: 2022/04/26 15:14:19 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool input_check(int argc, char **argv)
{
	if (argc == 1)
		return (false);
	return (true);
}

t_push_swap *ps_init(int argc, char **argv)
{
	t_push_swap *ps;

	ps = malloc(sizeof(t_push_swap));
	if (!ps)
		put_err_exit(1);
	ps->lst_size = argc - 1;
	ps_init_lst(ps, argv + 1);
}

void ps_init_lst(t_push_swap *ps, char **lst)
{
	int index;

	index = 0;
	while (index < ps->lst_size)
	{
		ps->lst[index] = atol(lst[index]);		  // TODO: ft_
		ps->sorted_lst[index] = atol(lst[index]); // TODO: ft_
		index++;
	}
	quick_sort(ps->sorted_lst, 0, ps->lst_size);
}

void push_swap(int argc, char **argv)
{
	t_dcl_lst *a;
	t_dcl_lst *b;
	t_push_swap *ps;

	a = make_dcl_lst(argc - 1, *argv + 1);
	b = make_init_dcl_lst();
	ps = init_ps(argc, argv);
}

int main(int argc, char **argv)
{
	if (!input_check(argc, *argv))
		return;
	push_swap(argc, *argv);
}