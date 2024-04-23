/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:42:28 by rodralva          #+#    #+#             */
/*   Updated: 2024/04/23 20:22:19 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_read(t_list **sort)
{
	char *content;
//	int	fd = open("text.txt", O_RDONLY);

	content = NULL;
	while (content || !*sort)
	{
		content = get_next_line(0);
		if (content)
			ft_lstadd_back(sort, ft_lstnew(content));
	}
}

void	ft_terminate(void)
{
	ft_putendl_fd("Error", 2);
	exit (2);
}

int main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_list	*sort;

	a = NULL;
	b = NULL;
	sort = NULL;
	if (argc == 1)
		return (0);
	parse_arg(argv, &a);
	ft_duplicated(a);
	ft_read(&sort);
	ft_sort(&a, &b, sort);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	ft_lstclear(&sort, free);
	return (0);
}
