/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_org.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 01:24:09 by sehattor          #+#    #+#             */
/*   Updated: 2022/06/11 01:24:10 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool sab(t_dcl_lst *a)
{
	long tmp;
	int size;

	size = dcl_lst_size(a);
	if (size <= 1)
		return (false);
	a = a->next;
	tmp = a->value;
	a->value = a->next->value;
	a->next->value = tmp;
	return (true);
}

bool pab(t_dcl_lst *a, t_dcl_lst *b)
{
	t_dcl_lst *b_front;

	b_front = get_first_lst(b);
	if (b_front->value == NIL)
		return (false);
	b_front->next->prev = b_front->prev;
	b_front->prev->next = b_front->next;
	b_front->prev = a;
	b_front->next = a->next;
	a->next = b_front;
	b_front->next->prev = b_front;
	return (true);
}

bool rab(t_dcl_lst *a)
{
	t_dcl_lst *a_front;
	t_dcl_lst *a_back;

	a_front = get_first_lst(a);
	a_back = get_last_lst(a);
	if (a_front == a_back)
		return (true);
	a->next = a_front->next;
	a->prev = a_front;
	a->prev->next = a;
	a->next->prev = a;
	a_back->next = a_front;
	a_front->prev = a_back;
	return (true);
}

bool rrab(t_dcl_lst *a)
{
	t_dcl_lst *a_front;
	t_dcl_lst *a_back;

	a_front = get_first_lst(a);
	a_back = get_last_lst(a);
	if (a_front == a_back)
		return (true);
	a->next = a_back;
	a->prev = a_back->prev;
	a->prev->next = a;
	a->next->prev = a;
	a_back->next = a_front;
	a_front->prev = a_back;
	return (true);
}