/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:52:35 by rodralva          #+#    #+#             */
/*   Updated: 2024/04/18 15:09:17 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	ft_get_top_b(t_list *a, int size_a, int i)
{
	a->moves.rb = i;
	a->moves.rrb = (size_a - i);
	a->moves.ra = 0;
	a->moves.rra = 0;
}

static void	ft_get_top_a(t_list *a, int size_a, int i)
{
	a->moves.ra = i;
	a->moves.rra = (size_a - i);
	a->moves.rb = 0;
	a->moves.rrb = 0;
}

void	ft_get_top(t_list *a, int ab)
{
	int	size_a;
	int	i;

	size_a = ft_lstsize(a);
	i = 0;
	while (a)
	{
		if (ab == 0)
			ft_get_top_a(a, size_a, i);
		else
			ft_get_top_b(a, size_a, i);
		a->moves.rr = 0;
		a->moves.rrr = 0;
		a = a->next;
		i++;
	}
}
