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
		basis->mode = "bench";
		return (1);
	}
	basis->mode = "norm";
	return (0);
}


/*
1)на входе только числа? (isdigit)

2)числа влезают в инт (нет оверфлоу, atoi_mod?),

3)создать узлы списка, положить в стэк?

4)проверить дубликаты. если есть - error?
*/


// return 0 if everything parsed correctly, otherweise error number
int    parse_it(size_t argc, char **argv, t_stack_data *basis)
{
    size_t i;
    int new_el;
        
    i = 0;
    new_el = 0;
    i = i + mode_set(argv[0], basis); //1
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
        {// !!!!!! we schould clean here all the stack, created before and return error (incorrect element)
			}
        }
        i++;
    
    return (0);
	}

/*int	parse_and_fill(t_push_swap *app, int ac, char **av)
{
	int		i;
	int		parsed_value;
	t_list	*new_node;

	i = 1; // Начинаем с 1, так как av[0] — это имя программы
	while (i < ac)
	{
		// 1. Проверяем isdigit (вы это уже сделали)
		if (!is_valid_number_string(av[i]))
			return (0); // Ошибка
		
		// 2. Безопасно переводим в int и проверяем границы
		if (!safe_atoi(av[i], &parsed_value))
			return (0); // Ошибка: число слишком большое/маленькое

		// 3. Создаем узел и добавляем в стек
		new_node = ft_lstnew_ps(parsed_value);
		if (!new_node)
			return (0); // Ошибка маллока
		ft_lstadd_back_ps(&(app->stack_a), new_node);
		app->size_a++; // Увеличиваем размер стека в нашей структуре
		
		i++;
	}
	// 4. После того как весь стек собран, проверяем на дубликаты
	if (has_duplicates(app->stack_a))
		return (0); // Ошибка
		
	return (1); // Всё прошло успешно!
}
*/