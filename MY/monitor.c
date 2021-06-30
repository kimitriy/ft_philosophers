#include "ft_philosophers.h"

void	change_priority(t_prime *p)
{
	int	ix;

	if (p->mntr.ch_pr_f == 1)
	{
		ix = 0;
		while (ix < p->n_ph)
		{
			if (p->n_ph % 2 == 0) //if even
			{
				if (*p->arr_ph[ix].pr == p->mntr.h)
					*p->arr_ph[ix].pr = p->mntr.l;
				if (*p->arr_ph[ix].pr == p->mntr.l)
					*p->arr_ph[ix].pr = p->mntr.h;
			}
			else if (p->n_ph % 2 != 0) //if odd
			{
				if (*p->arr_ph[ix].pr == p->mntr.h)
					*p->arr_ph[ix].pr = p->mntr.l;
				if (*p->arr_ph[ix].pr == p->mntr.m)
					*p->arr_ph[ix].pr = p->mntr.h;
				if (*p->arr_ph[ix].pr == p->mntr.l)
					*p->arr_ph[ix].pr = p->mntr.m;
			}
			ix++;
		}
	}
}

void	priority_node(t_prime *p)
{
	int	i;

	i = 0;
	while (i < p->n_ph)
	{
		if (p->arr_ph[i].have_eatn > p->mntr.n_mls_ate[i])
		{
			p->mntr.ch_pr_f = 1;
			p->mntr.n_mls_ate[i] = p->arr_ph[i].have_eatn;
		}
		i++;
	}
	change_priority(p);
}

void	kill_ph(t_prime *p)
{
	int	i;
	
	i = 0;
	while (i < p->n_ph)
	{
		pthread_detach(p->ph_thread[i]);
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
			prnt_sts(&p->arr_ph[i], "died of hunger");
			kill_ph(p);
			break ;
		}
		i++;
	}
	exit (0);
}

void	monitor(t_prime *p)
{
	while (1)
	{
		priority_node(p);
		is_dead(p);
	}
}
