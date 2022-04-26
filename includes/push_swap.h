/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 18:34:39 by sehattor          #+#    #+#             */
/*   Updated: 2022/04/26 14:54:36 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "libft.h"

#define NIL -3000000000
#define ARG_LIMIT 5000

typedef enum e_cmd
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
} t_cmd;

typedef struct s_dcl_lst
{
	long value;
	struct s_dcl_lst *next;
	struct s_dcl_lst *prev;
} t_dcl_lst;

typedef struct s_push_swap
{
	long lst[ARG_LIMIT + 10];
	long sorted_lst[ARG_LIMIT + 10];
	size_t lst_size;
} t_push_swap;

void put_err_exit(int exit_num);
void dcl_lst_addfront(t_dcl_lst *lst, long value);
void dcl_lst_addback(t_dcl_lst *lst, long value);
t_dcl_lst *make_dcl_lst(int size, char **str);
t_dcl_lst *make_init_dcl_lst();

void quick_sort(long arr[], int left, int right);

#endif
