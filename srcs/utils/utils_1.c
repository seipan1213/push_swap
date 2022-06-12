/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 01:24:29 by sehattor          #+#    #+#             */
/*   Updated: 2022/06/12 23:54:30 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ps_atol(char *str)
{
	int		i;
	int		len;
	long	m;
	long	ans;

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
	if (len != i || len > 11 || ans * m > INT_MAX
		|| ans * m < INT_MIN || len == 0)
		put_err_exit(1);
	return (ans * m);
}

void	put_err_exit(int exit_num)
{
	ft_putendl_fd("ERROR", STDOUT_FILENO);
	exit(exit_num);
}

bool	same_arg(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
			{
				return (true);
			}
			j++;
		}
		i++;
	}
	return (false);
}

bool	input_check(int argc, char **argv)
{
	if (argc == 1)
		return (false);
	else if (same_arg(argc, argv))
		put_err_exit(1);
	return (true);
}
