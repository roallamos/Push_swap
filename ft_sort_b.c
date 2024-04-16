/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:23:01 by rodralva          #+#    #+#             */
/*   Updated: 2024/04/16 11:43:57 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sb(t_list **b, int p)
{
	void	*swap;
	t_list	*next;

	if (!b || !*b || !(*b)->next)
		return ;
	next = (*b)->next;
	swap = next->next;
	(*b)->next = swap;
	ft_lstadd_front(b, next);
	if (p)
		printf("sb\n");
}

void	pb(t_list **b, t_list **a)
{
	t_list	*keep;

	if (!a || !*a)
		return ;
	keep = *a;
	ft_lstadd_front(b, ft_lstnew(keep->content));
	*a = keep->next;
	free(keep);
	printf("pb\n");
}

void	rb(t_list **b, int p)
{
	t_list	*lst;

	if (!b || !*b)
		return ;
	lst = (*b)->next;
	(*b)->next = NULL;
	ft_lstadd_back(&lst, *b);
	*b = lst;
	if (p)
		printf("rb\n");
}

void	rrb(t_list **b, int p)
{
	t_list	*lst;
	t_list	*next;

	if (!b || !*b)
		return ;
	lst = ft_lstlast(*b);
	lst->next = *b;
	*b = lst;
	next = (*b)->next;
	while (lst)
	{
		if (next->content == (*b)->content)
			lst->next = NULL;
		next = next->next;
		lst = lst->next;
	}
	if (p)
		printf("rrb\n");
}
