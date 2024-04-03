#include "pushswap.h"

void	ft_init_stack(char **argv, t_list **a)
{
	int i;
	int	*content;

	i = 0;
	while(argv[i + 1])
	{
		content = ft_calloc(1,4);
		*content = ft_atoi(argv[i + 1]);
		ft_lstadd_back(a, ft_lstnew(content));
		i++;
	}
/*	while (*a)
	{
		printf("%d\n", *((int *)(*a)->content));
		*a = (*a)->next;
	}*/
}
