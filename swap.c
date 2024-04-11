/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:15:08 by rodralva          #+#    #+#             */
/*   Updated: 2024/04/11 19:04:06 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*int	ft_is_sorted(t_list *a, t_list *b)
{
	(void)*a;
	(void)*b;
	return (0);
}*/

int		ft_max_number(t_list *b)
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

int		ft_min_number(t_list *b)
{
	int nb;
	
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
	int max;
	int	min;
	t_list *lst;

	max = ft_max_number(*a);
	min = ft_min_number(*a);
	lst = (*a)->next;
	if (*((int *)(*a)->content) == min)
	{
		if (*((int *)lst->content) == max)
		{
			rra(a);
			sa(a);
		}
	}
	else if (*((int *)(*a)->content) == max)
	{
		if (*((int *)lst->content) == min)
			ra(a);
		else
		{
			ra(a);
			sa(a);
		}
	}
	else
	{
		if (*((int *)lst->content) == min)
			sa(a);
		else
			rra(a);
	}
}

void	ft_values(t_values *value, t_list *a, t_list *b)
{
	value->max_a = ft_max_number(a);
	value->min_a = ft_max_number(a);
	value->max_b = ft_max_number(b);
	value->min_b = ft_max_number(b);
}

void	ft_get_top(t_list *a)
{
	int size_a;
	int i;

	size_a = ft_lstsize(a);
	i = 0;
	while (i <= size_a / 2)
	{
		a->moves.ra = i;
		a = a->next;
		i++;
	}
	while(a)
	{
		a->moves.rra = (i - size_a + 1);
		a = a->next;
		i++;
	}
}
int	ft_get_diff(t_list *a, t_list *b)
{
	int	min_diff;
	int diff;

	min_diff = 0;

	while(a)
	{
		diff = (*(int *)a->content) - (*(int *)b->content);
		if (min_diff == 0 || diff < min_diff)
			min_diff = diff;
		a = a->next;
	}
	return (min_diff);
}
void	ft_sort_a(t_list **a, t_list **b)
{
	t_values value;
	t_list	*lst_a;
	t_list	*lst_b;

	lst_a = *a;
	lst_b = *b;
	ft_values(&value, *a, *b);
	ft_get_top(*a);
	ft_get_top(*b);
	value.min_diff = ft_get_diff(*a, *b);
	value.diff = (*(int *)(*a)->content) - (*(int *)(*b)->content);
	if(*((int *)lst_b->content) < value.min_a)
	{
		while(*((int *)lst_a->content) != value.min_a)
			lst_a = lst_a->next;
		while(lst_a->moves.ra != 0)
		{
			ra(a);
			lst_a->moves.ra--;
		}
		while(lst_a->moves.rra != 0)
		{
			rra(a);
			lst_a->moves.ra--;
		}
		pa(a, b);
	}
	else if(*((int *)lst_b->content) > value.max_a)
	{
		while(*((int *)lst_a->content) != value.min_a)
			lst_a = lst_a->next;
		while(lst_a->moves.ra != 0)
		{
			ra(a);
			lst_a->moves.ra--;
		}
		while(lst_a->moves.rra != 0)
		{
			rra(a);
			lst_a->moves.ra--;
		}
		pa(a, b);
		ra(a);
	}
	else
	{
		while(value.diff != value.min_diff)
		{
			lst_a = lst_a->next;
			value.diff = (*(int *)lst_a->content) - (*(int *)(*b)->content);
		}
		while(lst_a->moves.ra != 0)
		{
			ra(a);
			lst_a->moves.ra--;
		}
		while(lst_a->moves.rra != 0)
		{
			rra(a);
			lst_a->moves.ra--;
		}
		pa(a, b);
		ra(a);
	}
}

void	ft_swap(t_list **a, t_list **b)
{
	while (ft_lstsize(*b) < 2 && ft_lstsize(*a) > 3)
			pb(b, a);
	if (ft_lstsize(*a) <= 3)
	{
		ft_sort_threes(a);
		while (b && *b)
			ft_sort_a(a, b);
	}
	else
	{
	}
}
