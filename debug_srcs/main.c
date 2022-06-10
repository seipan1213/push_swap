#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
	t_dcl_lst *a;
	t_dcl_lst *b;
	char *line;
	int ret;

	a = make_lst(argc - 1, argv + 1);
	b = make_init_lst();
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (!ft_strncmp(line, "sa", 3))
			sab(a);
		else if (!ft_strncmp(line, "sb", 3))
			sab(b);
		else if (!ft_strncmp(line, "ss", 3))
		{
			sab(a);
			sab(b);
		}
		else if (!ft_strncmp(line, "pa", 3))
			pab(a, b);
		else if (!ft_strncmp(line, "pb", 3))
			pab(b, a);
		else if (!ft_strncmp(line, "ra", 3))
			rab(a);
		else if (!ft_strncmp(line, "rb", 3))
			rab(b);
		else if (!ft_strncmp(line, "rr", 3))
		{
			rab(a);
			rab(b);
		}
		else if (!ft_strncmp(line, "rra", 3))
			rrab(a);
		else if (!ft_strncmp(line, "rrb", 3))
			rrab(b);
		else if (!ft_strncmp(line, "rrr", 3))
		{
			rrab(a);
			rrab(b);
		}
		put_stack(a, b);
	}
}