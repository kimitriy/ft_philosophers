#include "ft_philosophers.h"

int	main(int argc, char **argv)
{
	t_prime	*p;

	p = (t_prime *)ft_calloc(1, sizeof(t_prime));
	if (prsr(argc, argv, p))
	{
		write(1, "args are OK!\n", 13);
	}
	else
	{
		write(1, "args are not OK!\n", 17);
		exit (1);
	}
	while (1)
	{
		
	}
	
	return (0);
}