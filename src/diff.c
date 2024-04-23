/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:55:31 by rodralva          #+#    #+#             */
/*   Updated: 2024/04/18 13:49:33 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_get_diff(t_list *a, t_list *b, int ab)
{
	int	min_diff;
	int	diff;

	min_diff = 0;
	diff = 0;
	while (a && b)
	{
		if (*((int *)a->content) > *((int *)b->content))
			diff = *((int *)a->content) - *((int *)b->content);
		if (min_diff == 0 || diff < min_diff)
			min_diff = diff;
		if (ab == 0)
			a = a->next;
		else
			b = b->next;
	}
	return (min_diff);
}
