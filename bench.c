/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrezden <abrezden@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 17:02:32 by abrezden          #+#    #+#             */
/*   Updated: 2026/06/26 18:13:53 by abrezden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	total_ops(t_bench *b)
{
	if (!b)
		return (0);
	return (b->sa + b->sb + b->ss + b->pa + b->pb + b->ra + b->rb + b->rr
		+ b->rra + b->rrb + b->rrr);
}

char	*get_strategy(t_stack_data *basis)
{
	if (basis->strat_num == 1)
		return ("Simple");
	if (basis->strat_num == 2)
		return ("Medium");
	if (basis->strat_num == 3)
		return ("Complex");
	if (basis->strat_num == 4)
		return ("Adaptive");
	return ("Unknown");
}

char	*get_complexity(t_stack_data *basis)
{
	if (basis->strat_num == 1)
		return ("O(n²)");
	if (basis->strat_num == 2)
		return ("O(n√n)");
	if (basis->strat_num == 3)
		return ("O(n log n)");
	if (basis->strat_num == 4)
		return ("Adaptive");
	return ("Unknown");
}

void	print_b(char *str, int nbr)
{
	ft_putstr_fd(str, 2);
	ft_putnbr_fd(nbr, 2);
	return ;
}

void	print_bench(t_stack_data *basis)
{
	if (!basis || basis->mode == 0)
		return ;
	ft_putstr_fd("[bench] disorder: ", 2);
	disorder_percentage(basis->disord);
	ft_putstr_fd("%\n[bench] strategy:  ", 2);
	ft_putstr_fd(get_strategy(basis), 2);
	ft_putstr_fd(" / ", 2);
	ft_putstr_fd(get_complexity(basis), 2);
	ft_putstr_fd("\n[bench] total_ops: ", 2);
	ft_putnbr_fd((int)total_ops(basis->bench), 2);
	print_b("\n[bench] sa: ", basis->bench->sa);
	print_b(" sb: ", basis->bench->sb);
	print_b(" ss: ", basis->bench->ss);
	print_b(" pa: ", basis->bench->pa);
	print_b(" pb: ", basis->bench->pb);
	print_b("\n[bench] ra: ", basis->bench->ra);
	print_b(" rb: ", basis->bench->rb);
	print_b(" rr: ", basis->bench->rr);
	print_b(" rra: ", basis->bench->rra);
	print_b(" rrb: ", basis->bench->rrb);
	print_b(" rrr: ", basis->bench->rrr);
	ft_putstr_fd("\n", 2);
}
