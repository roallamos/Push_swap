/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:19:11 by rodralva          #+#    #+#             */
/*   Updated: 2024/04/18 12:51:05 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_max_number(t_list *b)
{
	int	nb;

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

void	ft_values(t_values *value, t_list *a, t_list *b)
{
	value->max_a = ft_max_number(a);
	value->min_a = ft_min_number(a);
	if (!b)
		return ;
	value->max_b = ft_max_number(b);
	value->min_b = ft_min_number(b);
}
