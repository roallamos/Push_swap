/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:22:59 by rodralva          #+#    #+#             */
/*   Updated: 2024/04/11 16:22:49 by rodralva         ###   ########.fr       */
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

int main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	atexit(leaks);
	if (argc == 1)
		return (0);
	ft_init_stack(argv, &a);
	ft_swap(&a, &b);
	print_stack(a, b);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (0);
}
