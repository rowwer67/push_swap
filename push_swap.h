/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrezden <abrezden@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 11:34:17 by abrezden          #+#    #+#             */
/*   Updated: 2026/06/23 16:53:33 by abrezden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_list
{
    int value;
    int index;
    struct s_list  *next;
}   t_list;

typedef struct s_stack_data
{
    size_t st_size;
    int min;
    int max;
    int strat_num;
    char *mode;
    t_list *stack_a;
}   t_stack_data;

typedef struct s_bench
{
    size_t sa;
    size_t sb;
    size_t ss;
    size_t pa;
    size_t pb;
    size_t ra;
    size_t rb;
    size_t rr;
    size_t rra;
    size_t rrb;
    size_t rrr;
} t_bench;


#endif