/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_both.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:22:55 by rodralva          #+#    #+#             */
/*   Updated: 2024/04/15 20:41:56 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ss(t_list **a, t_list **b)
{
	sa(a, 0);
	sb(b, 0);
}
void	rr(t_list **a, t_list **b)
{
	ra(a, 0);
	rb(b, 0);
	printf("rr\n");
}

void	rrr(t_list **a, t_list **b)
{
	rra(a, 0);
	rrb(b, 0);
	printf("rrr\n");
}
