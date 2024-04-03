#include "pushswap.h"

void	sb(t_list **a)
{
	void	*swap;
	t_list	*next;

	next = (*a)->next;
	swap = next->next;
	(*a)->next = swap;
	ft_lstadd_front(a, next);
}
/*
static void	clear_content(void *content)
{
	content = NULL;
}
*/
void	pb(t_list **b, t_list **a)
{
	t_list *keep;
	
	if (!a || !*a)
		return ;
	keep = *a;
	ft_lstadd_front(b, ft_lstnew(keep->content));
	*a = keep->next;
	free(keep);
}

