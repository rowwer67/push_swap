/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrezden <abrezden@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 12:22:49 by abrezden          #+#    #+#             */
/*   Updated: 2026/06/26 17:06:32 by abrezden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate_elements(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	first = *stack;
	*stack = (*stack)->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	return (1);
}

void	ra(t_stack_data *ps)
{
	if (rotate_elements(&ps->stack_a))
	{
		write(1, "ra\n", 3);
		if (ps->mode == 1)
			ps->bench->ra++;
	}
}

void	rb(t_stack_data *ps)
{
	if (rotate_elements(&ps->stack_b))
	{
		write(1, "rb\n", 3);
		if (ps->mode == 1)
			ps->bench->rb++;
	}
}

void	rr(t_stack_data *ps)
{
	int	done_a;
	int	done_b;

	done_a = rotate_elements(&ps->stack_a);
	done_b = rotate_elements(&ps->stack_b);
	if (done_a || done_b)
	{
		write(1, "rr\n", 3);
		if (ps->mode == 1)
			ps->bench->rr++;
	}
}
