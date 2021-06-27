#include "ft_philosophers.h"

void	arr_mtx_init(t_prime *p)
{
	int		i;

	i = 0;
	while (i < p->n_ph)
	{
		if (pthread_mutex_init(&p->arr_mtx[i], NULL))
			err_message("Mutex was not initialised");
		i++;
	}	
}

void	ph_init(t_prime *p, int ix)
{
	p->arr_ph[ix].indx = ix;
	p->arr_ph[ix].alive = 1;
	p->arr_ph[ix].pr = 1; //sets initial priority equal to the highest level
	p->arr_ph[ix].t2d = &p->t2d;
	p->arr_ph[ix].t2e = &p->t2e;
	p->arr_ph[ix].t2s = &p->t2s;
	p->arr_ph[ix].lf_mtx = &p->arr_mtx[ix]; //assigns address of arr_mtx[ix] as the left fork mutex
	p->arr_ph[ix].lf_f = &p->arr_ff[ix]; //assigns address of arr_ff[ix] as the left fork's status (0 or 1)
	if (ix + 1 == p->n_ph) //assigns address of arr_mtx[ix] as the right fork mutex
	{
		p->arr_ph[ix].rf_mtx = &p->arr_mtx[0]; //for the last ph right fork is the same as left fork for the first ph
		p->arr_ph[ix].lf_f = &p->arr_ff[0];
	}
	else
	{
		p->arr_ph[ix].rf_mtx = &p->arr_mtx[ix + 1];
		p->arr_ph[ix].lf_f = &p->arr_ff[ix + 1];
	}
	p->arr_ph[ix].p_mtx = &p->prnt_mtx; //set the address of prnt_mtx to p_mtx pointer of each philosopher
	p->arr_ph[ix].t_lst_ml; //sets time of last meal as equal to time of start
	p->arr_ph[ix].have_eatn = 0;
}

void	arr_ph_init(t_prime *p)
{
	int		ix; //ph index

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
		arr_mtx_init(p);
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