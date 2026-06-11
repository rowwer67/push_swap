/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrezden <abrezden@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 17:15:32 by abrezden          #+#    #+#             */
/*   Updated: 2026/06/11 19:12:14 by abrezden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double calculate_disorder(t_stack *a)
{
    t_stack *a1;
    int mistakes;
    int total_pairs;

    if (!a || !a->next)
        return (0.0);
    mistakes = 0;
    total_pairs = 0;
    while (a->next)
    {
        a1 = a->next;
        while (a1)
        {
            total_pairs += 1;
            if (a->value > a1->value)
                mistakes += 1;
            a1 = a1->next;
         }
         a = a->next;
    }
    return ((double)mistakes / total_pairs);
}