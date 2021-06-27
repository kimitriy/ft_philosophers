#include "ft_philosophers.h"

void	arr_mtx_init(t_prime *p)
{
	int		i;

	i = 0;
	while (i < p->n_ph)
	{
		if (pthread_mutex_init(p->arr_mtx[i], NULL))
			err_message("Mutex was not initialised");
		i++;
	}	
}

void	ph_init(t_prime *p, int indx)
{
	p->arr_ph[indx].
}

void	arr_ph_init(t_prime *p)
{
	int		i;

	i = 0;
	while (i < p->n_ph)
	{
		ph_init(p);
		i++;
	}
	
}

int	main(int argc, char **argv)
{
	t_prime	*p;

	p = (t_prime *)ft_calloc(1, sizeof(t_prime));
	if (prsr(argc, argv, p))
	{
		write(1, "args are OK!\n", 13);
		arr_mtx_init(p);
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
