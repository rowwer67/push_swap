/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrezden <abrezden@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 12:17:50 by abrezden          #+#    #+#             */
/*   Updated: 2026/06/15 19:51:35 by abrezden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}*/

void push_top_elements(t_list **src, t_list **dest)
{
    t_stack *head;

    if (!src || !dest)
        return ;
    head = *src;
    *src = (*src)->next;
    head->next = *dest;
    *dest = head;
}

void pa(t_list *a, t_list *b)
{
    push_top_elements(b, a);
    write(1, "pa\n", 3);
}

void pb(t_list *a, t_list *b)
{
    push_top_elements(a, b);
    write(1, "pb\n", 3);
}