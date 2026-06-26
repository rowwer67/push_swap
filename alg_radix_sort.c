#include "push_swap.h"

static int	get_max_bits(t_list *a)
{
	int		max;
	int		bits;

	max = 0;
	while (a)
	{
		if (a->index > max)
			max = a->index;
		a = a->next;
	}

	bits = 0;
	while ((max >> bits) != 0)
		bits++;

	return (bits);
}

void	radix_sort(t_stack_data *basis)
{
	int	max_bits;
	int	i;
	int	j;
	int	size;

	size = stack_size(basis->stack_a);
	max_bits = get_max_bits(basis->stack_a);

	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((basis->stack_a->index >> i) & 1) == 1)
				ra(basis);
			else
				pb(basis);
			j++;
		}
		while (basis->stack_b)
			pa(basis);
		i++;
	}
}
