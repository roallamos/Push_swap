/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 20:18:32 by rodralva          #+#    #+#             */
/*   Updated: 2024/04/18 11:24:32 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_init_stack(char **spl, t_list **a)
{
	int		i;
	long	*content;

	i = 0;
	while (spl[i])
	{
		ft_check_split(spl[i]);
		content = ft_calloc(1, sizeof(long));
		*content = ft_atol(spl[i]);
		if (*content > INT_MAX || *content < INT_MIN)
			ft_terminate();
		ft_lstadd_back(a, ft_lstnew(content));
		free(spl[i]);
		i++;
	}
}
