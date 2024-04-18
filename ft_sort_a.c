/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:25:05 by rodralva          #+#    #+#             */
/*   Updated: 2024/04/18 11:25:07 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sa(t_list **a, int p)
{
	void	*swap;
	t_list	*next;

	if (!a || !*a || !(*a)->next)
		return ;
	next = (*a)->next;
	swap = next->next;
	(*a)->next = swap;
	ft_lstadd_front(a, next);
	if (p)
		printf("sa\n");
}

void	pa(t_list **a, t_list **b)
{
	t_list	*keep;

	if (!b || !*b)
		return ;
	keep = *b;
	ft_lstadd_front(a, ft_lstnew(keep->content));
	*b = keep->next;
	free(keep);
	printf("pa\n");
}

void	ra(t_list **a, int p)
{
	t_list	*lst;

	if (!a || !*a)
		return ;
	lst = (*a)->next;
	(*a)->next = NULL;
	ft_lstadd_back(&lst, *a);
	*a = lst;
	if (p)
		printf("ra\n");
}

void	rra(t_list **a, int p)
{
	t_list	*lst;
	t_list	*next;

	if (!a || !*a)
		return ;
	lst = ft_lstlast(*a);
	lst->next = *a;
	*a = lst;
	next = (*a)->next;
	while (lst)
	{
		if (next->content == (*a)->content)
			lst->next = NULL;
		next = next->next;
		lst = lst->next;
	}
	if (p)
		printf("rra\n");
}
