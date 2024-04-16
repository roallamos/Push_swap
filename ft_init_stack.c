/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 20:18:32 by rodralva          #+#    #+#             */
/*   Updated: 2024/04/16 18:09:37 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_init_stack(char **argv, t_list **a, int s)
{
	int	i;
	int	*content;

	i = 0;
	while (argv[i + s])
	{
		content = ft_calloc(1, 4);
		*content = ft_atoi(argv[i + s]);
		ft_lstadd_back(a, ft_lstnew(content));
		i++;
	}
}
