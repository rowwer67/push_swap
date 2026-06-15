/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrezden <abrezden@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 12:05:08 by abrezden          #+#    #+#             */
/*   Updated: 2026/06/15 19:49:22 by abrezden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_top_elements(t_list *stack)
{
    int t;

    if (!stack || !stack->next)
        return ;
    t = stack->value;
    stack->value = stack->next->value;
    stack->next->value = t;
}

void sa(t_list *a)
{
    swap_top_elements(a);
    write(1, "sa\n", 3);
}

void sb(t_list *b)
{
    swap_top_elements(b);
    write(1, "sb\n", 3);
}

void ss(t_list *a, t_stack *b)
{
    swap_top_elements(a);
    swap_top_elements(b);
    write(1, "ss\n", 3);
}
