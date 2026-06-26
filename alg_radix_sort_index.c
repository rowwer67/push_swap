#include "push_swap.h"

static int	*stack_to_array(t_list *a, int size)
{
	int		*arr;
	int		i;

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
	int t;

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

void	assign_indexes(t_list *a)
{
	t_list	*node;
	int		*arr;
	int		i;
	int	size;

	size = stack_size(a);
	arr = stack_to_array(a, size);

	if (!arr)
		return ;

	sort_array(arr, size);

	node = a;
	while (node)
	{
		i = 0;
		while (i < size)
		{
			if (arr[i] == node->value)
			{
				node->index = i;
				break ;
			}
			i++;
		}
		node = node->next;
	}
	free(arr);
}