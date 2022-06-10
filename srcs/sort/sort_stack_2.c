/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 01:24:46 by sehattor          #+#    #+#             */
/*   Updated: 2022/06/11 01:24:46 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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