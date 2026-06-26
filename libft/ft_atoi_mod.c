

#include "push_swap.h"
//deleting spaces (actually, counts) at the begining of the string
static int	del_spaces(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

//checking if the number between INT_MIN and INT_MAX (returns 1 if yes and 0 otherwise)
static int not_overflow(int res, char s, int zn)
{
	long a;

	a = ((long)res * 10 + (s - 48)) * zn;
	if (a > 2147483647 || a < -2147483648)
		return (0);
	return (1);
}

//returns 1 if string is correctly converted to int and 0 otherwise
int	ft_atoi_mod(const char *str, int *res)
{
	int			i;
	int			zn;

	zn = 1;
	*res = 0;
	i = del_spaces(str);
	if (str[i] == '-' || str[i] == '+')
	{
        if (str[i] == '-')
			zn = -1 * zn;
		i++;
	}
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0' && (str[i] > 47 && str[i] < 58))
	{
		if (not_overflow(*res, str[i], zn))
			*res = *res * 10 + (str[i] - 48);
		else
			return (0);
		i++;
	}
	*res *= zn;
	return (str[i] == '\0');
}