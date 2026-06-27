/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrezden <abrezden@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 17:03:38 by abrezden          #+#    #+#             */
/*   Updated: 2026/06/26 17:04:27 by abrezden         ###   ########.fr       */
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
		basis->strat_num = 4;
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
	basis->mode = 0;
	return (0);
}

static int	add_number(t_stack_data *basis, int new_el)
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

int	parse_it(int argc, char **argv, t_stack_data *basis)
{
	int	i;
	int	new_el;
	int	err;

	if (argc < 2)
		return (1);
	i = 1;
	new_el = 0;
	i = i + mode_set(argv[i], basis);
	if (i < argc)
		i = i + strategy_set(argv[i], basis);
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