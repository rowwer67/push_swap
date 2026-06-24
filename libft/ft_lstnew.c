

#include "push_swap.h"

t_list	*ft_lstnew_ps(int value)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1; // Индекс пока не знаем, ставим дефолтный -1
	new_node->next = NULL;
	return (new_node);
}