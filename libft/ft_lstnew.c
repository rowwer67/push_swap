#include "libft.h"

t_list	*ft_lstnew(int *content)
{
	t_list	*new_n;

	new_n = malloc(sizeof(t_list));
	if (!new_n)
		return (NULL);
	new_n->content = content;
	new_n->next = NULL;
	return (new_n);
}