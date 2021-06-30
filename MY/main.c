#include "ft_philosophers.h"

void	mtx_init(t_prime *p)
{
	int		i;

	p->arr_mtx = (pthread_mutex_t *)ft_calloc(p->n_ph, sizeof(pthread_mutex_t));
	p->arr_ff = (int *)ft_calloc(p->n_ph, sizeof(int));
	i = 0;
	while (i < p->n_ph)
	{
		if (pthread_mutex_init(&p->arr_mtx[i], NULL)) //initializes mutex
			err_message("Mutex was not initialised");
		p->arr_ff[i] = 1; //sets fork (mutex) as available (unlocked)
		i++;
	}
	if (pthread_mutex_init(&p->prnt_mtx, NULL))
		err_message("Mutex was not initialised");
}

void	ph_init(t_prime *p, int ix)
{
	p->arr_ph[ix].indx = ix;
	p->arr_ph[ix].alive = 1;
	p->arr_ph[ix].pr = &p->mntr.pr[ix]; //points to pr array in t_mntr struct
	p->arr_ph[ix].t2d = &p->t2d;
	p->arr_ph[ix].t2e = &p->t2e;
	p->arr_ph[ix].t2s = &p->t2s;
	p->arr_ph[ix].lf_mtx = &p->arr_mtx[ix]; //assigns address of arr_mtx[ix] as the left fork mutex
	p->arr_ph[ix].lf_f = &p->arr_ff[ix]; //assigns address of arr_ff[ix] as the left fork's status (0 or 1)
	if (ix + 1 == p->n_ph) //for the last philosopher
	{
		p->arr_ph[ix].rf_mtx = &p->arr_mtx[0]; //the right fork is the same as left fork for the first ph
		p->arr_ph[ix].rf_f = &p->arr_ff[0]; //assigns address of arr_ff[0] as the left fork's status (0 or 1)
	}
	else //for all rest philosophers
	{
		p->arr_ph[ix].rf_mtx = &p->arr_mtx[ix + 1];
		p->arr_ph[ix].rf_f = &p->arr_ff[ix + 1];
	}
	p->arr_ph[ix].p_mtx = &p->prnt_mtx; //set the address of prnt_mtx to p_mtx pointer of each philosopher
	p->arr_ph[ix].have_eatn = 0;
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

void	mntr_init(t_prime *p)
{
	int	i;

	p->mntr.h = 10;
	p->mntr.m = 20;
	p->mntr.l = 30;
	p->mntr.ch_pr_f = 0;
	p->mntr.pr = (int *)ft_calloc(p->n_ph, sizeof(int));
	p->mntr.n_mls_ate = (int *)ft_calloc(p->n_ph, sizeof(int));
	i = 0;
	while (i < p->n_ph)
	{
		p->mntr.pr[i] = p->mntr.h;
		p->mntr.n_mls_ate[i] = 0;
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
		mtx_init(p);
		mntr_init(p);
		arr_ph_init(p);
		launch_threads(p);
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