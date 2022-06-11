#include "push_swap.h"

int main(int argc, char **argv)
{
	t_dcl_lst *a;
	t_dcl_lst *b;

	if (!input_check(argc, argv))
		return (0);
	a = make_lst(argc - 1, argv + 1);
	b = make_init_lst();
	checker_run_cmd(a, b);
	if (checker_is_sorted(a))
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
	clear_lst(a);
	clear_lst(b);
}

void checker_run_cmd(t_dcl_lst *a, t_dcl_lst *b)
{
	char *line;
	int ret;

	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (!check_str_cmd(line))
			put_err_exit(1);
		run_str_cmd(a, b, line);
		free(line);
	}
	free(line);
}

bool check_str_cmd(char *line)
{
	if (ft_strncmp(line, "sa", 3) && ft_strncmp(line, "sb", 3) && ft_strncmp(line, "ss", 3) && ft_strncmp(line, "pa", 3) && ft_strncmp(line, "pb", 3) && ft_strncmp(line, "ra", 3) && ft_strncmp(line, "rb", 3) && ft_strncmp(line, "rr", 3) && ft_strncmp(line, "rra", 3) && ft_strncmp(line, "rrb", 3) && ft_strncmp(line, "rrr", 3))
		return (false);
	return (true);
}

void run_str_cmd(t_dcl_lst *a, t_dcl_lst *b, char *line)
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
	if (!ft_strncmp(line, "rra", 3) || !ft_strncmp(line, "rrr", 3))
		rrab(a);
	if (!ft_strncmp(line, "rrb", 3) || !ft_strncmp(line, "rrr", 3))
		rrab(b);
}

bool checker_is_sorted(t_dcl_lst *a)
{
	a = get_first_lst(a);
	while (a->value != NIL)
	{
		if (a->prev->value >= a->value)
			return (false);
		a = a->next;
	}
	return (true);
}