/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheap.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:57:33 by rodralva          #+#    #+#             */
/*   Updated: 2024/04/19 17:52:33 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	ft_actual(t_list *a, t_list *b, int how_to_move, int *actual)
{
	if (how_to_move == 1)
	{
		if (a->moves.ra >= b->moves.rb)
			*actual = a->moves.ra;
		else
			*actual = b->moves.rb;
	}
	else if (how_to_move == 2)
	{
		if (a->moves.rra >= b->moves.rrb)
			*actual = a->moves.rra;
		else
			*actual = b->moves.rrb;
	}
	else if (how_to_move == 3)
	{
		*actual = a->moves.ra + b->moves.rrb;
		if (a->moves.rra + b->moves.rb < *actual)
			*actual = b->moves.rb + a->moves.rra;
	}
}

void	ft_cheapest(t_list *a, t_list *b, t_values *value)
{
	t_list	*keep;
	int		actual;
	int		how_to_move;

	keep = b;
	value->cheapest = -1;
	while (a)
	{
		value->min_diff = ft_get_diff(a, b, 1);
		if (*((int *)a->content) > *((int *)b->content))
			value->diff = *((int *)a->content) - *((int *)b->content);
		else
			value->diff = 0;
		b = ft_position_b(a, keep, *value);
		how_to_move = ft_moves(a, b);
		ft_actual(a, b, how_to_move, &actual);
		a->moves.moves = actual;
		if ((actual < value->cheapest || value->cheapest == -1) && actual >= 0)
			value->cheapest = actual;
		a = a->next;
		b = keep;
	}
}
