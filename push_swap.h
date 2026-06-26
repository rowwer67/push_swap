/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrezden <abrezden@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 11:34:17 by abrezden          #+#    #+#             */
/*   Updated: 2026/06/26 17:48:02 by abrezden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}					t_list;

typedef struct s_bench
{
	size_t			sa;
	size_t			sb;
	size_t			ss;
	size_t			pa;
	size_t			pb;
	size_t			ra;
	size_t			rb;
	size_t			rr;
	size_t			rra;
	size_t			rrb;
	size_t			rrr;
}					t_bench;

typedef struct s_stack_data
{
	size_t			st_size;
	double			disord;
	int				strat_num;
	int				mode;
	t_list			*stack_a;
	t_list			*stack_b;

	t_bench			*bench;

}					t_stack_data;

void				sa(t_stack_data *basis);
void				sb(t_stack_data *basis);
void				ss(t_stack_data *basis);
void				pa(t_stack_data *basis);
void				pb(t_stack_data *basis);
void				ra(t_stack_data *basis);
void				rb(t_stack_data *basis);
void				rr(t_stack_data *basis);
void				rra(t_stack_data *basis);
void				rrb(t_stack_data *basis);
void				rrr(t_stack_data *basis);

/* parsing */
int					parse_it(int argc, char **argv, t_stack_data *basis);

/* list utils */
t_list				*ft_lstnew(int value);
void				ft_lstadd_back(t_list **lst, t_list *new_node);
void				free_stack(t_list **stack);
int					stack_size(t_list *s);
int					is_sorted(t_list *a);

/* indexes */
void				assign_indexes(t_list *a);

/* disorder */
void				calculate_disorder(t_stack_data *bsis);
void				set_adaptive(t_stack_data *basis);
void				disorder_percentage(double dis);

/* sorting */
void				sort_by_strategy(t_stack_data *bsis);
void				simple_sort(t_stack_data *basis);
void				bucket_sort(t_stack_data *basis);
void				radix_sort(t_stack_data *basis);
void				sort_three(t_stack_data *basis);
void				sort_five(t_stack_data *basis);

/* bucket utils */
void				move_max_to_top_b(t_stack_data *basis);
int					get_chunk_size(int size);

/* bench */
void				print_bench(t_stack_data *basis);

/* libft */
int					ft_atoi_mod(const char *str, int *res);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
size_t				ft_strlen(const char *str);

void				init_data(t_stack_data *basis);
void				error_exit(t_stack_data *basis);

#endif
