#include "push_swap.h"

int	strategy_set(char *s, t_stack_data *basis)
{
	if (!s)
		return (0);
	if (ft_strcmp(s, "--simple") == 0)
		basis->strat_num = 1;
	else if (ft_strcmp(s, "--medium") == 0)
		basis->strat_num = 2;
	else if (ft_strcmp(s, "--complex") == 0)
		basis->strat_num = 3;
	else if (ft_strcmp(s, "--adaptive") == 0)
		basis->strat_num = 4;
	else
	{
		basis->strat_num = 4;
		return (0);
	}
	return (1);
}

//returns 1 if there is no duplicates 
int no_duplicates(int new_el, t_list *lst)
{
    while (lst)
	{
		if (lst->value == new_el)
            return (0);
		lst = lst->next;
	}
    return (1);
}


//returns 1 if there is --bench setted
int	mode_set(char *s, t_stack_data *basis)
{
	if (!s)
		return (0);
	if (ft_strcmp(s, "--bench") == 0)
	{
		basis->mode = 1;
		return (1);
	}
	basis->mode = 0;
	return (0);
}


// return 0 if everything parsed correctly, otherweise error number
int    parse_it(size_t argc, char **argv, t_stack_data *basis)
{
    size_t i;
    int new_el;
        
    i = 1;
    new_el = 0;
    i = i + mode_set(argv[1], basis); //1 - first argument
    i = i + strategy_set(argv[i], basis);
    if (i >= argc)
    	return (1);// we return error (1 - no elements in arguments)
    while (i < argc)
    {
  // here sould be SPLIT and then atoi inside of it!!!     
       if (ft_atoi_mod(argv[i], &new_el))
       {
            if (no_duplicates(new_el, basis->stack_a)) //checking for duplicates
                ft_lstadd_back(basis->stack_a, ft_lstnew(&new_el));//writing new element new_el at the end of stack
            else
            	return (2);// we return error (2 - duplicated elements)
        }
        else
			return (3);// we return error (3 - incorrect argument)
        i++;
	}
    return (0);
}















/*
#include "push_swap.h"

static int	is_strategy_flag(char *s)
{
	if (ft_strcmp(s, "--simple") == 0)
		return (1);
	if (ft_strcmp(s, "--medium") == 0)
		return (1);
	if (ft_strcmp(s, "--complex") == 0)
		return (1);
	if (ft_strcmp(s, "--adaptive") == 0)
		return (1);
	return (0);
}

static int	set_strategy(char *s, t_stack_data *ps)
{
	if (ft_strcmp(s, "--simple") == 0)
		ps->strat_num = 1;
	else if (ft_strcmp(s, "--medium") == 0)
		ps->strat_num = 2;
	else if (ft_strcmp(s, "--complex") == 0)
		ps->strat_num = 3;
	else if (ft_strcmp(s, "--adaptive") == 0)
		ps->strat_num = 4;
	else
		return (0);
	return (1);
}

static int	is_mode_flag(char *s)
{
	if (ft_strcmp(s, "--bench") == 0)
		return (1);
	return (0);
}

static int	no_duplicates(int new_el, t_list *lst)
{
	while (lst)
	{
		if (lst->value == new_el)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	parse_it(int argc, char **argv, t_stack_data *ps)
{
	int	i;
	int	new_el;
	int	strategy_seen;

	i = 1;
	strategy_seen = 0;
	while (i < argc)
	{
		if (is_mode_flag(argv[i]))
			ps->mode = 1;
		else if (is_strategy_flag(argv[i]))
		{
			if (strategy_seen)
				return (1);
			if (!set_strategy(argv[i], ps))
				return (1);
			strategy_seen = 1;
		}
		else
		{
			if (!ft_atoi_mod(argv[i], &new_el))
				return (1);
			if (!no_duplicates(new_el, ps->stack_a))
				return (1);
			ft_lstadd_back(&ps->stack_a, ft_lstnew(new_el));
			ps->st_size++;
		}
		i++;
	}
	if (ps->st_size == 0)
		return (1);
	return (0);
}
	*/