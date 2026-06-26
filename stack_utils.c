#include "push_swap.h"

int	stack_size(t_list *s)
{
	int	count;

	count = 0;
	while (s)
	{
		count++;
		s = s->next;
	}
	return (count);
}

int	is_sorted(t_list *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

void	free_stack(t_list **stack)
{
	t_list	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}