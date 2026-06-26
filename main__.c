

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_data	*basis;
	t_stack_data	nn;
	t_bench 	bench;
	int	err;

	if (argc <= 1)
		return (0);
	basis = &nn;
	basis->bench = &bench;
	init_data(basis);
	err = parse_it(argc, argv, basis);
	if (err !=0)
	{
		if (err != 1)
			error_exit(basis);
		return (0);
	}
	calculate_disorder(basis);
	assign_indexes(basis->stack_a);
	if (basis->strat_num == 4)
		set_adaptive(basis);
	if (basis->disord != 0.0)
		sort_by_strategy(basis);
	print_bench(basis);
	free_stack(&basis->stack_a);
	free_stack(&basis->stack_b);
	return (0);
}