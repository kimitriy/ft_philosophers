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
		// p->arr_frk[i].unlock = 1; //sets 1 (available or unlocked) or 0 (locked)
		i++;
	}
	if (pthread_mutex_init(&p->prnt_mtx, NULL)) //initializes mutex that is using while printing phi status in order to none of the philosophers change its status during this printing
		err_message("Mutex was not initialised");
}

// void	mntr_init(t_prime *p) //we need to call this func before philosophers initialization
// {
// 	int	i;

// 	p->mntr.h = 1; //
// 	// p->mntr.m = 5; //
// 	p->mntr.l = 0; //sets value of different levels of priority in milisecs
// 	// p->mntr.ch_pr_f = 0; //sets initial value of change_priority_flag as 0 (none of the phi's priorities needs to be reestimated)
// 	// p->mntr.meals2moment = 0;
// 	// p->mntr.pr = (int *)ft_calloc(p->n_ph, sizeof(int)); //allocates memory for an array of priority values
// 	p->mntr.arr_has_etn = (int *)ft_calloc(p->n_ph, sizeof(int)); //allocates memory for an array of number of meals each phi has ate to the moment
// 	i = 0;
// 	while (i < p->n_ph) //according to the number of phi
// 	{
// 		// p->mntr.pr[i] = p->mntr.h; //sets the highest priority level to each phi
// 		p->mntr.arr_has_etn[i] = 0;
// 		i++;
// 	}
// }

void	ph_init(t_prime *p, int ix)
{
	p->arr_ph[ix].indx = ix;
	p->arr_ph[ix].alive = 1;
	// p->arr_ph[ix].pr = &p->mntr.pr[ix]; //points to pr array in t_mntr struct
	// p->arr_ph[ix].h = &p->mntr.h;
	// p->arr_ph[ix].m = &p->mntr.m;
	// p->arr_ph[ix].l = &p->mntr.l;
	// p->arr_ph[ix].has_eatn = &p->mntr.arr_has_etn[ix];
	p->arr_ph[ix].has_eatn = 0;
	// p->arr_ph[ix].pr = p->mntr.h; //sets the highest priority level to each phi
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
		// mntr_init(p);
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