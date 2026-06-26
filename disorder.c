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

void calculate_disorder(t_stack_data *basis)
{
    t_list *a1;
    t_list *a2;
    int mistakes;
    int total_pairs;

    if (!basis || !basis->stack_a || !basis->stack_a->next )
    {
		basis->disord = 0.0;
		return ;
	}
    mistakes = 0;
    total_pairs = 0;
    a1 = basis->stack_a;
    while (a1)
    {
        a2 = a1->next;
        while (a2)
        {
            total_pairs += 1;
            if (a1->value > a2->value)
                mistakes += 1;
            a2 = a2->next;
         }
         a1 = a1->next;
    }
    basis->disord = (double)mistakes / total_pairs;
    return ;
}

void set_adaptive(t_stack_data *basis)
{
    if (basis->disord < 0.2)
        basis->strat_num = 1;
    else if (basis->disord < 0.5)
        basis->strat_num = 2;
    else basis->strat_num = 3;
}
