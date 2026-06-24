#include "push_swap.h"

void sort_stack(t_list **a, t_list **b)
{
    int size;

    size = stack_size(*a);

    if (size == 2)
        sa(a);
    if (size <= 3)
        sort_three(a);
    else if (size <= 5)
        sort_five(a, b);
    else if (size <= 100)
        bucket_sort(a, b);
    else
        bucket_sort_500(a, b);
}

/*#include "push_swap.h"

void	sort_stack(t_list **a, t_list **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
	else
		radix_sort(a, b);
}*/