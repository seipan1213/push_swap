#include "push_swap.h"
// 削除予定デバッグ用

bool sa(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	(void)b;
	sab(a);
	dcl_lst_addback(ps->ans, SA);
	put_stack(a, b);
	return (true);
}

bool sb(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	(void)a;
	sab(b);
	dcl_lst_addback(ps->ans, SB);
	put_stack(a, b);
	return (true);
}

bool ss(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	sab(a);
	sab(b);
	dcl_lst_addback(ps->ans, SS);
	put_stack(a, b);
	return (true);
}

bool pa(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	if (pab(a, b))
		dcl_lst_addback(ps->ans, PA);
	put_stack(a, b);
	return (true);
}

bool pb(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	if (pab(b, a))
		dcl_lst_addback(ps->ans, PB);
	put_stack(a, b);
	return (true);
}

bool ra(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	(void)b;
	rab(a);
	dcl_lst_addback(ps->ans, RA);
	put_stack(a, b);
	return (true);
}

bool rb(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	(void)a;
	rab(b);
	dcl_lst_addback(ps->ans, RB);
	put_stack(a, b);
	return (true);
}

bool rr(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	rab(a);
	rab(b);
	dcl_lst_addback(ps->ans, RR);
	put_stack(a, b);
	return (true);
}

bool rra(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	(void)b;
	rrab(a);
	dcl_lst_addback(ps->ans, RRA);
	put_stack(a, b);
	return (true);
}

bool rrb(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	(void)a;
	rrab(b);
	dcl_lst_addback(ps->ans, RRB);
	put_stack(a, b);
	return (true);
}

bool rrr(t_dcl_lst *a, t_dcl_lst *b, t_push_swap *ps)
{
	rrab(a);
	rrab(b);
	dcl_lst_addback(ps->ans, RRR);
	put_stack(a, b);
	return (true);
}