/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_ins_sort_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrezden <abrezden@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 17:08:42 by abrezden          #+#    #+#             */
/*   Updated: 2026/06/26 17:10:06 by abrezden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_list *s)
{
	int	i;

	i = 0;
	while (s)
	{
		i++;
		s = s->next;
	}
	return (i);
}

int	max_index(t_list *b)
{
	int	max;
	int	idx;
	int	i;

	max = b->value;
	idx = 0;
	i = 0;
	while (b)
	{
		if (b->value > max)
		{
			max = b->value;
			idx = i;
		}
		b = b->next;
		i++;
	}
	return (idx);
}

int	min_index(t_list *b)
{
	int	min;
	int	idx;
	int	i;

	min = b->value;
	idx = 0;
	i = 0;
	while (b)
	{
		if (b->value < min)
		{
			min = b->value;
			idx = i;
		}
		b = b->next;
		i++;
	}
	return (idx);
}

int	find_insert_pos_b(t_list *b, int value)
{
	int	i;
	int	best_pos;
	int	best_value;

	i = 0;
	best_pos = -1;
	best_value = -2147483648;
	while (b)
	{
		if (b->value < value && b->value > best_value)
		{
			best_value = b->value;
			best_pos = i;
		}
		i++;
		b = b->next;
	}
	if (best_pos != -1)
		return (best_pos + 1);
	return (max_index(b));
}

void	rotate_b_to_pos(t_list **b, int pos)
{
	int	size;

	size = stack_size(*b);
	if (pos <= size / 2)
	{
		while (pos--)
			rb(b);
	}
	else
	{
		pos = size - pos;
		while (pos--)
			rrb(b);
	}
}
