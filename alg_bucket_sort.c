#include "push_swap.h"

void bucket_sort(t_list **a, t_list **b)
{
    int size;
    int range;
    int i;

    size = stack_size(*a);

    range = 30;
    i = 0;

    while (*a)
    {
        if ((*a)->index <= i)
        {
            pb(a, b);
            rb(b);
            i++;
        }
        else if ((*a)->index <= i + range)
        {
            pb(a, b);
            i++;
        }
        else
            ra(a);
    }

    while (*b)
    {
        move_max_to_top_b(b);
        pa(a, b);
    }
}