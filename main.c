/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:22:59 by rodralva          #+#    #+#             */
/*   Updated: 2024/04/16 20:16:57 by rodralva         ###   ########.fr       */
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

void	ft_check_split(char *spl)
{
	int	i;

	i = 0;
	while(spl[i])
	{
		if (spl[i] <= '0' && spl[i] >= '9' && spl[i] != '-' && spl[i] != '+')
		{
			ft_putendl_fd("error", 2);
			exit (2);
		}
		i++;
	}
}

char **parse_arg(char **argv, t_list **a)
{
	char	**spl;
	int		i;
	int		j;
	int		*content;

	i = 1;
	j = 0;
	while(argv[i])
	{
		spl = ft_split(argv[i], ' ');
		while(spl[j])
		{
			ft_check_split(spl[j]);
			content = ft_calloc(1, 4);
			*content = ft_atoi(spl[j]);
			ft_lstadd_back(a, ft_lstnew(content));
			free(spl[j]);
			j++;
		}
		free(spl);
		j = 0;
		i++;
	}
	return(spl);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
//	char **spl;

	a = NULL;
	b = NULL;
//	atexit(leaks);
	if (argc == 1)
	{	
		ft_putendl_fd("error", 2);
		exit (2);
	}
	parse_arg(argv, &a);
//	ft_init_stack(argv, &a);
	ft_swap(&a, &b);
//	print_stack(a, b);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (0);
}
