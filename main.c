#include "ft_philosophers.h"

void	mtx_init(t_prime *p)
{
	int		i;

	p->arr_frk = (pthread_mutex_t *)ft_calloc(p->n_ph, sizeof(pthread_mutex_t));
	i = 0;
	while (i < p->n_ph)
	{
		if (pthread_mutex_init(&p->arr_frk[i], NULL))
			err_message("Mutex was not initialised");
		i++;
	}
}

/*lfrk points to ix element of the arr_frk
for the last philosopher the right fork is the same as left fork for the first ph
for all the rest philosophers the right fork is the fork with index ix + 1*/
void	ph_init(t_prime *p, int ix)
{
	p->arr_ph[ix].indx = ix;
	p->arr_ph[ix].has_eatn = 0;
	p->arr_ph[ix].t2d = &p->t2d;
	p->arr_ph[ix].t2e = &p->t2e;
	p->arr_ph[ix].t2s = &p->t2s;
	p->arr_ph[ix].lfrk = &p->arr_frk[ix];
	if (ix + 1 == p->n_ph)
		p->arr_ph[ix].rfrk = &p->arr_frk[0];
	else
		p->arr_ph[ix].rfrk = &p->arr_frk[ix + 1];
	p->arr_ph[ix].has_eatn = 0;
}

void	arr_ph_init(t_prime *p)
{
	int		ix;

	p->arr_ph = (t_phlsphr *)ft_calloc(p->n_ph, sizeof(t_phlsphr));
	ix = 0;
	while (ix < p->n_ph)
	{
		ph_init(p, ix);
		ix++;
	}
}

void	free_p(t_prime *p)
{
	int	i;

	i = 0;
	while (i < p->n_ph)
	{
		pthread_mutex_destroy(&p->arr_frk[i]);
		i++;
	}
	free(p->arr_frk);
	free(p->arr_ph);
	free(p->ph_ptid);
	free(p);
}

int	main(int argc, char **argv)
{
	t_prime	*p;

	p = (t_prime *)ft_calloc(1, sizeof(t_prime));
	if (prsr(argc, argv, p))
	{
		mtx_init(p);
		arr_ph_init(p);
		launch_threads(p);
		monitor(p);
		free_p(p);
	}
	return (0);
}
