/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 01:24:29 by sehattor          #+#    #+#             */
/*   Updated: 2022/06/11 16:22:01 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long ps_atol(char *str)
{
	int i;
	int len;
	long m;
	long ans;

	i = 0;
	m = 1;
	ans = 0;
	if (str[i] == '-')
	{
		m = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		ans *= 10;
		ans += str[i++] - '0';
	}
	len = ft_strlen(str);
	if (len != i || len > 11 || ans * m > INT_MAX || ans * m < INT_MIN)
		put_err_exit(1);
	return (ans * m);
}

void put_err_exit(int exit_num)
{
	ft_putendl_fd("ERROR\n", STDOUT_FILENO);
	exit(exit_num);
}

void put_dcl_lst(t_dcl_lst *lst) //削除予定
{
	while (lst->value != NIL)
		lst = lst->next;
	while (lst->value != NIL)
	{
		printf("%ld\n", lst->value);
		lst = lst->next;
	}
	printf("\n");
}

void put_arr(long values[], int size) //削除予定
{
	int index;

	index = 0;
	while (index < size)
	{
		printf("%ld\n", values[index]);
		index++;
	}
	printf("\n");
}