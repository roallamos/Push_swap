/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:43:21 by rodralva          #+#    #+#             */
/*   Updated: 2024/04/24 11:52:38 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "../printf/ft_printf.h"

typedef struct s_values
{
	int	max_a;
	int	min_a;
	int	max_b;
	int	min_b;
	int	min_diff;
	int	diff;
	int	cheapest;
}		t_values;

void	ft_init_stack(char **spl, t_list **a);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **b, t_list **a);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);
void	ft_terminate(void);
void	ft_check_split(char *spl);
int		ft_is_sorted(t_list *a, t_list *b);
void	ft_duplicated(t_list *a);
char	**parse_arg(char **argv, t_list **a);
int		ft_max_number(t_list *b);
int		ft_min_number(t_list *b);
void	ft_sort(t_list **a, t_list **b, char *move);

#endif
