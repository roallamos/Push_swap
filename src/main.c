/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:22:59 by rodralva          #+#    #+#             */
/*   Updated: 2024/04/23 13:59:05 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	leaks(void)
{
	system("leaks -q push_swap");
}

void	ft_terminate(void)
{
	ft_putendl_fd("Error", 2);
	exit (2);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	parse_arg(argv, &a);
	ft_duplicated(a);
	if (!ft_is_sorted(a))
		ft_swap(&a, &b);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (0);
}
