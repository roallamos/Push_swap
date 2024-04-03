#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "./libft/libft.h"

void	ft_init_stack(char **argv, t_list **a);
void	sa(t_list **a);
void	pa(t_list **a, t_list **b);
void	pb(t_list **b, t_list **a);
void	ra(t_list **a);

#endif
