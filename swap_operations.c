/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrezden <abrezden@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 12:05:08 by abrezden          #+#    #+#             */
/*   Updated: 2026/06/11 13:20:31 by abrezden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_top_elements(t_stack *stack)
{
    int t;

    if (!stack || !stack->next)
        return ;
    t = stack->value;
    stack->value = stack->next->value;
    stack->next->value = t;
}

void sa(t_stack *a)
{
    swap_top_elements(a);
}

void sb(t_stack *a)
{
    swap_top_elements(b);
}

void ss(t_stack *a, t_stack *b)
{
    swap_top_elements(a);
    swap_top_elements(b);
}
