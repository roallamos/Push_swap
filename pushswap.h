#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "./libft/libft.h"

/*typedef struct s_list
{
	void			*content;
	struct s_moves	moves;
	struct s_list	*next;
}	t_list;*/

typedef struct s_values
{
	int max_a;
	int min_a;
	int max_b;
	int min_b;
	int min_diff;
	int diff;
}				t_values;

/*typedef struct	s_moves
{
	int	sa;
	int	sb;
	int	ss;
	int pa;
	int pb;
	int ra;
	int rb;
	int rr;
	int rra;
	int rrb;
	int rrr;
}				t_moves;*/

void	ft_init_stack(char **argv, t_list **a);
void	ft_swap(t_list **a, t_list **b);
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

#endif
