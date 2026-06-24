#include "push_swap.h"

// if stack b is empty - pa
// if first a_elem 

//while (stack_a->content>

#include "push_swap.h"

static int	min_pos(t_list *a)
{
	int	pos;
	int	best_pos;
	int	min;

	pos = 0;
	best_pos = 0;
	min = a->index;
	while (a)
	{
		if (a->index < min)
		{
			min = a->index;
			best_pos = pos;
		}
		a = a->next;
		pos++;
	}
	return (best_pos);
}

static void	move_min_to_top(t_list **a)
{
	int	pos;
	int	size;

	pos = min_pos(*a);
	size = stack_size(*a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(a);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rra(a);
	}
}

void	sort_three(t_list **a)
{
	int	first;
	int	second;
	int	third;

	if (is_sorted(*a))
		return ;
	first = (*a)->index;
	second = (*a)->next->index;
	third = (*a)->next->next->index;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	sort_five(t_list **a, t_list **b)
{
	while (stack_size(*a) > 3)
	{
		move_min_to_top(a);
		pb(a, b);
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}