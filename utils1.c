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
