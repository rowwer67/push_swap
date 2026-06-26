#include "push_swap.h"

static int	reverse_rotate_elements(t_list **stack)
{
	t_list	*prev;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
	return (1);
}

void	rra(t_stack_data *ps)
{
	if (reverse_rotate_elements(&ps->stack_a))
	{
		write(1, "rra\n", 4);
		if (ps->mode == 1)
			ps->bench.rra++;
	}
}

void	rrb(t_stack_data *ps)
{
	if (reverse_rotate_elements(&ps->stack_b))
	{
		write(1, "rrb\n", 4);
		if (ps->mode == 1)
			ps->bench.rrb++;
	}
}

void	rrr(t_stack_data *ps)
{
	int	done_a;
	int	done_b;

	done_a = reverse_rotate_elements(&ps->stack_a);
	done_b = reverse_rotate_elements(&ps->stack_b);
	if (done_a || done_b)
	{
		write(1, "rrr\n", 4);
		if (ps->mode == 1)
			ps->bench.rrr++;
	}
}