/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 18:34:39 by sehattor          #+#    #+#             */
/*   Updated: 2022/05/16 21:28:16 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "libft.h"

#define NIL -3000000000
#define ARG_LIMIT 1000
#define MIN_SORT_NUM 3

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
	long sorted_lst[ARG_LIMIT + 10];
	int next_want_index;
	int lst_size;
	int now_sort_size;
	t_dcl_lst *ans;
} t_push_swap;

void put_err_exit(int exit_num);
void put_dcl_lst(t_dcl_lst *lst);
void put_arr(long values[], int size);
int div_up(int num, int div_num);

void dcl_lst_addfront(t_dcl_lst *lst, long value);
void dcl_lst_addback(t_dcl_lst *lst, long value);
t_dcl_lst *make_dcl_lst(int size, char **str);
t_dcl_lst *make_init_dcl_lst();
void ps_init_lst(t_push_swap *ps, char **lst);
void push_swap(int argc, char **argv);
int dcl_lst_size(t_dcl_lst *lst);
t_dcl_lst *get_first_lst(t_dcl_lst *lst);
t_dcl_lst *get_last_lst(t_dcl_lst *lst);
void delete_lst(t_dcl_lst *lst);
long get_mid_value(t_dcl_lst *lst);

void quick_sort(long arr[], int left, int right);

void sort_stack(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps);
void move_a_stack(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps);
void div_a_stack(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps);
void div_b_stack(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps);
bool is_sorted_lst(t_dcl_lst *lst, t_push_swap *ps);
void reduction_stack(t_dcl_lst *lst);

void put_ans(t_push_swap *ps);
void put_cmd(int cmd);

bool sab(t_dcl_lst *a);
bool pab(t_dcl_lst *a, t_dcl_lst *b);
bool rab(t_dcl_lst *a);
bool rrab(t_dcl_lst *a);

bool sa(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps);
bool sb(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps);
bool ss(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps);
bool pa(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps);
bool pb(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps);
bool ra(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps);
bool rb(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps);
bool rr(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps);
bool rra(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps);
bool rrb(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps);
bool rrr(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps);

void put_stack(t_dcl_lst *a, t_dcl_lst *b);
#endif
