/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 01:24:32 by sehattor          #+#    #+#             */
/*   Updated: 2022/06/11 01:24:33 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool same_arg(int argc, char **argv)
{
	int i;
	int j;

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

bool input_check(int argc, char **argv)
{
	if (argc == 1)
		return (false);
	else if (same_arg(argc, argv))
		return (false);
	return (true);
}