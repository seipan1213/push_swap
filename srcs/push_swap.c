#include "push_swap.h"

void sort_stack(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	div_stack(a, b, ps);
}

void div_stack(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	long mid;
	int index;

	index = 0;
	mid = ps->sorted_lst[ps->lst_size / 2];
	while (index < ps->lst_size)
	{
		if (get_first_lst(a)->value < mid)
			pb(a, b, ps);
		else
			rra(a, b, ps);
		index++;
	}
}