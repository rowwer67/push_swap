



#include "push_swap.h"

void	reverse_rotate_elements(t_list **stack)
{
	t_list	*prev;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
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
}

void	rra(t_list **a)
{
	reverse_rotate_elements(a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	reverse_rotate_elements(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	reverse_rotate_elements(a);
	reverse_rotate_elements(b);
	write(1, "rrr\n", 4);
}