/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_sort_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrezden <abrezden@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 17:02:23 by abrezden          #+#    #+#             */
/*   Updated: 2026/06/26 17:05:52 by abrezden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_by_strategy(t_stack_data *basis)
{
	int	size;

	size = stack_size(basis->stack_a);
	if (size == 2)
		sa(basis);
	else if (size <= 3)
		sort_three(basis);
	else if (size <= 5)
		sort_five(basis);
	else if (basis->strat_num == 1)
		simple_sort(basis);
	else if (basis->strat_num == 2)
		bucket_sort(basis);
	else if (basis->strat_num == 3)
		radix_sort(basis);
	else
		radix_sort(basis);
}
