/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_bucket_sort_functions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrezden <abrezden@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 16:51:05 by abrezden          #+#    #+#             */
/*   Updated: 2026/06/28 15:24:29 by abrezden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_pos(t_list *b)
{
	int	pos;
	int	max_pos;
	int	max_idx;

	pos = 0;
	max_pos = 0;
	max_idx = b->index;
	while (b)
	{
		if (b->index > max_idx)
		{
			max_idx = b->index;
			max_pos = pos;
		}
		pos++;
		b = b->next;
	}
	return (max_pos);
}

void	move_max_to_top_b(t_stack_data *basis)
{
	int	pos;
	int	size;

	pos = find_max_pos(basis->stack_b);
	size = stack_size(basis->stack_b);
	if (pos <= size / 2)
	{
		while (pos--)
			rb(basis);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rrb(basis);
	}
}

int	get_chunk_size(int size)
{
	int	a;

	a = 1;
	while ((a * a) < size)
		a++;
	return (a);
}
