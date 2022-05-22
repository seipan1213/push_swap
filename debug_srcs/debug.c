#include "../includes/push_swap.h"

void put_stack(t_dcl_lst *a, t_dcl_lst *b)
{
	int index;

	usleep(200000);
	printf("\033[2J");
	a = get_first_lst(a);
	b = get_first_lst(b);
	index = 0;
	printf("--|     A     |--|     B     |--\n");
	while (index < 30)
	{
		printf("--|");
		if (a->value == NIL)
			printf("           ");
		else
			printf("%7ld    ", a->value);
		printf("|--|");
		if (b->value == NIL)
			printf("           ");
		else
			printf("%7ld    ", b->value);
		printf("|--\n");
		if (a->value != NIL)
			a = a->next;
		if (b->value != NIL)
			b = b->next;
		index++;
	}
}