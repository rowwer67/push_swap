/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrezden <abrezden@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 15:08:37 by abrezden          #+#    #+#             */
/*   Updated: 2026/06/28 15:24:53 by abrezden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	strategy_set(char *s, t_stack_data *basis)
{
	if (!s)
		return (0);
	if (ft_strcmp(s, "--simple") == 0)
		basis->strat_num = 1;
	else if (ft_strcmp(s, "--medium") == 0)
		basis->strat_num = 2;
	else if (ft_strcmp(s, "--complex") == 0)
		basis->strat_num = 3;
	else if (ft_strcmp(s, "--adaptive") == 0)
		basis->strat_num = 4;
	else
	{
		return (0);
	}
	return (1);
}

int	no_duplicates(int new_el, t_list *lst)
{
	while (lst)
	{
		if (lst->value == new_el)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	mode_set(char *s, t_stack_data *basis)
{
	if (!s)
		return (0);
	if (ft_strcmp(s, "--bench") == 0)
	{
		basis->mode = 1;
		return (1);
	}
	return (0);
}

int	add_number(t_stack_data *basis, int new_el)
{
	t_list	*node;

	if (!no_duplicates(new_el, basis->stack_a))
		return (2);
	node = ft_lstnew(new_el);
	if (!node)
		return (3);
	ft_lstadd_back(&basis->stack_a, node);
	basis->st_size++;
	return (0);
}

int	flags_set(int argc, char **argv, t_stack_data *basis)
{
	int	a;

	a = 1;
	while (a < argc && (mode_set(argv[a], basis) || strategy_set(argv[a],
				basis)))
		a++;
	return (a);
}
