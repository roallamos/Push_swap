#include "pushswap.h"

int main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	ft_init_stack(argv, &a);
//	pa(&a, &b);
//	pb(&b, &a);
	ra(&a);
	while (a)
	{
		printf("----- a %d\n", *((int *)a->content));
		a = a->next;
	}
	while (b)
	{
		printf("----- b %d\n", *((int *)b->content));
		b = b->next;
	}
	//ft_swap(&list);
	return (0);
}
