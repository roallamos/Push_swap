#include "pushswap.h"

void	sa(t_list **a)
{
	void	*swap;
	t_list	*next;

	next = (*a)->next;
	swap = next->next;
	(*a)->next = swap;
	ft_lstadd_front(a, next);
}

void	pa(t_list **a, t_list **b)
{
	t_list *keep;

	if (!b || !*b)
		return ;
	keep = *b;
	ft_lstadd_front(a, ft_lstnew(keep->content));
	*b = keep->next;
	free(keep);
}

void	ra(t_list **a)
{
	t_list *lst;

	lst = *a;
	while ((*a)->next)
		*a = (*a)->next;
	(*a)->next = lst;
	lst->next = NULL;
}
