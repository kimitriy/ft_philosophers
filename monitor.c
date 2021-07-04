#include "ft_philosophers.h"

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
		p->arr_ph[i].age = current_time() - p->arr_ph[i].t_lst_ml;
		if (p->arr_ph[i].age >= p->t2d)
		{
			p->arr_ph[i].alive = 0;
			prnt_sts(&p->arr_ph[i], "died of hunger");
			kill_ph(p);
			break ;
		}
		i++;
	}
}

void	monitor(t_prime *p)
{
	while (1)
	{
		wait_for(1000);
		is_dead(p); //!!!
	}
	return ;
}