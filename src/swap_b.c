/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:04:34 by rodralva          #+#    #+#             */
/*   Updated: 2024/04/18 17:04:52 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*ft_position_b(t_list *a, t_list *b, t_values value)
{
	if ((*((int *)a->content) < value.min_b)
		|| (*((int *)a->content) > value.max_b))
	{
		while (*((int *)b->content) != value.max_b)
			b = b->next;
	}
	else
	{
		while (value.diff != value.min_diff)
		{
			b = b->next;
			if (*((int *)a->content) > *((int *)b->content))
				value.diff = *((int *)a->content) - *((int *)b->content);
		}
	}
	return (b);
}

void	ft_sort_b(t_list **b, t_list **a)
{
	t_values	value;
	t_list		*lst_a;
	t_list		*lst_b;

	lst_a = *a;
	ft_values(&value, *a, *b);
	ft_get_top(*a, 0);
	ft_get_top(*b, 1);
	ft_cheapest(*a, *b, &value);
	while (lst_a->moves.moves != value.cheapest)
		lst_a = lst_a->next;
	value.min_diff = ft_get_diff(lst_a, *b, 1);
	if (*((int *)lst_a->content) > *((int *)(*b)->content))
		value.diff = *((int *)lst_a->content) - *((int *)(*b)->content);
	else
		value.diff = 0;
	lst_b = ft_position_b(lst_a, *b, value);
	ft_start_moving(a, b, lst_a, lst_b);
	pb(b, a);
}
