#include "ft_philosophers.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*mem;

	mem = s;
	i = 0;
	while (i < n)
	{
		mem[i] = '\0';
		i++;
	}
}

int	err_message(char *error)
{
	write(1, "Error! ", 7);
	write(1, error, ft_strlen(error));
	write(1, "\n", 1);
	return (0);
}

void	err_memory_allocation_error(void)
{
	write(1, "Error!\n", 7);
	write(1, "Memory allocation error!\n", 25);
	exit(2);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*pntr;

	pntr = (void *)malloc(count * size);
	if (NULL == pntr)
		err_memory_allocation_error();
	ft_bzero(pntr, count * size);
	return (pntr);
}

int	ft_strlen(const char *s)
{
	int		i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

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
	int					i;
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

void	ft_putnbr(unsigned int n)
{
	char	ch;
	
	// if (n == -2147483648)
	// 	write(1, "-2147483648", 11);
	// else if (n < 0)
	// {
	// 	write(1, "-", 1);
	// 	ft_putnbr(n * (-1));
	// }
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{	
		ch = n + '0';
		write(1, &ch, 1);
	}
}

int		arr_min(int *arr)
{
	int	rv;
	int	i;

	i = 0;
	rv = arr[i];
	while (arr[++i])
	{
		if (arr[i] < rv)
			rv = arr[i];
	}
	return (rv);
}