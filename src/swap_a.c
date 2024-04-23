/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:15:08 by rodralva          #+#    #+#             */
/*   Updated: 2024/04/18 16:39:00 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static t_list	*ft_position_a(t_list *a, t_list *b, t_values value)
{
	if (*((int *)b->content) < value.min_a
		|| *((int *)b->content) > value.max_a)
	{
		while (*((int *)a->content) != value.min_a)
			a = a->next;
	}
	else
	{
		while (value.diff != value.min_diff)
		{
			a = a->next;
			if (*((int *)a->content) > *((int *)b->content))
				value.diff = *((int *)a->content) - *((int *)b->content);
		}
	}
	return (a);
}

void	ft_sort_a(t_list **a, t_list **b)
{
	t_values	value;
	t_list		*lst_a;

	ft_values(&value, *a, *b);
	ft_get_top(*a, 0);
	ft_get_top(*b, 1);
	value.min_diff = ft_get_diff(*a, *b, 0);
	if (*((int *)(*a)->content) > *((int *)(*b)->content))
		value.diff = *((int *)(*a)->content) - *((int *)(*b)->content);
	else
		value.diff = 0;
	lst_a = ft_position_a(*a, *b, value);
	ft_start_moving(a, b, lst_a, *b);
	pa(a, b);
}

void	min_to_top(t_list **a, t_list *lst_a)
{
	if (lst_a->moves.ra <= lst_a->moves.rra)
	{
		while (lst_a->moves.ra != 0)
		{
			ra(a, 1);
			lst_a->moves.ra--;
		}
	}
	else if (lst_a->moves.ra > lst_a->moves.rra)
	{
		while (lst_a->moves.rra != 0)
		{
			rra(a, 1);
			lst_a->moves.rra--;
		}
	}
}

void	ft_sort_small(t_list **a, t_list **b)
{
	t_list		*lst_a;
	t_values	value;

	ft_sort_threes(a);
	while (b && *b)
		ft_sort_a(a, b);
	ft_get_top(*a, 0);
	ft_values(&value, *a, *b);
	lst_a = *a;
	while (*((int *)lst_a->content) != value.min_a)
		lst_a = lst_a->next;
	min_to_top(a, lst_a);
}

void	ft_swap(t_list **a, t_list **b)
{
	t_values	value;
	t_list		*lst_a;
	t_list		*lst_b;

	while (ft_lstsize(*b) < 2 && ft_lstsize(*a) > 3)
		pb(b, a);
	if (ft_lstsize(*a) <= 3)
		ft_sort_small(a, b);
	else
	{
		lst_a = *a;
		lst_b = *b;
		while (ft_lstsize(*a) > 3)
			ft_sort_b(b, a);
		ft_sort_threes(a);
		while (b && *b)
			ft_sort_a(a, b);
		ft_get_top(*a, 0);
		ft_values(&value, *a, *b);
		lst_a = *a;
		while (*((int *)lst_a->content) != value.min_a)
			lst_a = lst_a->next;
		min_to_top(a, lst_a);
	}
}
