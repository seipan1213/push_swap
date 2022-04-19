/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 18:34:39 by sehattor          #+#    #+#             */
/*   Updated: 2022/04/19 23:15:18 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "libft.h"

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
	t_dcl_lst *next;
	t_dcl_lst *prev;
} t_dcl_lst;

typedef struct s_push_swap
{
	long *ans;
} t_push_swap;

void put_err_exit(int exit_num);
void dcl_lst_addfront(t_dcl_lst *lst, long value);
void dcl_lst_addback(t_dcl_lst *lst, long value);
#endif
