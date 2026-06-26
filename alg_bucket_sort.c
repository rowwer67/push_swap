#include "push_swap.h"

void bucket_sort(t_stack_data *basis)
{
    int range;
    int i;

    range = get_chunk_size((int)basis->st_size);;
    i = 0;

    while (basis->stack_a)
    {
        if (basis->stack_a->index <= i)
        {
            pb(basis);
            rb(basis);
            i++;
        }
        else if (basis->stack_a->index <= i + range)
        {
            pb(basis);
            i++;
        }
        else
            ra(basis);
    }

    while (basis->stack_b)
    {
        move_max_to_top_b(basis);
        pa(basis);
    }
}