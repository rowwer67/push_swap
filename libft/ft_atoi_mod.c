
//может просто взять atol ?

// возвращает 1, если всё ок, и 0, если число вышло за границы int
int	safe_atoi(const char *str, int *result)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!*str)
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		if ((sign * num) > 2147483647 || (sign * num) < -2147483648)
			return (0);
		str++;
	}
	*result = (int)(num * sign);
	return (1);
}
