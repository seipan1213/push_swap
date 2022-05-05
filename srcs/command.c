#include "push_swap.h"

bool sa(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	(void)b;
	sab(a);
	dcl_lst_addback(ps->ans, SA);
	return (true);
}

bool sb(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	(void)a;
	sab(b);
	dcl_lst_addback(ps->ans, SB);
	return (true);
}

bool ss(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	sab(a);
	sab(b);
	dcl_lst_addback(ps->ans, SS);
	return (true);
}

bool pa(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	pab(a, b);
	dcl_lst_addback(ps->ans, PA);
	return (true);
}

bool pb(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	pab(b, a);
	dcl_lst_addback(ps->ans, PB);
	return (true);
}

bool ra(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	(void)b;
	rab(a);
	dcl_lst_addback(ps->ans, RA);
	return (true);
}

bool rb(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	(void)a;
	rab(b);
	dcl_lst_addback(ps->ans, RB);
	return (true);
}

bool rr(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	rab(a);
	rab(b);
	dcl_lst_addback(ps->ans, RR);
	return (true);
}

bool rra(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	(void)b;
	rrab(a);
	dcl_lst_addback(ps->ans, RRA);
	return (true);
}

bool rrb(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	(void)a;
	rrab(b);
	dcl_lst_addback(ps->ans, RRB);
	return (true);
}

bool rrr(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	rrab(a);
	rrab(b);
	dcl_lst_addback(ps->ans, RRR);
	return (true);
}