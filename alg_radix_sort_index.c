/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_radix_sort_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrezden <abrezden@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 16:54:38 by abrezden          #+#    #+#             */
/*   Updated: 2026/06/26 17:47:55 by abrezden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*stack_to_array(t_list *a, int size)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (a)
	{
		arr[i++] = a->value;
		a = a->next;
	}
	return (arr);
}

static void	swap_int(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

static void	sort_array(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
				swap_int(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}

static int	get_index(int *arr, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (0);
}

void	assign_indexes(t_list *a)
{
	t_list	*node;
	int		*arr;
	int		size;

	size = stack_size(a);
	arr = stack_to_array(a, size);
	if (!arr)
		return ;
	sort_array(arr, size);
	node = a;
	while (node)
	{
		node->index = get_index(arr, size, node->value);
		node = node->next;
	}
	free(arr);
}
