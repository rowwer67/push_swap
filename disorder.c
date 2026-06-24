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

void calculate_disorder(t_list *a, t_stack_data *basis)
{
    t_list *a1;
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
    basis->disord = (double)mistakes / total_pairs;
    return ;
}

void set_adaptive(t_stack_data *basis)
{
    if (basis->disord < 0.2)
        basis->strat_num == 1;
    else if (basis->disord < 0.5)
        basis->strat_num == 2;
    else basis->strat_num == 3;
}