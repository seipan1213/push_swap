/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 18:34:47 by sehattor          #+#    #+#             */
/*   Updated: 2022/04/17 20:43:44 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool input_check(int argc, char **argv)
{
	if (argc == 1)
		return (false);
	return (true);
}

t_dcl_lst *make_lst()
{
	t_dcl_lst *lst;

	lst = malloc(sizeof(t_dcl_lst));
	if (!lst)
		put_err_exit(1);
	lst->value = 0;
	lst->next = NULL;
	lst->prev = NULL;
	return lst;
}

t_dcl_lst *make_init_lst()
{
	t_dcl_lst *lst;

	lst = malloc(sizeof(t_dcl_lst));
	if (!lst)
		put_err_exit(1);
	lst->value = 0;
	lst->next = NULL;
	lst->prev = NULL;
	return lst;
}

void push_swap()
{
	t_dcl_lst *a;
	t_dcl_lst *b;

	a = make_lst();
	b = make_init_lst();
}

int main(int argc, char **argv)
{
	if (!input_check(argc, argv))
		return;
	push_swap();
}