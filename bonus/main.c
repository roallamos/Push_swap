/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:42:28 by rodralva          #+#    #+#             */
/*   Updated: 2024/04/24 16:22:32 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_read(t_list **a, t_list **b)
{
	char	*content;

	content = get_next_line(0);
	while (content)
	{
		if (content)
			ft_sort(a, b, content);
		free(content);
		content = get_next_line(0);
	}
	free(content);
	if (ft_is_sorted(*a, *b))
		ft_printf("OK");
	else
		ft_printf("KO");
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
	ft_read(&a, &b);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (0);
}
