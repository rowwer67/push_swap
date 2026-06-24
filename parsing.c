#include "push_swap.h"

int strategy_set(char *s, t_stack_data *basis)
{
    if (s == "--simple")  //иф (ft_strcmp(s, "--simple") == 0) чи не 
        basis->strat_num = 1;
    else if (s == "--medium")
        basis->strat_num = 2;
    else if (s == "--complex")
        basis->strat_num = 3;   
    else if (s == "--adaptive")
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
	if (s == "--bench")
	{
	        *basis->mode = "bench";
	        return (1);
	}
        basis->mode = "norm";
        return (0);
}


// return 0 if everything parsed correctly, otherweise error number
int    parse_it(size_t argc, char **argv, t_stack_data *basis)
{
    size_t i;
    int new_el;
        
    i = 0;
    new_el = 0;
    i = i + mode_set(argv[0], basis); 
    i = i + strategy_set(argv[i], basis);
    if (i < argc)
        basis->st_size = argc - i; // count number of elements and put to basis->st_size
    else
        {
            //!!! we should return error (no elements in stack)
        }
    while (i < argc)
    {
  // here sould be SPLIT and then atoi inside of it!!!     
       if (ft_atoi_mod(argv[i], &new_el))
       {
            if (no_duplicates(new_el, basis->stack_a)) //checking for duplicates
                ft_lstadd_back(basis->stack_a, ft_lstnew(&new_el));//writing new element new_el at the end of stack
            else
            {// !!!!!! we schould clean here all the stack, created before and return error (duplicated elements)
            }
        }
        else
        {// !!!!!! we schould clean here all the stack, created before and return error (incorrect element)}
        }
        i++;
    }
    return (0);
}

//вроде такой надо парсинг

/*#include "push_swap.h"

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

int	no_duplicates(int new_el, t_list *lst)
{
	while (lst)
	{
		if (lst->value == new_el)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	mode_set(char *s, t_stack_data *basis)
{
	if (!s)
		return (0);
	if (ft_strcmp(s, "--bench") == 0)
	{
		basis->mode = "bench";
		return (1);
	}
	basis->mode = "norm";
	return (0);
}

int	parse_it(int argc, char **argv, t_stack_data *basis)
{
	int		i;
	int		new_el;
	t_list	*node;

	i = 1;
	basis->st_size = 0;
	basis->mode = "norm";
	basis->strat_num = 4;
	basis->stack_a = NULL;
	basis->stack_b = NULL;
	i += mode_set(argv[i], basis);
	i += strategy_set(argv[i], basis);
	if (i >= argc)
		return (1);
	while (i < argc)
	{
		if (!ft_atoi_mod(argv[i], &new_el))
		{
			free_stack(&basis->stack_a);
			return (2);
		}
		if (!no_duplicates(new_el, basis->stack_a))
		{
			free_stack(&basis->stack_a);
			return (3);
		}
		node = new_node(new_el);
		if (!node)
		{
			free_stack(&basis->stack_a);
			return (4);
		}
		add_back(&basis->stack_a, node);
		basis->st_size++;
		i++;
	}
	return (0);
}*/


