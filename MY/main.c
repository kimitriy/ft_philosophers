#include "ft_philosophers.h"

void	mtx_init(t_prime *p)
{
	int		i;

	p->arr_frk = (pthread_mutex_t *)ft_calloc(p->n_ph, sizeof(pthread_mutex_t)); //allocates memory to p->arr_frk
	i = 0;
	while (i < p->n_ph)
	{
		if (pthread_mutex_init(&p->arr_frk[i], NULL)) //initializes fork mutexes
			err_message("Mutex was not initialised");
		i++;
	}
	if (pthread_mutex_init(&p->prnt_mtx, NULL)) //initializes mutex that is using while printing phi status in order to none of the philosophers change its status during this printing
		err_message("Mutex was not initialised");
}

void	ph_init(t_prime *p, int ix)
{
	p->arr_ph[ix].indx = ix;
	p->arr_ph[ix].alive = 1;
	p->arr_ph[ix].has_eatn = 0;
	p->arr_ph[ix].t2d = &p->t2d;
	p->arr_ph[ix].t2e = &p->t2e;
	p->arr_ph[ix].t2s = &p->t2s;
	p->arr_ph[ix].lfrk = &p->arr_frk[ix]; //lfrk points to ix element of the arr_frk
	if (ix + 1 == p->n_ph) //for the last philosopher
		p->arr_ph[ix].rfrk = &p->arr_frk[0]; //the right fork is the same as left fork for the first ph
	else //for all rest philosophers
		p->arr_ph[ix].rfrk = &p->arr_frk[ix + 1];
	p->arr_ph[ix].p_mtx = &p->prnt_mtx; //set the address of prnt_mtx to p_mtx pointer of each philosopher
}

void	arr_ph_init(t_prime *p)
{
	int		ix; //ph index

	p->arr_ph = (t_phlsphr *)ft_calloc(p->n_ph, sizeof(t_phlsphr));
	ix = 0;
	while (ix < p->n_ph)
	{
		ph_init(p, ix);
		ix++;
	}
}

int	main(int argc, char **argv)
{
	t_prime	*p;

	p = (t_prime *)ft_calloc(1, sizeof(t_prime));
	if (prsr(argc, argv, p))
	{
		write(1, "args are OK!\n", 13);
		mtx_init(p);
		arr_ph_init(p);
		launch_threads(p);
		monitor(p);
	}
	else
	{
		write(1, "args are not OK!\n", 17);
		exit (1);
	}
	// while (1)
	// {
		
	// }
	
	return (0);
}