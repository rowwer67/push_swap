/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrezden <abrezden@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 11:34:17 by abrezden          #+#    #+#             */
/*   Updated: 2026/06/11 19:05:54 by abrezden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_stack
{
    int value;
    struct s_stack  *next;
}   t_stack;

typedef struct s_stack_data
{
    size_t st_size;
    char *mode;
    int min;
    int max;
    int strat_num;
    char *mode;
    t_list *stack_a;
}   t_stack_data;

