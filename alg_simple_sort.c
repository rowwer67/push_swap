/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_simple_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrezden <abrezden@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 17:02:07 by abrezden          #+#    #+#             */
/*   Updated: 2026/06/26 17:02:16 by abrezden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	move_min_to_top(t_stack_data *basis)
{
	int	pos;
	int	size;

	pos = min_pos(basis->stack_a);
	size = stack_size(basis->stack_a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(basis);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rra(basis);
	}
}

void	sort_three(t_stack_data *basis)
{
	int	first;
	int	second;
	int	third;

	if (is_sorted(basis->stack_a))
		return ;
	first = basis->stack_a->index;
	second = basis->stack_a->next->index;
	third = basis->stack_a->next->next->index;
	if (first > second && second < third && first < third)
		sa(basis);
	else if (first > second && second > third)
	{
		sa(basis);
		rra(basis);
	}
	else if (first > second && second < third && first > third)
		ra(basis);
	else if (first < second && second > third && first < third)
	{
		sa(basis);
		ra(basis);
	}
	else if (first < second && second > third && first > third)
		rra(basis);
}

void	sort_five(t_stack_data *basis)
{
	while (stack_size(basis->stack_a) > 3)
	{
		move_min_to_top(basis);
		pb(basis);
	}
	sort_three(basis);
	while (basis->stack_b)
		pa(basis);
}

void	simple_sort(t_stack_data *basis)
{
	while (basis->stack_a)
	{
		move_min_to_top(basis);
		pb(basis);
	}
	while (basis->stack_b)
		pa(basis);
}
