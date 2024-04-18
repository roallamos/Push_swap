/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:46:22 by rodralva          #+#    #+#             */
/*   Updated: 2024/04/18 15:03:35 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	third_scenario(t_list **a, t_list *lst, t_values value)
{
	if (*((int *)lst->content) == value.min_a)
		sa(a, 1);
	else
		rra(a, 1);
}

static void	second_scenario(t_list **a, t_list *lst, t_values value)
{
	if (*((int *)lst->content) == value.min_a)
		ra(a, 1);
	else
	{
		ra(a, 1);
		sa(a, 1);
	}
}

static void	first_scenario(t_list **a, t_list *lst, t_values value)
{
	if (*((int *)lst->content) == value.max_a)
	{
		rra(a, 1);
		sa(a, 1);
	}
}

void	ft_sort_threes(t_list **a)
{
	t_values	value;
	t_list		*lst;

	ft_values(&value, *a, NULL);
	lst = (*a)->next;
	if (*((int *)(*a)->content) == value.min_a)
		first_scenario(a, lst, value);
	else if (*((int *)(*a)->content) == value.max_a)
		second_scenario(a, lst, value);
	else
		third_scenario(a, lst, value);
}
