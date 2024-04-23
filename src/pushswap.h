/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:26:18 by rodralva          #+#    #+#             */
/*   Updated: 2024/04/23 12:12:52 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

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
void	ft_swap(t_list **a, t_list **b);
void	sa(t_list **a, int p);
void	sb(t_list **b, int p);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **b, t_list **a);
void	ra(t_list **a, int p);
void	rb(t_list **b, int p);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a, int p);
void	rrb(t_list **b, int p);
void	rrr(t_list **a, t_list **b);
void	ft_sort_a(t_list **a, t_list **b);
void	ft_sort_b(t_list **b, t_list **a);
int		ft_get_diff(t_list *a, t_list *b, int ab);
int		ft_moves(t_list *a, t_list *b);
int		ft_prepare_moves(t_list *a, t_list *b, int dir);
void	ft_get_top(t_list *a, int ab);
void	ft_values(t_values *value, t_list *a, t_list *b);
void	ft_cheapest(t_list *a, t_list *b, t_values *value);
void	print_stack(t_list *a, t_list *b);
void	print_moves(t_list *a, t_list *b);
void	ft_terminate(void);
void	ft_check_split(char *spl);
int		ft_is_sorted(t_list *a);
void	ft_duplicated(t_list *a);
char	**parse_arg(char **argv, t_list **a);
int		ft_max_number(t_list *b);
int		ft_min_number(t_list *b);
void	ft_sort_threes(t_list **a);
void	ft_moving_up(t_list **a, t_list **b, t_list *lst_a, t_list *lst_b);
void	ft_moving_down(t_list **a, t_list **b, t_list *lst_a, t_list *lst_b);
void	ft_moving_opposite(t_list **a, t_list **b, t_list *lst_a, t_list *l_b);
void	ft_start_moving(t_list **a, t_list **b, t_list *lst_a, t_list *l_b);
t_list	*ft_position_b(t_list *a, t_list *b, t_values value);

#endif
