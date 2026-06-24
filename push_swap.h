/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrezden <abrezden@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 11:34:17 by abrezden          #+#    #+#             */
/*   Updated: 2026/06/24 15:28:13 by abrezden         ###   ########.fr       */
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
    size_t st_size;	    //stack size
   // int min;
  //  int max;
    double  disord;
    int strat_num;	    //strategy (1=simple, 2=medium, 3=complex, 4=adaptive)
    int mode;		    //mode (1 = bench and 0 = norm)
    t_list *stack_a;	//pointer to head of stack a
   // int total_ops;	    //??? we can count it as sum s_bench
}   t_stack_data;

/*
typedef struct s_push_swap
{
	t_list	*stack_a;    // Голова стека А
	t_list	*stack_b;    // Голова стека Б
	size_t	size_a;     // Текущий размер стека А
	size_t	size_b;     // Текущий размер стека Б
	size_t	total_ops;  // Счетчик всех проведенных операций
	t_strat	strategy;   // Выбранная стратегия для бенчмарка
}	t_push_swap;
*/

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


// CHECK THE FUNCTIONS LIST!!! A lot of incorrect functions

void	sa(t_list **a);     // !!!!!! void sa(t_list *a)
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

int		parse_args(int argc, char **argv, t_list **a);  //???????
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

