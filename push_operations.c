/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrezden <abrezden@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 12:17:50 by abrezden          #+#    #+#             */
/*   Updated: 2026/06/11 15:01:37 by abrezden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_top_elements(t_stack **src, t_stack **dest) //тк вершины стека меняются
{
    if (!src || !dest)
        return ;
    
}

void pa(t_stack *a, t_stack *b)
{
    push_top_elements(a, b);
}

void pb(t_stack *a, t_stack *b)
{
    push_top_elements(b, a);
}