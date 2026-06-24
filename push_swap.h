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
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

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


void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

int		parse_args(int argc, char **argv, t_list **a);
void	assign_indexes(t_list *a);
void	sort_stack(t_list **a, t_list **b);
void	sort_three(t_list **a);
void	sort_five(t_list **a, t_list **b);
void	radix_sort(t_list **a, t_list **b);

int		stack_size(t_list *s);
int		is_sorted(t_list *a);
int		contains_value(t_list *a, int value);
t_list	*new_node(int value);
void	add_back(t_list **lst, t_list *new_node);
void	free_stack(t_list **stack);
void	print_error(void);

#endif

