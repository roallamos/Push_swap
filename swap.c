/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:15:08 by rodralva          #+#    #+#             */
/*   Updated: 2024/04/16 18:28:50 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*int	ft_is_sorted(t_list *a, t_list *b)
{
	int	nb;

	(void)*a;
	(void)*b;
	return (0);
}*/
int	ft_max_number(t_list *b)
{
	int nb;

	nb = *((int *)b->content);
	while (b)
	{
		if (nb < *((int *)b->content))
			nb = *((int *)b->content);
		b = b->next;
	}
	return (nb);
}

int	ft_min_number(t_list *b)
{
	int	nb;

	nb = *((int *)b->content);
	while (b)
	{
		if (nb > *((int *)b->content))
			nb = *((int *)b->content);
		b = b->next;
	}
	return (nb);
}

void	ft_sort_threes(t_list **a)
{
	int		max;
	int		min;
	t_list	*lst;

	max = ft_max_number(*a);
	min = ft_min_number(*a);
	lst = (*a)->next;
	if (*((int *)(*a)->content) == min)
	{
		if (*((int *)lst->content) == max)
		{
			rra(a, 1);
			sa(a, 1);
		}
	}
	else if (*((int *)(*a)->content) == max)
	{
		if (*((int *)lst->content) == min)
			ra(a, 1);
		else
		{
			ra(a, 1);
			sa(a, 1);
		}
	}
	else
	{
		if (*((int *)lst->content) == min)
			sa(a, 1);
		else
			rra(a, 1);
	}
}

void	ft_values(t_values *value, t_list *a, t_list *b)
{
	value->max_a = ft_max_number(a);
	value->min_a = ft_min_number(a);
	if (!b)
		return ;
	value->max_b = ft_max_number(b);
	value->min_b = ft_min_number(b);
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
		{
			a->moves.ra = i;
			a->moves.rra = (size_a - i);
			a->moves.rb = 0;
			a->moves.rrb = 0;
		}
		else
		{
			a->moves.rb = i;
			a->moves.rrb = (size_a - i);
			a->moves.ra = 0;
			a->moves.rra = 0;
		}
		a->moves.rr = 0;
		a->moves.rrr = 0;
		a = a->next;
		i++;
	}
}
int	ft_get_diff(t_list *a, t_list *b, int ab)
{
	int	min_diff;
	int	diff;

	min_diff = 0;
	diff = 0;
	if (ab == 0)
	{
		while (a)
		{
			if (*((int *)a->content) > *((int *)b->content))
				diff = *((int *)a->content) - *((int *)b->content);
			if (min_diff == 0 || diff < min_diff)
				min_diff = diff;
			a = a->next;
		}
	}
	else
	{
		while (b)
		{
			if (*((int *)a->content) > *((int *)b->content))
				diff = *((int *)a->content) - *((int *)b->content);
			if (min_diff == 0 || diff < min_diff)
				min_diff = diff;
			b = b->next;
		}
	}
	return (min_diff);
}

int	ft_prepare_moves(t_list *a, t_list *b, int dir)
{
	if (dir == 1)
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
	if (dir == 2)
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
	if (dir == 3)
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
	/*	if (up <= opposite && up <= down)
		return(ft_prepare_moves(a, b, 1));
	if (down <= up && down <= opposite)
		return(ft_prepare_moves(a, b, 2));
	if (down <= up && down <= opposite)
		return(ft_prepare_moves(a, b, 3));*/
	return (0);
}

void	ft_sort_a(t_list **a, t_list **b)
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
	value.min_diff = ft_get_diff(*a, *b, 0);
	if (*((int *)(*a)->content) > *((int *)(*b)->content))
		value.diff = *((int *)(*a)->content) - *((int *)(*b)->content);
	else
		value.diff = 0;
	if (*((int *)lst_b->content) < value.min_a)
	{
		while (*((int *)lst_a->content) != value.min_a)
			lst_a = lst_a->next;
		how_to_move = ft_moves(lst_a, lst_b);
		ft_prepare_moves(lst_a, lst_b, how_to_move);
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
		pa(a, b);
	}
	else if (*((int *)lst_b->content) > value.max_a)
	{
		while (*((int *)lst_a->content) != value.min_a)
			lst_a = lst_a->next;
		how_to_move = ft_moves(lst_a, lst_b);
		ft_prepare_moves(lst_a, lst_b, how_to_move);
		// ----------------------------------------------
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
		pa(a, b);
	}
	// ---------------------------------------------
	else
	{
		while (value.diff != value.min_diff)
		{
			lst_a = lst_a->next;
			if (*((int *)lst_a->content) > *((int *)(*b)->content))
				value.diff = *((int *)lst_a->content) - *((int *)(*b)->content);
		}
		how_to_move = ft_moves(lst_a, lst_b);
		ft_prepare_moves(lst_a, lst_b, how_to_move);
		//		print_moves(*a, *b);
		// ----------------------------------------------
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
		pa(a, b);
	}
	// ----------------------------------------------
}

void	ft_swap(t_list **a, t_list **b)
{
	t_values	value;
	t_list		*lst_a;
	t_list		*lst_b;

	while (ft_lstsize(*b) < 2 && ft_lstsize(*a) > 3)
		pb(b, a);
	if (ft_lstsize(*a) <= 3)
	{
		ft_sort_threes(a);
		while (b && *b)
			ft_sort_a(a, b);
		ft_get_top(*a, 0);
		ft_values(&value, *a, *b);
		lst_a = *a;
		while (*((int *)lst_a->content) != value.min_a)
			lst_a = lst_a->next;
		if (lst_a->moves.ra < lst_a->moves.rra)
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
	else
	{
		lst_a = *a;
		lst_b = *b;
		while (ft_lstsize(*a) > 3)
			ft_sort_b(b, a);
		ft_sort_threes(a);
		//		print_stack(*a, *b);
		//		printf("*************\n");
		while (b && *b)
			ft_sort_a(a, b);
		ft_get_top(*a, 0);
		ft_values(&value, *a, *b);
		lst_a = *a;
		while (*((int *)lst_a->content) != value.min_a)
			lst_a = lst_a->next;
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
}
