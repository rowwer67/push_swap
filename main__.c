/*
int main(int argc, char **argv)
{
    int a;
	t_stack_data *basis;
    t_bench *op_count;



    if (argc <= 1)
        return (0);
    if (parse_it(argc, argv, basis))
        {
            //printing error message 
            // if it returns 2 or 3 - clean the stack
            //abort the programm
        };
    calculate_disorder(basis->stack_a, basis);
    if (basis->strat_num == 4)
        set_adaptive(&basis);
        
    
}
*/


//добавить проценты

#include "push_swap.h"

static void	init_data(t_stack_data *basis)
{
	basis->st_size = 0;
	basis->stack_a = NULL;
	basis->stack_b = NULL;
	basis->disord = 0.0;
	basis->strat_num = 4;
	basis->mode = 0;
	basis->bench->sa = 0;
	basis->bench->sb = 0;
	basis->bench->ss = 0;
	basis->bench->pa = 0;
	basis->bench->pb = 0;
	basis->bench->ra = 0;
	basis->bench->rb = 0;
	basis->bench->rr = 0;
	basis->bench->rra = 0;
	basis->bench->rrb = 0;
	basis->bench->rrr = 0;
}

static void	error_exit(t_stack_data *basis)
{
	free_stack(&basis->stack_a);
	free_stack(&basis->stack_b);
	write(2, "Error\n", 6);
	return ;
}

int	main(int argc, char **argv)
{
	t_stack_data	*basis;
	t_stack_data	nn;
	int	err;

	if (argc <= 1)
		return (0);
	basis = &nn;
	init_data(basis);
	err = parse_it(argc, argv, basis);
	if (err !=0)
	{
		if (err != 1)
			error_exit(basis);
		return (0);
	}
	calculate_disorder(basis);

	if (basis->strat_num == 4)
		set_adaptive(basis);
	if (basis->disord != 0.0)
		sort_by_strategy(basis);
	print_bench(basis);
	free_stack(&basis->stack_a);
	free_stack(&basis->stack_b);
	return (0);
}