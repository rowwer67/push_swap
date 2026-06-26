/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrezden <abrezden@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 12:17:50 by abrezden          #+#    #+#             */
/*   Updated: 2026/06/26 17:09:39 by abrezden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_top_elements(t_list **src, t_list **dest)
{
	t_list	*head;

	if (!src || !dest || !*src)
		return (0);
	head = *src;
	*src = (*src)->next;
	head->next = *dest;
	*dest = head;
	return (1);
}

void	pa(t_stack_data *ps)
{
	if (push_top_elements(&ps->stack_b, &ps->stack_a))
	{
		write(1, "pa\n", 3);
		if (ps->mode == 1)
			ps->bench->pa++;
	}
}

void	pb(t_stack_data *ps)
{
	if (push_top_elements(&ps->stack_a, &ps->stack_b))
	{
		write(1, "pb\n", 3);
		if (ps->mode == 1)
			ps->bench->pb++;
	}
}
