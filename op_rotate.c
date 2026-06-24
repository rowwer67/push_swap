/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrezden <abrezden@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 12:22:49 by abrezden          #+#    #+#             */
/*   Updated: 2026/06/23 15:52:25 by abrezden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotate_elements(t_list **stack)
{
    t_list *first;
    t_list *last;

    if (!stack || !*stack || !(*stack)->next)
        return;

    first = *stack;
    *stack = (*stack)->next;
    first->next = NULL;
    last = *stack; //ВРЕМЕННО УКАЗЫВАЕТ НА ГОЛОВУ
    while (last->next)
		last = last->next;
	last->next = first;
	return ;
    
}

void    ra(t_list *a)
{
    rotate_elements(a);
    write(1, "ra\n", 3);
}

void    rb(t_list *b)
{
    rotate_elements(b);
    write(1, "rb\n", 3);
}

void    rr(t_list *a, t_list *b)
{
    rotate_elements(a);
    rotate_elements(b);
    write(1, "rr\n", 3);
}