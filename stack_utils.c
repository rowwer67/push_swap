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

void	init_data(t_stack_data *basis)
{
	basis->st_size = 0;
	basis->stack_a = NULL;
	basis->stack_b = NULL;
	basis->disord = 0.0;
	basis->strat_num = 4;
	basis->mode = 0;
	basis->bench->sa = 0;
	basis->bench->sb = 0;
	basis->bench->ss = 0;
	basis->bench->pa = 0;
	basis->bench->pb = 0;
	basis->bench->ra = 0;
	basis->bench->rb = 0;
	basis->bench->rr = 0;
	basis->bench->rra = 0;
	basis->bench->rrb = 0;
	basis->bench->rrr = 0;
}

void	error_exit(t_stack_data *basis)
{
	free_stack(&basis->stack_a);
	free_stack(&basis->stack_b);
	write(2, "Error\n", 6);
	return ;
}