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

int	is_dead(t_prime *p)
{
	int	i;

	i = 0;
	while (i < p->n_ph)
	{
		if ((int)(current_time() - p->arr_ph[i].t_lst_ml) > p->t2d)
		{
			p->arr_ph[i].alive = 0;
			prnt_sts(&p->arr_ph[i], "died of hunger");
			kill_ph(p);
			return (1);
		}
		i++;
	}
	return (0);
}

void	monitor(t_prime *p)
{
	while (1)
	{
		wait_for(1000);
		if (is_dead(p) == 1)
			break ;
	}
	return ;
}