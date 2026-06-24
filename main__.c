#include "push_swap.h"



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
