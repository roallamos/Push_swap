/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:50:23 by rodralva          #+#    #+#             */
/*   Updated: 2024/04/18 16:39:04 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_moving_up(t_list **a, t_list **b, t_list *lst_a, t_list *lst_b)
{
	while (lst_a->moves.rr)
	{
		rr(a, b);
		lst_a->moves.rr--;
	}
	while (lst_a->moves.ra)
	{
		ra(a, 1);
		lst_a->moves.ra--;
	}
	while (lst_b->moves.rb)
	{
		rb(b, 1);
		lst_b->moves.rb--;
	}
}

void	ft_moving_down(t_list **a, t_list **b, t_list *lst_a, t_list *lst_b)
{
	while (lst_a->moves.rrr)
	{
		rrr(a, b);
		lst_a->moves.rrr--;
	}
	while (lst_a->moves.rra)
	{
		rra(a, 1);
		lst_a->moves.rra--;
	}
	while (lst_b->moves.rrb)
	{
		rrb(b, 1);
		lst_b->moves.rrb--;
	}
}

void	ft_moving_opposite(t_list **a, t_list **b, t_list *lst_a, t_list *lst_b)
{
	while (lst_a->moves.ra)
	{
		ra(a, 1);
		lst_a->moves.ra--;
	}
	while (lst_b->moves.rb)
	{
		rb(b, 1);
		lst_b->moves.rb--;
	}
	while (lst_a->moves.rra)
	{
		rra(a, 1);
		lst_a->moves.rra--;
	}
	while (lst_b->moves.rrb)
	{
		rrb(b, 1);
		lst_b->moves.rrb--;
	}
}

void	ft_start_moving(t_list **a, t_list **b, t_list *lst_a, t_list *lst_b)
{
	int	how_to_move;

	how_to_move = ft_moves(lst_a, lst_b);
	ft_prepare_moves(lst_a, lst_b, how_to_move);
	if (how_to_move == 1)
		ft_moving_up(a, b, lst_a, lst_b);
	else if (how_to_move == 2)
		ft_moving_down(a, b, lst_a, lst_b);
	else if (how_to_move == 3)
		ft_moving_opposite(a, b, lst_a, lst_b);
}
