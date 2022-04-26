/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 18:34:47 by sehattor          #+#    #+#             */
/*   Updated: 2022/04/26 13:03:59 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool input_check(int argc, char **argv)
{
	if (argc == 1)
		return (false);
	return (true);
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