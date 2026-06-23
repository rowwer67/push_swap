static int	*stack_to_array(t_stack *a)
{
	t_node	*tmp;
	int		*arr;
	int		i;

	arr = malloc(sizeof(int) * a->size);
	if (!arr)
		return (NULL);
	tmp = a->top;
	i = 0;
	while (tmp)
	{
		arr[i++] = tmp->value;
		tmp = tmp->next;
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

void	assign_indexes(t_stack *a)
{
	t_node	*node;
	int		*arr;
	int		i;

	arr = stack_to_array(a);
	sort_array(arr, a->size);

	node = a->top;
	while (node)
	{
		i = 0;
		while (i < a->size)
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