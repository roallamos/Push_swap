/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:22:59 by rodralva          #+#    #+#             */
/*   Updated: 2024/04/16 18:29:17 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	leaks(void)
{
	system("leaks -q push_swap");
}

void	print_stack(t_list *a, t_list *b)
{
	while (a)
	{
		printf("----- a %d\n", *((int *)a->content));
		a = a->next;
	}
	while (b)
	{
		printf("----- b %d\n", *((int *)b->content));
		b = b->next;
	}
}

char **parse_arg(char **argv)
{
	char	**spl;

	spl = ft_split(argv[1], ' ');
	return(spl);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char **spl;

	a = NULL;
	b = NULL;
	//	atexit(leaks);
	if (argc == 1)
		exit (2);
	else if (argc == 2)
	{
		spl = parse_arg(argv);
		ft_init_stack(spl, &a, 0);
	}
	else
		ft_init_stack(argv, &a, 1);
	ft_swap(&a, &b);
//	print_stack(a, b);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (0);
}
