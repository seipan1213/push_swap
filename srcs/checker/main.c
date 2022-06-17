/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:58:21 by sehattor          #+#    #+#             */
/*   Updated: 2022/06/17 15:18:40 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_dcl_lst	*a;
	t_dcl_lst	*b;

	if (!input_check(argc, argv))
		return (0);
	a = make_lst(argc - 1, argv + 1);
	b = make_init_lst();
	checker_run_cmd(a, b);
	if (is_sorted_lst(a))
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
	clear_lst(a);
	clear_lst(b);
}

void	checker_run_cmd(t_dcl_lst *a, t_dcl_lst *b)
{
	char	*line;
	int		ret;

	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(0, &line);
		if (ret <= 0)
			break ;
		if (!check_str_cmd(line))
			put_err_exit(1);
		run_str_cmd(a, b, line);
		free(line);
	}
	free(line);
}

bool	check_str_cmd(char *line)
{
	if (ft_strncmp(line, "sa", 3) && ft_strncmp(line, "sb", 3)
		&& ft_strncmp(line, "ss", 3) && ft_strncmp(line, "pa", 3)
		&& ft_strncmp(line, "pb", 3) && ft_strncmp(line, "ra", 3)
		&& ft_strncmp(line, "rb", 3) && ft_strncmp(line, "rr", 3)
		&& ft_strncmp(line, "rra", 4) && ft_strncmp(line, "rrb", 4)
		&& ft_strncmp(line, "rrr", 4))
		return (false);
	return (true);
}

void	run_str_cmd(t_dcl_lst *a, t_dcl_lst *b, char *line)
{
	if (!ft_strncmp(line, "sa", 3) || !ft_strncmp(line, "ss", 3))
		sab(a);
	if (!ft_strncmp(line, "sb", 3) || !ft_strncmp(line, "ss", 3))
		sab(b);
	if (!ft_strncmp(line, "pa", 3))
		pab(a, b);
	if (!ft_strncmp(line, "pb", 3))
		pab(b, a);
	if (!ft_strncmp(line, "ra", 3) || !ft_strncmp(line, "rr", 3))
		rab(a);
	if (!ft_strncmp(line, "rb", 3) || !ft_strncmp(line, "rr", 3))
		rab(b);
	if (!ft_strncmp(line, "rra", 4) || !ft_strncmp(line, "rrr", 4))
		rrab(a);
	if (!ft_strncmp(line, "rrb", 4) || !ft_strncmp(line, "rrr", 4))
		rrab(b);
}
