/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:11:57 by rodralva          #+#    #+#             */
/*   Updated: 2024/04/18 15:29:43 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_move_opposite(t_list *a, t_list *b)
{
	if (a->moves.ra < a->moves.rra)
	{
		while (a->moves.rra)
			a->moves.rra--;
	}
	else if (a->moves.ra > a->moves.rra)
	{
		while (a->moves.ra)
			a->moves.ra--;
	}
	if (b->moves.rb < b->moves.rrb)
	{
		while (b->moves.rrb)
			b->moves.rrb--;
	}
	else if (b->moves.rb > b->moves.rrb)
	{
		while (b->moves.rb)
			b->moves.rb--;
	}
	return (3);
}

static int	ft_move_down(t_list *a, t_list *b)
{
	while (a->moves.rra != 0 && b->moves.rrb)
	{
		a->moves.rrr++;
		b->moves.rrr++;
		a->moves.rra--;
		b->moves.rrb--;
	}
	return (2);
}

static int	ft_move_up(t_list *a, t_list *b)
{
	while (a->moves.ra != 0 && b->moves.rb)
	{
		a->moves.rr++;
		b->moves.rr++;
		a->moves.ra--;
		b->moves.rb--;
	}
	return (1);
}

int	ft_prepare_moves(t_list *a, t_list *b, int dir)
{
	if (dir == 1)
		return (ft_move_up(a, b));
	if (dir == 2)
		return (ft_move_down(a, b));
	if (dir == 3)
		return (ft_move_opposite(a, b));
	return (0);
}

int	ft_moves(t_list *a, t_list *b)
{
	int	opposite;
	int	up;
	int	down;

	up = 0;
	down = 0;
	opposite = a->moves.ra + b->moves.rrb;
	if (b->moves.rb + a->moves.rra < opposite)
		opposite = b->moves.rb + a->moves.rra;
	if (a->moves.ra >= b->moves.rb)
		up = a->moves.ra;
	else if (a->moves.ra < b->moves.rb)
		up = b->moves.rb;
	if (a->moves.rra >= b->moves.rrb)
		down = a->moves.rra;
	else if (a->moves.rra < b->moves.rrb)
		down = b->moves.rrb;
	if (up <= opposite && up <= down)
		return (1);
	if (down <= up && down <= opposite)
		return (2);
	if (opposite <= up && opposite <= down)
		return (3);
	return (0);
}
