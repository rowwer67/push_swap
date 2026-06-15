/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrezden <abrezden@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 11:34:17 by abrezden          #+#    #+#             */
/*   Updated: 2026/06/15 20:02:02 by abrezden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_list
{
    int value;
    struct s_list  *next;
}   t_list;

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

