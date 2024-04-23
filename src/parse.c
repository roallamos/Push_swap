/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:09:32 by rodralva          #+#    #+#             */
/*   Updated: 2024/04/23 14:05:46 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_check_split(char *spl)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (spl[i + j])
	{
		if ((spl[i] < '0' || spl[i] > '9') && spl[i] != '-' && spl[i] != '+')
			ft_terminate();
		while (spl[i] == '-' || spl[i] == '+')
		{
			i++;
			if (!spl[i] || (spl[i] < '0' || spl[i] > '9'))
				ft_terminate();
		}
		while(spl[i + j] == '0')
			j++;
		while ((spl[i + j] >= '0' && spl[i + j] <= '9'))
		{
			i++;
			if (spl[i + j] && (spl[i + j] < '0' || spl[i + j] > '9'))
				ft_terminate();
		}
		if (i > 11)
			ft_terminate();
	}
}

char	**parse_arg(char **argv, t_list **a)
{
	char	**spl;
	int		i;

	i = 1;
	if (argv[1][0] == 0)
	{
		ft_putendl_fd("Error", 2);
		exit(2);
	}
	while (argv[i])
	{
		spl = ft_split(argv[i], ' ');
		ft_init_stack(spl, a);
		free(spl);
		i++;
	}
	return (spl);
}

int	ft_is_sorted(t_list *a)
{
	int	nb;

	nb = *((int *)a->content);
	a = a->next;
	while (a)
	{
		if (nb > *((int *)a->content))
			return (0);
		nb = *((int *)a->content);
		a = a->next;
	}
	return (1);
}

void	ft_duplicated(t_list *a)
{
	t_list	*lst_a;

	lst_a = a->next;
	while (a)
	{
		while (lst_a)
		{
			if (*((int *)lst_a->content) == *((int *)(a->content)))
			{
				ft_putendl_fd("Error", 2);
				exit(2);
			}
			lst_a = lst_a->next;
		}
		a = a->next;
		if (a)
			lst_a = a->next;
	}
}
