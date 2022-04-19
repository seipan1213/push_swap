/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 18:34:47 by sehattor          #+#    #+#             */
/*   Updated: 2022/04/19 23:17:54 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool input_check(int argc, char **argv)
{
	if (argc == 1)
		return (false);
	return (true);
}

t_dcl_lst *make_dcl_lst(int size, char **str)
{
	t_dcl_lst *lst;
	int index;

	index = 0;
	lst = make_init_dcl_lst();
	while (index < size)
	{
		dcl_lst_addback(lst, atol(str[index]));
		index++;
	}
	return lst;
}

t_dcl_lst *make_init_dcl_lst()
{
	t_dcl_lst *lst;

	lst = malloc(sizeof(t_dcl_lst));
	if (!lst)
		put_err_exit(1);
	lst->value = 0;
	lst->next = lst;
	lst->prev = lst;
	return lst;
}

void push_swap(int argc, char **argv)
{
	t_dcl_lst *a;
	t_dcl_lst *b;

	a = make_dcl_lst(argc, argv);
	b = make_init_dcl_lst();
}

int main(int argc, char **argv)
{
	if (!input_check(argc, argv))
		return;
	push_swap();
}