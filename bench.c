




#include "push_swap.h"

size_t	total_ops(t_bench *b)
{
	if (!b)
		return (0);
	return (b->sa + b->sb + b->ss + b->pa + b->pb 
		+ b->ra + b->rb + b->rr + b->rra + b->rrb + b->rrr);
}

char    *get_strategy(t_stack_data *a)
{
	if (a->strat_num == 1)
		return ("Simple");
	if (a->strat_num == 2)
		return ("Medium");
	if (a->strat_num == 3)
		return ("Complex");
	if (a->strat_num == 4)
		return ("Adaptive / ");
	return ("Unknown");
}

char    *get_complexity(t_stack_data *a)
{
    if (a->strat_num == 1)
		return ("O(n²)");
	if (a->strat_num == 2)
		return ("O(n√n)");
	if (a->strat_num == 3)
		return ("O(n log n)");
	if (a->strat_num == 4)
    {
        //
    }
		return ("");
	return ("Unknown");
}


void	print_bench(t_stack_data *basis, t_bench *bench)
{
	// Проверяем, был ли задан режим bench, если нет — ничего не выводим
	if (!basis || ft_strcmp(basis->mode, "bench") != 0)
		return ;

	ft_putstr_fd("[bench] disorder: ");
    ft_putnbr_fd(calculate_disorder(basis->stack_a, basis->st_size), 1);
	ft_putstr_fd("%\n", 1);

	ft_putstr_fd("[bench] strategy:  ", 1);
	ft_putstr_fd(get_strategy(basis), 1);
	if (basis->strat_num == 4)
		ft_putstr_fd(basis->st_size <= 5 ? "Medium" : "Complex", 1);

	ft_putstr_fd(get_complexity(basis), 1);
	if (basis->strat_num == 4)
		ft_putstr_fd(basis->st_size <= 5 ? "O(n√n)" : "O(n log n)", 1);
	ft_putstr_fd("\n", 1);
	
	ft_putstr_fd("TOTAL OPERATIONS:   ", 1);
	ft_putnbr_fd(total_ops(bench), 1);
	ft_putstr_fd("\n==============================================\n\n", 1);
}
