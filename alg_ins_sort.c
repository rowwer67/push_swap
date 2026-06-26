
# include "push_swap.h"

void insertion_sort(t_list **a, t_list **b)
{
    int pos;

    while (*a)
    {
        pos = find_insert_pos_b(*b, (*a)->value);

        rotate_b_to_pos(b, pos);

        pb(a, b);
    }

    pos = max_index(*b);

    rotate_b_to_pos(b, pos);

    while (*b)
        pa(a, b);
}


