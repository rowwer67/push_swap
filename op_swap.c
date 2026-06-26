/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrezden <abrezden@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 12:05:08 by abrezden          #+#    #+#             */
/*   Updated: 2026/06/26 17:06:42 by abrezden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap_top_elements(t_list *stack)
{
	int	tmp;

	if (!stack || !stack->next)
		return (0);
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
	return (1);
}

void	sa(t_stack_data *ps)
{
	if (swap_top_elements(ps->stack_a))
	{
		write(1, "sa\n", 3);
		if (ps->mode == 1)
			ps->bench->sa++;
	}
}

void	sb(t_stack_data *ps)
{
	if (swap_top_elements(ps->stack_b))
	{
		write(1, "sb\n", 3);
		if (ps->mode == 1)
			ps->bench->sb++;
	}
}

void	ss(t_stack_data *ps)
{
	int	done_a;
	int	done_b;

	done_a = swap_top_elements(ps->stack_a);
	done_b = swap_top_elements(ps->stack_b);
	if (done_a || done_b)
	{
		write(1, "ss\n", 3);
		if (ps->mode == 1)
			ps->bench->ss++;
	}
}
