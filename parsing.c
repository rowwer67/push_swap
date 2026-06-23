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
		if (lst->content == new_el)
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




