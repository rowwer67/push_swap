/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrezden <abrezden@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 17:03:38 by abrezden          #+#    #+#             */
/*   Updated: 2026/06/28 15:09:01 by abrezden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_it(int argc, char **argv, t_stack_data *basis)
{
	int	i;
	int	new_el;
	int	err;

	if (argc < 2)
		return (1);
	i = 1;
	new_el = 0;
	i = flags_set(argc, argv, basis);
	if (i >= argc)
		return (1);
	while (i < argc)
	{
		if (!ft_atoi_mod(argv[i], &new_el))
			return (3);
		err = add_number(basis, new_el);
		if (err)
			return (err);
		i++;
	}
	return (0);
}

/*
int	parse_it(int argc, char **argv, t_stack_data *basis)
{
	int	i;
	int	new_el;

	i = 1;
	new_el = 0;
	i = i + mode_set(argv[1], basis);
	i = i + strategy_set(argv[i], basis);
	if (i >= argc)
		return (1);
	while (i < argc)
	{
		if (ft_atoi_mod(argv[i], &new_el))
		{
			if (no_duplicates(new_el, basis->stack_a))
			{
				ft_lstadd_back(&basis->stack_a, ft_lstnew(new_el));
				basis->st_size++;
			}
			else
				return (2);
		}
		else
			return (3);
		i++;
	}
	return (0);
}
*/