#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "./libft/libft.h"
# include "./printf/ft_printf.h"

/*typedef struct s_list
{
	void			*content;
	struct s_moves	moves;
	struct s_list	*next;
}	t_list;*/

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

void	ft_init_stack(char **argv, t_list **a, int s);
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

#endif
