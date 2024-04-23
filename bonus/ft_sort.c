/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:43:24 by rodralva          #+#    #+#             */
/*   Updated: 2024/04/23 20:31:19 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_sort(t_list **a, t_list **b, t_list *sort)
{
	char	*move;
	int		len;
	while (sort)
	{
		move = (char *)sort->content;
		len = ft_strlen(move);
		if (!ft_strncmp(move, "sa\n", len))
			sa(a);
		else if (!ft_strncmp(move, "sb\n", len))
			sb(b);
		else if (!ft_strncmp(move, "ss\n", len))
			ss(a, b);
		else if (!ft_strncmp(move, "ra\n", len))
			ra(a);
		else if (!ft_strncmp(move, "rb\n", len))
			rb(b);
		else if (!ft_strncmp(move, "rr\n", len))
			rr(a, b);
		else if (!ft_strncmp(move, "rra\n", len))
			rra(a);
		else if (!ft_strncmp(move, "rrb\n", len))
			rrb(b);
		else if (!ft_strncmp(move, "rrr\n", len))
			rrr(a, b);
		else
			ft_terminate();
		sort = sort->next;
	}
	if (ft_is_sorted(*a))
		ft_printf("OK");
	else
		ft_printf("KO");
}
