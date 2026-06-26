


#include "push_swap.h"

size_t	total_ops(t_bench *b)
{
	if (!b)
		return (0);
	return (b->sa + b->sb + b->ss + b->pa + b->pb 
		+ b->ra + b->rb + b->rr + b->rra + b->rrb + b->rrr);
}

char    *get_strategy(t_stack_data *basis)
{
	if (basis->strat_num == 1)
		return ("Simple");
	if (basis->strat_num == 2)
		return ("Medium");
	if (basis->strat_num == 3)
		return ("Complex");
	if (basis->strat_num == 4)
		return ("Adaptive");
	return ("Unknown");
}

char    *get_complexity(t_stack_data *basis)
{
    if (basis->strat_num == 1)
		return ("O(n²)");
	if (basis->strat_num == 2)
		return ("O(n√n)");
	if (basis->strat_num == 3)
		return ("O(n log n)");
	if (basis->strat_num == 4)
		return ("Adaptive");
	return ("Unknown");
}


void	print_bench(t_stack_data *basis)
{
	if (!basis || basis->mode == 0)
		return ;

	ft_putstr_fd("[bench] disorder: ", 2);
    disorder_percentage(basis->disord);
	ft_putstr_fd("%\n", 2);

	ft_putstr_fd("[bench] strategy:  ", 2);
	ft_putstr_fd(get_strategy(basis), 2);
	ft_putstr_fd(" / ", 2);
	ft_putstr_fd(get_complexity(basis), 2);
	ft_putstr_fd("\n", 2);

	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(total_ops(basis->bench), 2);
	ft_putstr_fd("\n", 2);

	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(basis->bench->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(basis->bench->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(basis->bench->ss, 2);

	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(basis->bench->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(basis->bench->pb, 2);
	ft_putstr_fd("\n", 2);

	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(basis->bench->ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(basis->bench->rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(basis->bench->rr, 2);

	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(basis->bench->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(basis->bench->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(basis->bench->rrr, 2);
	ft_putstr_fd("\n", 2);
}
