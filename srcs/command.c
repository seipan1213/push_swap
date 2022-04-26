#include "push_swap.h"

bool sa(t_dcl_lst *a)
{
	long tmp;
	int size;

	size = dcl_lst_size(a);
	if (size <= 1)
		return (false);
	a = a->next;
	tmp = a->value;
	a->value = a->next->value;
	a->next->value = tmp;
	return (true);
}

bool sb(t_dcl_lst *a, t_dcl_lst *b)
{
}
bool ss(t_dcl_lst *a, t_dcl_lst *b)
{
}
bool pa(t_dcl_lst *a, t_dcl_lst *b)
{
}
bool pb(t_dcl_lst *a, t_dcl_lst *b)
{
}
bool ra(t_dcl_lst *a, t_dcl_lst *b)
{
}
bool rb(t_dcl_lst *a, t_dcl_lst *b)
{
}
bool rr(t_dcl_lst *a, t_dcl_lst *b)
{
}
bool rra(t_dcl_lst *a, t_dcl_lst *b)
{
}
bool rrb(t_dcl_lst *a, t_dcl_lst *b)
{
}
bool rrr(t_dcl_lst *a, t_dcl_lst *b)
{
}