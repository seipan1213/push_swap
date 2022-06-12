/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 18:34:39 by sehattor          #+#    #+#             */
/*   Updated: 2022/06/12 23:58:06 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define NIL -3000000000
# define ARG_LIMIT 1000
# define MIN_SORT_NUM 4
# define MIN_LIMIT_SORT_CNT 12

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
}						t_cmd;

typedef struct s_dcl_lst
{
	long				value;
	struct s_dcl_lst	*next;
	struct s_dcl_lst	*prev;
}						t_dcl_lst;

typedef struct s_push_swap
{
	long				sorted_lst[ARG_LIMIT + 10];
	int					want_i;
	int					lst_size;
	int					now_sort_size;
	t_dcl_lst			*stack_size_lst;
	t_dcl_lst			*ans;
	long				max_turn;
	t_dcl_lst			*tmp_ans;
}						t_push_swap;

/* push_swap */
t_push_swap				*ps_init(int argc, char **argv);
void					ps_init_lst(t_push_swap *ps, char **lst);
void					free_push_swap(t_push_swap *ps, t_dcl_lst *a,
							t_dcl_lst *b);
void					push_swap(int argc, char **argv);

/* quick_sort */
void					long_swap(long *la, long *lb);
void					quick_sort(long *arr, int left, int right);

/* sort_stack */
void					sort_stack(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps);
void					sort_b(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps);
void					half_set_stack(t_dcl_lst *a, t_dcl_lst *b,
							t_push_swap *ps);
void					div_a_stack(t_dcl_lst *a, t_dcl_lst *b,
							t_push_swap *ps);
void					div_b_stack(t_dcl_lst *a, t_dcl_lst *b,
							t_push_swap *ps);

/* sort_min_stack */
void					sort_min_stack(t_dcl_lst *a, t_dcl_lst *b,
							t_push_swap *ps);
void					update_ans(t_push_swap *ps, long turn);
bool					check_avoid_cmd(int cmd, int pre);
bool					cant_cmd(t_dcl_lst *a, t_dcl_lst *b, int cmd);
void					sort_dfs(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps,
							long turn);
void					only_run_cmd(t_dcl_lst *a, t_dcl_lst *b, int cmd,
							bool type);
void					run_cmd(t_dcl_lst *a, t_dcl_lst *b, int cmd);
void					run_r_cmd(t_dcl_lst *a, t_dcl_lst *b, int cmd);

/* utils */
long					ps_atol(char *str);
void					put_err_exit(int exit_num);
bool					same_arg(int argc, char **argv);
bool					input_check(int argc, char **argv);

/* lst_utils_X */
void					dcl_lst_addfront(t_dcl_lst *lst, long value);
void					dcl_lst_addback(t_dcl_lst *lst, long value);
t_dcl_lst				*make_lst(int size, char **str);
t_dcl_lst				*make_init_lst(void);
int						get_lst_size(t_dcl_lst *lst);
t_dcl_lst				*get_first_lst(t_dcl_lst *lst);
t_dcl_lst				*get_last_lst(t_dcl_lst *lst);
void					clear_lst(t_dcl_lst *lst);
void					reset_lst(t_dcl_lst *lst);
void					delete_lst(t_dcl_lst *lst);
long					get_mid_value(t_dcl_lst *lst);
bool					is_sorted_lst(t_dcl_lst *lst, t_push_swap *ps);
void					put_ans(t_push_swap *ps);
void					put_cmd(int cmd);
void					reduction_stack(t_dcl_lst *lst);
void					reduction_cmd(t_dcl_lst **lst);

/* command_org */
bool					sab(t_dcl_lst *a);
bool					pab(t_dcl_lst *a, t_dcl_lst *b);
bool					rab(t_dcl_lst *a);
bool					rrab(t_dcl_lst *a);

/* command_X */
bool					sa(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps);
bool					sb(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps);
bool					ss(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps);
bool					pa(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps);
bool					pb(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps);
bool					ra(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps);
bool					rb(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps);
bool					rr(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps);
bool					rra(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps);
bool					rrb(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps);
bool					rrr(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps);

/* checker main */
void					checker_run_cmd(t_dcl_lst *a, t_dcl_lst *b);
bool					check_str_cmd(char *line);
void					run_str_cmd(t_dcl_lst *a, t_dcl_lst *b, char *line);
bool					checker_is_sorted(t_dcl_lst *a);

#endif