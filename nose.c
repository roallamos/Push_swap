/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nose.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:38:33 by rodralva          #+#    #+#             */
/*   Updated: 2024/04/16 11:58:05 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_cheapest(t_list *a, t_list *b, t_values *value)
{
	t_list	*lst_a;
	t_list	*lst_b;
	int		actual;
	int		how_to_move;

	lst_a = a;
	lst_b = b;
	value->cheapest = -1;
	//	print_moves(lst_a, lst_b);
	while (lst_a)
	{
		value->min_diff = ft_get_diff(lst_a, lst_b, 1);
		if (*((int *)lst_a->content) > *((int *)lst_b->content))
			value->diff = *((int *)lst_a->content) - *((int *)lst_b->content);
		else
			value->diff = 0;
		if (*((int *)lst_a->content) < value->min_b)
		{
			while (*((int *)lst_b->content) != value->max_b)
				lst_b = lst_b->next;
		}
		else if (*((int *)lst_a->content) > value->max_b)
		{
			while (*((int *)lst_b->content) != value->max_b)
				lst_b = lst_b->next;
		}
		else
		{
			while (value->diff != value->min_diff)
			{
				lst_b = lst_b->next;
				if (*((int *)lst_a->content) > *((int *)lst_b->content))
					value->diff = *((int *)lst_a->content)
						- *((int *)lst_b->content);
			}
		}
		how_to_move = ft_moves(lst_a, lst_b);
		if (how_to_move == 1)
		{
			if (lst_a->moves.ra >= lst_b->moves.rb)
				actual = lst_a->moves.ra;
			else
				actual = lst_b->moves.rb;
		}
		else if (how_to_move == 2)
		{
			if (lst_a->moves.rra >= lst_b->moves.rrb)
				actual = lst_a->moves.rra;
			else
				actual = lst_b->moves.rrb;
		}
		else if (how_to_move == 3)
		{
			actual = lst_a->moves.ra + lst_b->moves.rrb;
			if (lst_a->moves.rra + lst_b->moves.rb < actual)
				actual = lst_b->moves.rb + lst_a->moves.rra;
		}
		lst_a->moves.moves = actual;
		if ((actual < value->cheapest || value->cheapest == -1) && actual >= 0)
			value->cheapest = actual;
		lst_a = lst_a->next;
		lst_b = b;
	}
}

void	print_moves(t_list *a, t_list *b)
{
	while (a)
	{
		printf("a ra %i a rra %i a rr %i a rrr %i\n", a->moves.ra, a->moves.rra,
				a->moves.rr, a->moves.rrr);
		a = a->next;
	}
	while (b)
	{
		printf("b rb %i b rrb %i b rr %i b rrr %i\n", b->moves.rb, b->moves.rrb,
				b->moves.rr, b->moves.rrr);
		b = b->next;
	}
	printf("*********\n");
}

void	ft_sort_b(t_list **b, t_list **a)
{
	t_values	value;
	t_list		*lst_a;
	t_list		*lst_b;
	int			how_to_move;

	lst_a = *a;
	lst_b = *b;
	ft_values(&value, *a, *b);
	ft_get_top(*a, 0);
	ft_get_top(*b, 1);
	ft_cheapest(*a, *b, &value);
	while (lst_a->moves.moves != value.cheapest)
		lst_a = lst_a->next;
	value.min_diff = ft_get_diff(lst_a, lst_b, 1);
	if (*((int *)lst_a->content) > *((int *)lst_b->content))
		value.diff = *((int *)lst_a->content) - *((int *)lst_b->content);
	else
		value.diff = 0;
	if (*((int *)lst_a->content) < value.min_b)
	{
		while (*((int *)lst_b->content) != value.max_b)
			lst_b = lst_b->next;
	}
	else if (*((int *)lst_a->content) > value.max_b)
	{
		while (*((int *)lst_b->content) != value.max_b)
			lst_b = lst_b->next;
	}
	else
	{
		while (value.diff != value.min_diff)
		{
			lst_b = lst_b->next;
			if (*((int *)lst_a->content) > *((int *)lst_b->content))
				value.diff = *((int *)lst_a->content)
					- *((int *)lst_b->content);
		}
	}
	how_to_move = ft_moves(lst_a, lst_b);
	ft_prepare_moves(lst_a, lst_b, how_to_move);
	//	print_moves(*a, *b);
	if (how_to_move == 1)
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
	else if (how_to_move == 2)
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
	else if (how_to_move == 3)
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
	pb(b, a);
}
