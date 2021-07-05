#include "ft_philosophers.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

unsigned long long int	ovrloading_protection(
	unsigned long long int n, int sign)
{
	if (n > 9223372036854775807)
	{
		if (sign > 0)
			n = -1;
		else if (sign < 0)
			n = 0;
	}
	return (n);
}

int	ft_atoi(const char *str)
{
	int						i;
	int						sign;
	unsigned long long int	number;

	i = 0;
	number = 0;
	sign = 1;
	while (str[i] == 32 || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == '\n')
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			sign *= (-1);
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		number = number * 10 + (str[i] - 48);
		i++;
	}
	number = ovrloading_protection(number, sign);
	return (sign * (int)number);
}
