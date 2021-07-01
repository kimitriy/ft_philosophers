#include "ft_philosophers.h"

void	change_priority(t_prime *p)
{
	pthread_mutex_t	ch_p;
	int				ix;

	ix = 0;
	while (ix < p->n_ph)
	{
		if (p->n_ph % 2 == 0) //if even
		{
			pthread_mutex_lock(&ch_p);
			if (*p->arr_ph[ix].pr == p->mntr.m && p->arr_ph[ix].has_eatn < p->mntr.meals2moment)
				*p->arr_ph[ix].pr = p->mntr.h;
			pthread_mutex_unlock(&ch_p);
		}
		else //if odd
		{
			pthread_mutex_lock(&ch_p);
			if (*p->arr_ph[ix].pr == p->mntr.m)
				*p->arr_ph[ix].pr = p->mntr.h;
			if (*p->arr_ph[ix].pr == p->mntr.l && p->arr_ph[ix].has_eatn < p->mntr.meals2moment)
				*p->arr_ph[ix].pr = p->mntr.m;
			pthread_mutex_unlock(&ch_p);
		}
		ix++;
	}
	p->mntr.ch_pr_f = 0;
}

void	priority_node(t_prime *p)
{
	int	i;

	i = 0;
	while (i < p->n_ph)
	{
		if (p->arr_ph[i].has_eatn > p->mntr.n_mls_ate[i])
		{
			p->mntr.ch_pr_f = 1; //sets change priority flag equal 1
			p->mntr.n_mls_ate[i] = p->arr_ph[i].has_eatn;
			if (p->mntr.n_mls_ate[i] > p->mntr.meals2moment)
				p->mntr.meals2moment = p->mntr.n_mls_ate[i];
			if (p->n_ph % 2 == 0)
				*p->arr_ph[i].pr = p->mntr.m;
			else
				*p->arr_ph[i].pr = p->mntr.l;
		}
		i++;
	}
	if (p->mntr.ch_pr_f == 1)
		change_priority(p);
}

void	kill_ph(t_prime *p)
{
	int	i;
	
	i = 0;
	while (i < p->n_ph)
	{
		pthread_detach(p->ph_ptid[i]);
		i++;
	}
}

void	is_dead(t_prime *p)
{
	int	i;

	i = 0;
	while (i < p->n_ph)
	{
		if (p->arr_ph[i].alive == 0)
		{
			// write(1, "mmm\n", 4);
			prnt_sts(&p->arr_ph[i], "died of hunger");
			kill_ph(p);
			exit (0);
			// break ;
		}
		i++;
	}
}

void	monitor(t_prime *p)
{
	// write(1, "monitor is launched\n", 20);
	p->mntr.t_strt = current_time();
	while (1)
	{
		priority_node(p);
		is_dead(p); //!!!
	}
}